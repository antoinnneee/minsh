#include <unistd.h>
#include <signal.h>
#include "../libft/includes/libft.h"
#include "../includes/get_next_line.h"
#include <stdlib.h>
#include "../includes/minishell.h"

void	clear_term(void)
{
	ft_putstr("\033[2J\033[1;1Hminsh:> ");
}

t_cmd	*parse_command(char *tmp)
{
	t_cmd	*cmd;
	char	*commande;

	commande = ft_strtrim(tmp);
	free(tmp);
	cmd = NULL;
	if (commande)
	{
		if (!ft_strcmp(commande, ""))
		{
			free(commande);
			return (NULL);
		}
		else
		{
			cmd = split_cmd(commande);
			if (!cmd)
			{
				ft_putstr(commande);
				ft_putendl(": command not found");
			}
			return (cmd);
		}
	}
	else
		return (NULL);
}

int main(void)
{
	char	**buf;
	t_msh	*msh;
	t_cmd	*cmd;

	clear_term();
	msh = copy_env();
	set_add_msh((u64)msh, 1);
	msh->path = copy_path(msh->env);
	buf = (char**)ft_memalloc(sizeof(char*));
	setup_catch();
	fb(&buf, 0);
	while (get_next_line(0, buf))
	{
		if (*buf)
		{
			if ((cmd = parse_command(*buf)))
			{
				print_detail_cmd(cmd);
				exec_cmd(&cmd, &msh, NULL);
			}
		}
		free_cmd(cmd);
		ft_putstr("minsh:> ");
	}
	return (0);
}

static void	sig_handler(int signo)
{
	if (signo == SIGINT)
	{
		ft_putendl("ctrl+c protection");
		run_exit(NULL, (t_msh*)set_add_msh(0, 0));
	}
}

u64	set_add_msh(u64 ptr, int state)
{
	static u64	data = 0;

	if (data == 0)
	{
		data = ptr;
	}
	else if (state == 1)
	{
		data = ptr;
	}
	else
		return (data);
	return (0);
}

void setup_catch(void)
{
	if (signal(SIGINT, sig_handler) == SIG_ERR)
	{
		ft_putendl("SIGNAL CATCH ERROR");
	}

}
