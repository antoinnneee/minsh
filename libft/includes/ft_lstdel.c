/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abureau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 14:56:00 by abureau           #+#    #+#             */
/*   Updated: 2015/12/14 14:34:59 by abureau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void*, size_t))
{
	t_list	*tmp;
	t_list	*nextl;

	if (alst && del && *alst)
	{
		tmp = *alst;
		while (tmp)
		{
			nextl = tmp->next;
			ft_lstdelone(&tmp, del);
			tmp = nextl;
		}
		*alst = NULL;
	}
}
