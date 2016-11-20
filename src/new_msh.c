/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_msh.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abureau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 12:00:40 by abureau           #+#    #+#             */
/*   Updated: 2016/11/20 14:48:45 by abureau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include "../libft/includes/libft.h"

t_msh	*new_msh(void)
{
	t_msh	*tmp;

	tmp = NULL;
	tmp = (t_msh*)ft_memalloc(sizeof(t_msh));
	if (!tmp)
		return (NULL);
	tmp->env = NULL;
	tmp->env = (char**)ft_memalloc(sizeof(char*));
	return (tmp);
}
