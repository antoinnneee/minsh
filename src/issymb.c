/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   issymb.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abureau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/20 13:44:53 by abureau           #+#    #+#             */
/*   Updated: 2016/11/21 12:09:33 by abureau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"

int		issymb(const char c)
{
	if (ft_isalnum(c))
		return (1);
	if (c > 34 && c < 47)
		return (1);
	if (c == 95)
		return (1);
	if (c == '/')
		return (1);
	if (c == '\\')
		return (1);
	if (c == '\'')
		return (1);
	return (0);
}
