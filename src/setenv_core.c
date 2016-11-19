/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setenv_core.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abureau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 14:47:41 by abureau           #+#    #+#             */
/*   Updated: 2016/11/19 19:44:11 by abureau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include "../libft/includes/libft.h"

void	core_setenv(t_cmd **cmd, t_msh ***pmsh, int i)
{
	i = 42;
	env_param(cmd, pmsh, *pmsh, &i);
}
