/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abureau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/20 13:49:33 by abureau           #+#    #+#             */
/*   Updated: 2016/11/20 13:58:48 by abureau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include "../libft/includes/libft.h"

u64			set_add_path(u64 ptr, int state)
{
	static u64	data = 0;

	if (state == 1)
	{
		data = ptr;
	}
	else
		return (data);
	return (0);
}

u64			set_add_msh(u64 ptr, int state)
{
	static u64	data = 0;

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
