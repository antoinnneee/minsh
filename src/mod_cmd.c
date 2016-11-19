/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mod_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abureau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 15:59:25 by abureau           #+#    #+#             */
/*   Updated: 2016/11/19 18:52:19 by abureau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include "../libft/includes/libft.h"

static void			alloc_loop(int *i, int *j, t_cmd **ncmd, t_cmd **cmd)
{
	int		k;

	k = 0;
	while (*j - *i > 0)
	{
		(*ncmd)->option[k] = ft_strdup((*cmd)->param[*i]);
		k++;
		*i = *i + 1;
	}
}

static void			alloc_loop_p(int *i, int *j, t_cmd **ncmd, t_cmd **cmd)
{
	int		k;

	k = 0;
	while (*j - *i > 0)
	{
		(*ncmd)->param[k] = ft_strdup((*cmd)->param[*i]);
		k++;
		*i = *i + 1;
	}
}

t_cmd				*mod_cmd(t_cmd **cmd, int i)
{
	t_cmd	*ncmd;
	int		j;

	ncmd = (t_cmd*)ft_memalloc(sizeof(t_cmd));
	ncmd->prog = ft_strdup((*cmd)->param[i]);
	i++;
	j = i;
	if ((*cmd)->param[i])
		while ((*cmd)->param[j] && isbegin("-", (*cmd)->param[j]))
			j++;
	else
	{
		if (*cmd)
			free_cmd(*cmd);
		return (ncmd);
	}
	ncmd->option = (char **)ft_memalloc(sizeof(char*) * (j - i + 1));
	alloc_loop(&i, &j, &ncmd, cmd);
	if ((*cmd)->param[i])
		while ((*cmd)->param[j])
			j++;
	ncmd->param = (char **)ft_memalloc(sizeof(char*) * (j - i + 1));
	alloc_loop_p(&i, &j, &ncmd, cmd);
	free_cmd(*cmd);
	return (ncmd);
}
