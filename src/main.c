#include <unistd.h>
#include "../libft/includes/libft.h"
#include "../includes/get_next_line.h"
#include <stdlib.h>
#include "../includes/minishell.h"

extern char	**environ;

void	clear_term(void)
{
	ft_putstr("\033[2J\033[1;1Hminsh:> ");
}

t_cmd	*split_cmd(char *commande)
{
	t_cmd	*cmd;
	int	i;
	int	nb;
	char	*tmp;

	i = 0;
	nb = 0;
	cmd = (t_cmd*)ft_memalloc(sizeof(t_cmd));
	if (!cmd)
	{
		ft_putendl("malloc error");
		exit(0);
	}
	while (commande[i])
	{
		if (commande[i] == ' ')
		{
			cmd->prog = ft_strsub(commande, 0, i);
			tmp = get_option(&commande[i], &nb);
			if (tmp)
			{
				cmd->option = ft_strsplit(tmp, ':');
				free(tmp);
			}
			i = i + nb;
			if (commande[i])
				cmd->param = ft_strsplit(&commande[i], ' ');
			free(commande);
			return (cmd);
		}
		i++;
	}
	cmd->prog = ft_strdup(commande);
	cmd->param = NULL;
	free(commande);
	return (cmd);
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

t_msh	*copy_env(void)
{
	int	i;
	int	j;
	t_msh	*msh;

	i = 0;
	j = 0;
	while (environ[i])
		i++;
	if (i == 0)
		return (NULL);
	msh = (t_msh*)ft_memalloc(sizeof(t_msh));
	ft_bzero(msh, sizeof(t_msh));
	msh->enb = i;
	msh->env = (char**)ft_memalloc(sizeof(char*) * (i + 1));	
	i = 0;
	while (environ[i])
	{
		msh->env[i] = (char*)ft_memalloc(sizeof(char) * (ft_strlen(environ[i]) + 1));
		while (environ[i][j])
		{
			msh->env[i][j] = environ[i][j];
			j++;
		}
		msh->env[i][j] = 0;
		j = 0;
		i++;
	}
	msh->env[i] = NULL;
	return (msh);
}

char	**copy_path(char **env)
{
	char	**path;
	char	*tmp;

	tmp = NULL;
	if((tmp = f_getenv("PATH", env)))
	{
		path = ft_strsplit(&tmp[ft_strlen("PATH=")], ':');
		return (path);
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
	if (!msh)
	{
		ft_putendl("No env, exitting");
		exit(0);
	}
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
