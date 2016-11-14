
#include "../includes/minishell.h"
#include "../libft/includes/libft.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
void	run_exit(t_cmd *cmd, t_msh *msh)
{
	if (cmd)
		free_cmd(cmd);
	if (msh)
		free_msh(&msh);
	f(NULL, 1);
	fb(NULL, 1);
	exit(0);
}

int		ft_strlensquare(char **env)
{
	int	i;

	i = 0;
	if (env)
	{
		while (env[i])
		{
			i++;	
		}
		i++;
	}
	return (i);
}

static t_msh	*cpy_env(t_msh *msh)
{
	t_msh		*tmp;
	int		cnt;
	int		i;

	cnt = ft_strlensquare(msh->env);
	i = 0;
	tmp = (t_msh*)ft_memalloc(sizeof(t_msh));
	if(!tmp)
		return (NULL);
	tmp->env = (char**)ft_memalloc(sizeof(char*) * (cnt + 1));
	if (msh->env)
	{
		ft_putendl("dupping env");
		while (msh->env[i])
		{
			tmp->env[i] = ft_strdup(msh->env[i]);
			i++;
		}
		ft_putendl("env dup");
	}
	else
	{
		ft_putendl("no env, pls gamu");
	}
	i = 0;
	cnt = ft_strlensquare(msh->path);
	tmp->path = (char**)ft_memalloc(sizeof(char*) * (cnt + 1));
	if (msh->path)
	while (msh->path[i])
	{
		tmp->path[i] = ft_strdup(msh->path[i]);
		i++;
	}
	return (tmp);
}

void	run_env(t_cmd **cmd, t_msh **msh)
{
	int		i;
	t_msh	*tmp;
	unsigned int		opt;
	int		process;

	opt = 0;
	process = 0;
	if (!msh)
		return ;
	if (!*msh)
		return ;	
	tmp = cpy_env(*msh);
/*
	while (msh->path[i])
	{
//		ft_putendl(msh->path[i]);
		i++;
	}
*/
	i = 0;
	if ((*cmd)->option)
	{
		while ((*cmd)->option[i])
		{
			if (isbegin("-0", (*cmd)->option[i]) || isbegin("--null", (*cmd)->option[i]))
			{
				opt = opt | (1U << 0);
			}
			else if (isbegin("--unset=", (*cmd)->option[i]))
			{
				unset_env(&(*cmd)->option[i][ft_strlen("--unset=")], &tmp);
			}
			else if (isbegin("-u", (*cmd)->option[i]))
			{
				opt = opt | (1U << 1);
				process = 1;
			}
			else if (isbegin("-i", (*cmd)->option[i]))
			{
				if (tmp)
					free_msh(&tmp);
				tmp = NULL;
			}
			else if (isbegin("-v", (*cmd)->option[i]) || isbegin("--version", (*cmd)->option[i]))
			{
				print_env_v();
				if (tmp)
					free_msh(&tmp);
				return ;
			}
			else if (isbegin("-h", (*cmd)->option[i]) || isbegin("--help", (*cmd)->option[i]))
			{
				print_env_help();
				if (tmp)
					free_msh(&tmp);
				return ;
			}
			else
			{
				ft_putstr("invalid option :");
				ft_putendl((*cmd)->option[i]);
				if (tmp)
					free_msh(&tmp);
				return ;
			}
			i++;
		}
	}
	i = 0;
	if (opt & (1U << 1))
	{
//	========================================================================== //
		if ((*cmd)->param)
		{
			while (tmp->env[i])
			{
				if(beginby((*cmd)->param[0], tmp->env[i]))
					unset_env((*cmd)->param[0], &tmp);
				i++;
			}
			i = 0;
			if (opt & (1U << 0) && (*cmd)->param[1])
			{
				ft_putendl("env: cannot specify --null (-0) with command");
				ft_putendl("try 'env --help' for more informqtion.");
			}
			else if ((*cmd)->param[1])
			{
				*cmd = mod_cmd(cmd, 1);
				print_detail_cmd(*cmd);
				ft_putendl("CMD mod reussit");
				exec_cmd(cmd, msh, &tmp);
				ft_putendl("free tmp passed");
			}
			else
			{
				print_msh(tmp, opt);
			}
		}
		else
		{
			ft_putendl("env: option requires an argument '-u'");
			if (tmp)
				free_msh(&tmp);
			return ;
		}
//	========================================================================== //	
	}
	else
	{
		if (!tmp)
		{
			tmp = (t_msh*)ft_memalloc(sizeof(t_msh));
			tmp->env = (char**)ft_memalloc(sizeof(char*));
			tmp->env = NULL;
			tmp->path = (char**)ft_memalloc(sizeof(char*));
			tmp->path = NULL;
		}
		if ((*cmd)->param)
		{
			i = 0;
			while ((*cmd)->param[i] && ft_strchr((*cmd)->param[i], '='))
			{
				char	*value = ft_strdup(ft_strchr((*cmd)->param[i], '='));
				char	*mpath = ft_strsub((*cmd)->param[i], 0, ft_strlen((*cmd)->param[i]) - ft_strlen(value) + 1);
				ft_putendl(value);
				set_env(mpath, &value[1], &tmp);
				i++;
				if (value)
					free(value);
				if (mpath)
					free(mpath);
			}
			if ((*cmd)->param[i])
			{
				*cmd = mod_cmd(cmd, i);	
				print_detail_cmd(*cmd);
				ft_putendl("CMD mod reussit");
				exec_cmd(cmd, msh, &tmp);
				free_msh(&tmp);
				return ;
			}
			else
				print_msh(tmp, opt);

		}
		else if (!(*cmd)->param)
			print_msh(tmp, opt);
		free_msh(&tmp);
	}
}

/*
void	run_env(t_cmd *cmd, t_msh *msh)
{
	int		i;
	int		j;
	int		process;
	int		opt;
	t_msh	*tmp;

	i = 0;
	opt = 0;
	process = 0;
	tmp = cpy_env(msh);
	while (tmp->env[i])
	{
		ft_putendl(tmp->env[i]);
		i++;
	}
	i = 0;
	if (cmd->param)
	{
	}
	else if (opt & (1U << 1))
	{
		ft_putendl("env: option requires an argument --'u'");	
	}
	else
	{
		cmd = mod_cmd(&cmd, 0);
		exec_cmd(cmd, &msh, &tmp);
		print_detail_cmd(cmd);
		ft_putendl("CMD mod reussit");
		free_msh(tmp);

	}
	i = 0;
	while (tmp->env[i])
	{
		if (opt & (1U << 0))
			ft_putstr(tmp->env[i]);
		else
			ft_putendl(tmp->env[i]);
		i++;
	}
}
*/

t_cmd	*mod_cmd(t_cmd	**cmd, int i)
{
	t_cmd	*ncmd;
	int		j;
	int		k;

	ncmd = (t_cmd*)ft_memalloc(sizeof(t_cmd));
	ncmd->prog = ft_strdup((*cmd)->param[i]);
	i++;
	j = i;
 	k = 0;
	if ((*cmd)->param[i])
	{
		while ((*cmd)->param[j] && isbegin("-", (*cmd)->param[j]))
		{
			j++;
		}
	}
	else
	{
		if (*cmd)
			free_cmd(*cmd);
		return (ncmd);
	}
	ncmd->option = (char **)ft_memalloc(sizeof(char*) * (j - i + 1));
	while (j - i > 0)
	{
//	=============================================explore here=================
		ncmd->option[k] = ft_strdup((*cmd)->param[i]);
		k++;
		i++;
	}
	k = 0;	
	if ((*cmd)->param[i])
		while ((*cmd)->param[j])
		{
			j++;
		}
	ncmd->param = (char **)ft_memalloc(sizeof(char*) * (j - i + 1));
	while (j - i > 0)
	{
		ncmd->param[k] = ft_strdup((*cmd)->param[i]);
		k++;
		i++;
	}
	free_cmd(*cmd);
	return (ncmd);
	
}

void	run_cd(t_cmd *cmd, t_msh *msh)
{
	char	**pwd;
	char	**old;
	char	*tmp;

	tmp = (char*)ft_memalloc((sizeof(char) * 256));
	tmp = getcwd(tmp, 256);
	old = get_env("OLDPWD=", msh);
	free(*old);
	*old = ft_memalloc((sizeof(char) * 256));
	*old = ft_strcpy(*old, "OLDPWD=");
	*old = ft_strcat(*old, tmp);
	if (cmd->param && cmd->param[0][0] == '~')
		chdir(ft_strchr(*get_env("HOME=", msh), '=') + 1);	
	else if (cmd->param)
	{
		if (chdir(cmd->param[0]) == -1)
		{
			ft_putstr("cd : ");
			ft_putstr(cmd->param[0]);
			ft_putstr(" : no such file or directory\n");
		}
	}
	else
		chdir(ft_strchr(*get_env("HOME=", msh), '=') + 1);
	pwd = get_env("PWD=", msh);
	tmp = getcwd(tmp, 256);
	free(*pwd);
	*pwd = ft_memalloc((sizeof(char) * 256));
	*pwd = ft_strcpy(*pwd, "PWD=");
	*pwd = ft_strcat(*pwd, tmp);
	free(tmp);
}

void	run_unset(t_cmd *cmd, t_msh **msh)
{
	int	i;

	i = 0;
	if (cmd->param)
	{
		while ((*msh)->env[i])
		{
			if(beginby(cmd->param[0], (*msh)->env[i]))
			{
				unset_env(cmd->param[0], msh);
				return ;
			}
				i++;
		}
	}	
}

void	run_setenv(t_cmd *cmd, t_msh **msh)
{
	char	**splitenv;
	int		i;

	i = 0;
	if (cmd->param)
	{
		splitenv = (char**)ft_memalloc(sizeof(char*) * 3);
		if (splitenv)
		{
			if (ft_strchr(cmd->param[0], '='))
			{
				splitenv[1] = ft_strdup(ft_strchr(cmd->param[0], '=') + 1);
				splitenv[0] = ft_strsub(cmd->param[0], 0, ft_strlen(cmd->param[0]) - ft_strlen(splitenv[1]));
				if (splitenv[0])
					set_env(splitenv[0], splitenv[1], msh);
				while (splitenv[i])
				{
					free(splitenv[i]);
					i++;
				}
				free(splitenv);
			}
			else
			{
				free(splitenv);
				return ;
			}
		}
	}
}


