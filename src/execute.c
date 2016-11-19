/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abureau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 18:50:45 by abureau           #+#    #+#             */
/*   Updated: 2016/11/19 22:22:25 by abureau          ###   ########.fr       */
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

static pid_t		creat_process(void)
{
	pid_t pid;

	while ((pid = fork()) == -1)
	{
		;
	}
	return (pid);
}

static int			cnt_p(t_cmd *cmd)
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
/*
static char			**inorga(int *ij, char *pathexe, int *nbparam, t_cmd *cmd)
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
*/
static char			**organize(t_cmd *cmd, char *pathexe)
{
	char	**argv;
	int		nbparam;
	int		i;
	int		j;

	ft_inittwovar(&i, &j);
	nbparam = cnt_p(cmd) + 1;
	argv = (char**)ft_memalloc(sizeof(char*) * (nbparam + 1));
	argv[i] = ft_strdup(pathexe);
	i++;
	j = 0;
	ft_putendl("organize init");
	while (i < nbparam)
	{
		ft_putendl("loop_option");
		if (cmd->option[j])
		{
			ft_putendl("start elem loop dup option");
			argv[i] = ft_strdup(cmd->option[j]);
			ft_putendl("ending elem loop dup option");
		}
			else
		{
			j = 0;
			while (i < nbparam)
			{
				ft_putendl("dupe loop");
				argv[i] = ft_strdup(cmd->param[j]);
				ft_inctwovar(&i, &j);
			}
				ft_putendl("dupe loop end");
		}
		i++;
		j++;
	}
	argv[nbparam] = NULL;
	return (argv);
}

void			printenv(char **env)
{
	int i;

	i = 0;
	ft_putendl("============== PRINT ENV =============");
	while (env[i])
	{
		ft_putendl(env[i]);
		i++;
	}
}

int				exe_search(char *scat, t_cmd *cmd, t_msh **msh, t_msh **nmsh)
{
	char		**env;
	struct stat	st;
	pid_t		pid;

	env = NULL;
	if (!access(scat, X_OK))
	{
		ft_putendl("scat access");
		lstat(scat, &st);
		ft_putendl("organize will begin");
		env = organize(cmd, scat);
		ft_putendl("organize end");
		pid = creat_process();
		if (pid == 0)
		{
			if (nmsh && env)
			{
				ft_putendl("pidok");
				execve(scat, env, (*nmsh)->env);
			}
			else if (env)
				execve(scat, env, (*msh)->env);
			exit(0);
		}
		if (pid > 0)
		{
			waitpid(0, NULL, 0);
		}
		if (env)
			free_tab(env);
		if ((st.st_mode & S_IFMT) == S_IFDIR)
			return (2);
		return (1);
	}
	ft_putendl("scat no access");
	return (0);
}

void			execute(char *name, t_cmd *cmd, t_msh **msh, t_msh **nmsh)
{
	int		i;
	int		state;
	char	*scat;

	state = 0;
	i = 0;
	if (cmd->prog[0] == '.')
		state = exe_search(name, cmd, msh, nmsh);
	else if ((*msh)->path)
	{
		while ((*msh)->path[i] && state == 0)
		{
			scat = (char*)ft_memalloc(sizeof(char) * (ft_strlen((*msh)->path[i]) + ft_strlen(name) + 2));
			scat = ft_strcat(scat, (*msh)->path[i]);
			scat = ft_strcat(scat, "/");
			scat = ft_strcat(scat, name);
			ft_putendl(scat);
			state = exe_search(scat, cmd, msh, nmsh);
			if (scat)
			{
				ft_putendl("scat free ?");
				ft_strdel(&scat);
					ft_putendl("scat is free");
			}
			i++;
		}
	}
	if (state == 0)
	{
		if (cmd->prog[0] == '.')
		{
			ft_putstr("minsh: ");
			ft_putstr(name);
			if (access(name, F_OK))
				ft_putendl(": No such file or directory");
			else
				ft_putendl(": Permission denied");
		}
		else
		{
			ft_putstr(name);
			ft_putendl(": command not found");
		}
	}
	else if (state == 2)
	{
		ft_putstr("minsh: ");
		ft_putstr(name);
		ft_putendl(": is a Directory");
	}
	i = 0;
}
