/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abureau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/20 11:47:18 by abureau           #+#    #+#             */
/*   Updated: 2016/11/20 14:29:48 by abureau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include "../libft/includes/libft.h"
#include "../includes/get_next_line.h"
#include <stdlib.h>
#include "../includes/minishell.h"

void		clear_term(void)
{
	ft_putstr("\033[2J\033[1;1Hminsh:> ");
}

t_cmd		*parse_command(char *tmp)
{
	t_cmd	*cmd;
	char	*commande;

	commande = ft_strtrim(tmp);
	free(tmp);
	cmd = NULL;
	if (commande)
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
	else
		return (NULL);
}

int			main(int argc, char **argv, char **environ)
{
	char	**buf;
	t_msh	*msh;
	t_cmd	*cmd;

	clear_term();
	msh = copy_env(environ);
	set_add_msh((t_u64)msh, 1);
	set_add_path((t_u64)copy_path(msh->env), 1);
	buf = (char**)ft_memalloc(sizeof(char*));
	setup_catch();
	fb(&buf, 0);
	while (get_next_line(0, buf))
	{
		if (*buf)
		{
			if ((cmd = parse_command(*buf)))
			{
				exec_cmd(&cmd, &msh, NULL);
			}
		}
		free_cmd(cmd);
		ft_putstr("minsh:> ");
	}
	free_path();
	return (0);
}

static void	sig_handler(int signo)
{
	if (signo == SIGINT)
	{
		ft_putendl("ctrl+c protection");
		run_exit(NULL, (t_msh*)set_add_msh(0, 0));
	}
}

void		setup_catch(void)
{
	if (signal(SIGINT, sig_handler) == SIG_ERR)
	{
		ft_putendl("SIGNAL CATCH ERROR");
	}
}
