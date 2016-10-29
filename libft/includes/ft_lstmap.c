/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abureau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 15:49:17 by abureau           #+#    #+#             */
/*   Updated: 2015/12/04 16:24:26 by abureau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_lstpushback(t_list **begin_list, t_list *new)
{
	t_list	*tmp;

	if (begin_list)
	{
		tmp = *begin_list;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*tmp;
	t_list	*newlst;
	t_list	*new;

	newlst = NULL;
	if (lst && f)
	{
		tmp = lst;
		newlst = ft_lstnew(f(tmp)->content, f(tmp)->content_size);
		if (!newlst)
			return (NULL);
		tmp = tmp->next;
		while (tmp)
		{
			new = ft_lstnew(f(tmp)->content, f(tmp)->content_size);
			if (!new)
				return (NULL);
			ft_lstpushback(&newlst, new);
			tmp = tmp->next;
		}
	}
	return (newlst);
}
