/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abureau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 11:30:15 by abureau           #+#    #+#             */
/*   Updated: 2016/11/21 15:32:23 by abureau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include <unistd.h>
#include "../libft/includes/libft.h"

void	check_env(t_cmd **cmd, t_msh *msh)
{
	int		i;
	char	**str;

	i = -1;
	if (*cmd)
		if ((*cmd)->param)
		{
			while ((*cmd)->param[++i])
				if ((*cmd)->param[i][0] == '$')
				{
					str = get_env(&(*cmd)->param[i][1], msh);
					if (str)
					{
						free((*cmd)->param[i]);
						(*cmd)->param[i] = ft_strdup(ft_strchr(*str, '=') + 1);
					}
				}
				else if ((*cmd)->param[i][0] == '\\')
				{
					free((*cmd)->param[i]);
					(*cmd)->param[i] = ft_strsub(
							(*cmd)->param[i], 1, ft_strlen((*cmd)->param[i]));
				}
		}
}
