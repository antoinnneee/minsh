
#include "../includes/minishell.h"
#include "../libft/includes/libft.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void	free_tab(char **tab)
{
	int i;

	i = 0;
	if (tab)
	{
		while (tab[i])
		{
			free(tab[i]);
			tab[i] = NULL;
			i++;
		}
		free(tab);
	}
}

void	free_cmd(t_cmd *cmd)
{
	int	i;

	i = 0;
	if (cmd)
	{
		if (cmd->prog)
			free(cmd->prog);
		if (cmd->param)
		{
			while (cmd->param[i])
			{
				free(cmd->param[i]);
				i++;
			}
			i = 0;
			free(cmd->param);
		}
		if (cmd->option)
		{
			while (cmd->option[i])
			{
				free(cmd->option[i]);
				i++;
			}
			i = 0;
			free(cmd->option);
		}
		free(cmd);
	}
}

void	free_msh(t_msh *msh)
{
	int	i;

	i = 0;
	if (msh)
	{
		if (msh->env)
		{
			while (msh->env[i])
			{
				free(msh->env[i]);
				i++;
			}
			free(msh->env);
		}
		i = 0;
		if (msh->path)
		{
			while (msh->path[i])
			{
				free(msh->path[i]);
				i++;
			}
			free(msh->path);
		}
		free(msh);
	}
}

void	free_split(char ***split)
{
	int	i;

	i = 0;
	if (*split)
	{
		while (*split[i])
		{
			free(*split[i]);
			*split[i] = NULL;
			i++;
		}
		free(*split);
	}
}


