/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   beg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abureau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 17:04:07 by abureau           #+#    #+#             */
/*   Updated: 2016/11/21 15:08:04 by abureau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "../includes/minishell.h"

void		inimain(t_msh **msh)
{
	init_pwd(msh);
	set_add_msh((t_u64)*msh, 1);
	set_add_path((t_u64)copy_path((*msh)->env), 1);
}

int			isbegin(const char *str, char *big)
{
	if (ft_strncmp(str, big, ft_strlen(str)))
		return (0);
	else
		return (1);
	if (!str && !big)
		return (1);
	else if (!big)
		return (1);
	else if (!str)
		return (0);
	else if (*str != *big)
		return (0);
	else
		return (1);
}

int			beginby(const char *str, char *env)
{
	while (*str && *env && *str == *env)
	{
		env++;
		str++;
	}
	if (!str)
		return (0);
	else if (*env == '=')
		return (1);
	else
		return (0);
}
