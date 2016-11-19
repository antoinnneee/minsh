#include "../includes/minishell.h"
#include "../libft/includes/libft.h"
#include <unistd.h>

char		*f_getenv(const char *str, char **env)
{
	int	i;

	i = 0;
	while (env[i])
	{
		if (beginby(str, env[i]))
			return (env[i]);
		i++;
	}
	return (NULL);		
}

char		**get_env(char *name, t_msh *msh)
{
	int	i;

	i = 0;
	if (msh->env)
		while (msh->env[i])
		{
			if (!ft_strncmp(msh->env[i], name, ft_strlen(name)))
			{
				return (&msh->env[i]);
			}
			i++;
		}
	return(NULL);
}

void		unset_env(char *name, t_msh **msh)
{
	int		i;
	int		j;
	char	**tmpenv;

	ft_inittwovar(&i, &j);
	tmpenv = (char**)ft_memalloc(sizeof(char*) * (ft_strlensquare((*msh)->env, NULL)));
	while ((*msh)->env[i])
	{
		if(beginby(name, (*msh)->env[i]))
			i++;
		else
		{
			tmpenv[j] = ft_strdup((*msh)->env[i]);
			ft_inctwovar(&i, &j);
		}
	}
	i = 0;
	while ((*msh)->env[i])
	{
		free((*msh)->env[i]);
		i++;
	}
	free((*msh)->env);
	(*msh)->env = tmpenv;
}

static int	cnt_env(t_msh *msh)
{
	int	i;

	i = 0;
	if (msh->env)
		while (msh->env[i])
		{
			i++;
		}
	return (i);
}

void		add_env(char *name, char *value, t_msh **msh)
{
	int	i;
	char	**tmpenv;

	i = 0;
	tmpenv = (char**)ft_memalloc(sizeof(char*) * (cnt_env(*msh) + 2));
	if ((*msh)->env)
	while ((*msh)->env[i])
	{
		tmpenv[i] = ft_strdup((*msh)->env[i]);
		i++;
	}
	tmpenv[i] = (char*)ft_memalloc((sizeof(char) * (ft_strlen(name) + ft_strlen(value) + 1)));
	tmpenv[i] = ft_strcpy(tmpenv[i], name);
	tmpenv[i] = ft_strcat(tmpenv[i], value);
	tmpenv[i + 1] = NULL;
	i = 0;
	if ((*msh)->env)
	{
		while ((*msh)->env[i])
		{
			free((*msh)->env[i]);
			i++;
		}
	free((*msh)->env);
	}
	(*msh)->env = tmpenv;
}

void		set_env(char *name, char *value, t_msh **msh)
{
	char	**old;

	old = get_env(name, *msh);
	if (old)
	{
		free(*old);
		*old = (char*)ft_memalloc((sizeof(char)
					* (ft_strlen(name) + ft_strlen(value) + 1)));
		*old = ft_strcpy(*old, name);
		*old = ft_strcat(*old, value);
	}
	else
	{
		add_env(name, value, msh);
	}
}
