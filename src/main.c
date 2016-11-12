#include <unistd.h>
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
	msh->path = copy_path(msh->env);
	buf = (char**)ft_memalloc(sizeof(char*));
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
