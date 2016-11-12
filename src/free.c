
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
			i++;
		}
		free(tab);
		tab = NULL;
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

void	free_msh(t_msh **tmp)
{
	int		i;
	t_msh	*msh;

	if (tmp)
		msh = *tmp;
	else
		return ;
	i = 0;
	if (msh)
	{
		if (msh->env)
		{
			while (msh->env[i])
			{
				free(msh->env[i]);
				msh->env[i] = NULL;
				i++;
			}
			free(msh->env);
			msh->env = NULL;
		}
		i = 0;
		if (msh->path)
		{
			while (msh->path[i])
			{
				free(msh->path[i]);
				msh->path[i] = NULL;
				i++;
			}
			free(msh->path);
			msh->path = NULL;
		}
		free(msh);
		msh = NULL;
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


