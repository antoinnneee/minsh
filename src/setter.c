/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abureau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/20 13:49:33 by abureau           #+#    #+#             */
/*   Updated: 2016/11/20 14:30:31 by abureau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include "../libft/includes/libft.h"

t_u64			set_add_path(t_u64 ptr, int state)
{
	static t_u64	data = 0;

	if (state == 1)
	{
		data = ptr;
	}
	else
		return (data);
	return (0);
}

t_u64			set_add_msh(t_u64 ptr, int state)
{
	static t_u64	data = 0;

	if (data == 0)
	{
		data = ptr;
	}
	else if (state == 1)
	{
		data = ptr;
	}
	else
		return (data);
	return (0);
}
