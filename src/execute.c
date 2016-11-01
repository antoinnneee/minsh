#include "../includes/minishell.h"
#include "../libft/includes/libft.h"
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <dirent.h>
#include <unistd.h>
#include <fcntl.h>

static pid_t creat_process()
{
	pid_t pid;

	while ((pid = fork()) == -1)
	{
		;
	}
	return (pid);
}

static int	cnt_p(t_cmd *cmd)
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

static char	**organize(t_cmd *cmd, char *pathexe)
{
	char	**argv;
	int	nbparam;
	int	i;
	int	j;

	i = 0;
	j = 0;
	nbparam = cnt_p(cmd) + 1;
	argv = (char**)ft_memalloc(sizeof(char*) * (nbparam + 1));
	argv[i] = ft_strdup(pathexe);
	i++;
	while (i < nbparam)
	{
		if (cmd->option && cmd->option[j])
			argv[i] = ft_strdup(cmd->option[j]);
		else
		{
			j = 0;
			while (i < nbparam)
			{
				argv[i] = ft_strdup(cmd->param[j]);
				i++;
				j++;
			}
		}	
		i++;
		j++;
	}
	argv[nbparam] = NULL;
	return (argv);
}

void	printenv(char **env)
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

int	exe_search(char *scat, t_cmd *cmd, t_msh **msh, t_msh **nmsh)
{
	char		**env;
	struct stat	st;
	pid_t		pid;

	env = NULL;
	if (!access(scat, X_OK))
	{
		lstat(scat, &st);
		env = organize(cmd, scat);
		printenv(env);
		pid = creat_process();	
		if (pid == 0)
		{
			if (nmsh && env)
			{
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
	return (0);
}


void	execute(char *name, t_cmd *cmd, t_msh **msh, t_msh **nmsh)
{
	int		i;
	int		state;
	char	*scat;

	state = 0;
	ft_putendl("state = 0");
	i = 0;
	if (cmd->prog[0] == '.')
		state = exe_search(name, cmd, msh, nmsh);
	else
	{
		while ((*msh)->path[i] && state == 0)
		{
			scat = (char*)ft_memalloc(sizeof(char) * (ft_strlen((*msh)->path[i]) + ft_strlen(name) + 2));
			scat = ft_strcat(scat, (*msh)->path[i]);
			scat = ft_strcat(scat, "/");
			scat = ft_strcat(scat, name);
			state = exe_search(scat, cmd, msh, nmsh);
			if (scat)
				ft_strdel(&scat);
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

