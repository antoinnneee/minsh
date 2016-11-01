#include "../libft/includes/libft.h"
#include "../includes/minishell.h"

void	print_env_v(void)
{
	ft_putstr("env (minsh builtin) 1.0\nThis is a free software:  ");
	ft_putstr("you  are free to change and redistribute it.\n");
	ft_putstr("Write by Antoine Bureau.");
}

void	print_env_help(void)
{
	ft_putstr("Usage : env [OPTION] [NAME=VALUE] [COMMAND]\n");
	ft_putstr("-i, --ignore-environment\tstart with an empty environment\n");
	ft_putstr("-0, --null\t\t\tend each output line with NUL, not newline \n");
	ft_putstr("-u, --unset=NAME\t\tremove variable from environment\n");
	ft_putstr("-h, --help\t\t\tdisplay this help and exit\n");
	ft_putstr("-v, --version\t\t\tOutput information and exit\n\n");
	ft_putstr("a mere - implies -i, if no COMMAND, print the resulting environment.\n");
}

void	print_msh(t_msh *env, unsigned int opt)
{
	int		i;

	i = 0;
	ft_putnbrnl(opt);
	while (env->env[i])
	{
		if (opt & (1U << 0))
			ft_putstr(env->env[i]);
		else
			ft_putendl(env->env[i]);
		i++;
	}
}
