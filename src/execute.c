/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abureau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 18:50:45 by abureau           #+#    #+#             */
/*   Updated: 2016/11/21 13:30:54 by abureau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include "../libft/includes/libft.h"
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <dirent.h>
#include <unistd.h>
#include <fcntl.h>

static int		cnt_p(t_cmd *cmd)
{
	int	i;
	int	cnt;

	i = 0;
	cnt = 0;
	if (cmd->option)
	{
		while (cmd->option[i])
		{
			i++;
		}
		cnt = i;
		i = 0;
	}
	if (cmd->param)
	{
		while (cmd->param[i])
		{
			i++;
		}
	}
	cnt = cnt + i;
	return (cnt);
}

static char		**inorga(int *ij, char *pathexe, int *nbparam, t_cmd *cmd)
{
	char	**argv;

	ij[0] = 0;
	ij[1] = 0;
	*nbparam = cnt_p(cmd) + 1;
	argv = (char**)ft_memalloc(sizeof(char*) * (*nbparam + 1));
	argv[ij[0]] = ft_strdup(pathexe);
	ij[0] = ij[0] + 1;
	return (argv);
}

static char		**organize(t_cmd *cmd, char *pathexe)
{
	char	**argv;
	int		nbparam;
	int		ij[2];

	argv = inorga(ij, pathexe, &nbparam, cmd);
	while (ij[0] < nbparam)
	{
		if (cmd->option && cmd->option[ij[1]])
		{
			argv[ij[0]] = ft_strdup(cmd->option[ij[1]]);
		}
		else
		{
			ij[1] = 0;
			while (ij[0] < nbparam)
			{
				argv[ij[0]] = ft_strdup(cmd->param[ij[1]]);
				ft_inctwovar(&ij[0], &ij[1]);
			}
		}
		ft_inctwovar(&ij[0], &ij[1]);
	}
	argv[nbparam] = NULL;
	return (argv);
}

int				exe_search(char *scat, t_cmd *cmd, t_msh **msh)
{
	char		**env;
	struct stat	st;
	pid_t		pid;

	env = NULL;
	if (!access(scat, X_OK))
	{
		lstat(scat, &st);
		env = organize(cmd, scat);
		pid = creat_process();
		if (pid == 0)
		{
			fork_process(scat, msh, env);
		}
		if (pid > 0)
			waitpid(0, NULL, 0);
		if (env)
			free_tab(env);
		if ((st.st_mode & S_IFMT) == S_IFDIR)
			return (2);
		return (1);
	}
	return (0);
}

void			execute(char *name, t_cmd *cmd, t_msh **msh)
{
	int		i;
	int		state;
	char	*scat;
	char	**path;

	path = (char **)set_add_path(0, 0);
	state = 0;
	i = -1;
	if (cmd->prog[0] == '.')
		state = exe_search(name, cmd, msh);
	else if (path)
		while (path[++i] && state == 0)
		{
			scat = (char*)ft_memalloc(sizeof(char) *
					(ft_strlen(path[i]) + ft_strlen(name) + 2));
			scat = ft_strcat(scat, path[i]);
			scat = ft_strcat(scat, "/");
			scat = ft_strcat(scat, name);
			state = exe_search(scat, cmd, msh);
			if (scat)
				ft_strdel(&scat);
		}
	if (state == 0)
		state = exe_search(name, cmd, msh);
	p_exec_error(name, cmd->prog, state);
}
