/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   beg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abureau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 17:04:07 by abureau           #+#    #+#             */
/*   Updated: 2016/11/14 17:04:28 by abureau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"

int	isbegin(const char *str, char *big)
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

int	beginby(const char *str, char *env)
{
	while (*str == *env)
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
