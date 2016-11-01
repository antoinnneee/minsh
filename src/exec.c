#include "../includes/minishell.h"
#include "../libft/includes/libft.h"

static int	exec_builtin(t_cmd **cmd, t_msh **msh)
{
	if (!ft_strcmp((*cmd)->prog, "echo"))
		;
	else if (!ft_strcmp((*cmd)->prog, "cd"))
		run_cd(*cmd, *msh);
	else if (!ft_strcmp((*cmd)->prog, "pwd"))
		run_pwd(*cmd, *msh);
	else if (!ft_strcmp((*cmd)->prog, "setenv"))
		run_setenv(*cmd, msh);
	else if (!ft_strcmp((*cmd)->prog, "unsetenv"))
		run_unset(*cmd, msh);
	else if (!ft_strcmp((*cmd)->prog, "env"))
		run_env(cmd, msh);
	else if (!ft_strcmp((*cmd)->prog, "exit") || !ft_strcmp((*cmd)->prog, "q"))
		run_exit(*cmd, *msh);
	else
		return (0);
	return (1);
}

void		exec_cmd(t_cmd **cmd, t_msh **msh, t_msh	**nmsh)
{
	if (!nmsh)
	{
		if (!exec_builtin(cmd, msh))
		{
			execute((*cmd)->prog, *cmd, msh, NULL);
		}
	}
	else
	{
		if (!exec_builtin(cmd, nmsh))
		{
			execute((*cmd)->prog, *cmd, msh, nmsh);
		}
	}
}

char			*get_option(char *commande, int *i)
{
	int	j;
	char	*option;
	int	ind;
	
	ind = 0;
	option = NULL;
	while (commande[ind] == ' ' && commande[ind] != '\0')
	{
		ind++;
		if (commande[ind] == '-')
		{
			j = ind;
			ind++;
			while (ft_isalnum(commande[ind]) || commande[ind] == '-' || commande[ind] == '=')
			{
				ind = ind + 1;
			}
			if (!option)
				option = ft_strsub(commande, j, ind - j);
			else
			{
				option = secure_cat(secure_cat(option, ":", 0), ft_strsub(commande, j, ind -j), 1);
			}
		}
	}
	*i = ind;
	return (option);
}

void			print_detail_cmd(t_cmd *cmd)
{
	int	i;

	i = 0;
	ft_putstr("programme : ");
	if (cmd->prog)
		ft_putstr(cmd->prog);
	ft_putstr("\nparam : ");
	if (cmd->param)
	{
		while (cmd->param[i])
		{
			ft_putendl(cmd->param[i]);
			i++;
		}
		i = 0;
	}
	ft_putstr("\noption : ");
	if (cmd->option)
	{
		while (cmd->option[i])
		{
			ft_putendl(cmd->option[i]);
			i++;
		}
	}
	else
		ft_putchar('\n');
}


