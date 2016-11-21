/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abureau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/20 13:03:18 by abureau           #+#    #+#             */
/*   Updated: 2016/11/21 14:17:22 by abureau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include "../libft/includes/libft.h"
#include <unistd.h>
#include <sys/types.h>

void		fork_process(char *scat, t_msh **msh, char **env)
{
	if (env && (*msh)->env)
		execve(scat, env, (*msh)->env);
	else if (env)
		execve(scat, env, NULL);
	else
		ft_putendl("fork commande error");
	exit(0);
}

pid_t		creat_process(void)
{
	pid_t pid;

	while ((pid = fork()) == -1)
	{
		;
	}
	return (pid);
}
