/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abureau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/14 15:40:53 by abureau           #+#    #+#             */
/*   Updated: 2016/04/22 16:08:40 by abureau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"
#include "../libft/includes/libft.h"
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>

static int			parsing(char *tmpbuff, char **line, int funcchose)
{
	int	lenton;

	lenton = 0;
	if (tmpbuff)
		while (tmpbuff[lenton] != '\n' && tmpbuff[lenton] != '\0')
			lenton++;
	if (funcchose)
		return (lenton);
	else
	{
	*line = ft_strnew(lenton);
	ft_strncpy(*line, tmpbuff, lenton);
	ft_strcpy(tmpbuff, &tmpbuff[lenton + 1]);
	return (1);
	}
}

static void			mallocarray(char **buff, int *ret)
{
	char		*tmpbuff;

	*ret = -42;
	tmpbuff = (char*)malloc(sizeof(char) * BUFF_SIZE);
	*buff = tmpbuff;
	if (!tmpbuff)
		*ret = -1;
}

static char			*superjoin(char *tmpbuff, char *readbuff)
{
	char	*res;
	int		i;

	if (tmpbuff)
	{
		i = ft_strlen(tmpbuff) + BUFF_SIZE;
	}
	else
	{
		i = BUFF_SIZE + 1;
	}
	res = ft_strnew(i);
	if (!res)
		return (NULL);
	if (tmpbuff)
		res = ft_strcat(res, tmpbuff);
	if (readbuff)
		res = ft_strcat(res, readbuff);
	if (tmpbuff)
		ft_strdel(&tmpbuff);
	return (res);
}

int					get_next_line(int const fd, char **line)
{
	char		buf[BUFF_SIZE + 1];
	int			retout[2];
	static char	*tmpb = NULL;

	(!tmpb) ? mallocarray(&tmpb, &retout[0]) : (retout[0] = -42);
	if (fd < 0 || retout[0] == -1 || !line)
		return (-1);
	if (ft_strlen(&tmpb[parsing(tmpb, line, 1)]) == 0)
	{
		if ((retout[0] = read(fd, buf, BUFF_SIZE)) < 0)
			return (-1);
		buf[retout[0]] = '\0';
		tmpb = superjoin(tmpb, buf);
		retout[1] = 2;
	}
	else
		retout[1] = parsing(tmpb, line, 0);
	if (retout[0] == 0 && (ft_strlen(&tmpb[parsing(tmpb, line, 1)]) == 0))
	{
		retout[1] = (ft_strlen(tmpb) > 0) ? 1 : 0;
		parsing(tmpb, line, 0);
		ft_strdel(&tmpb);
		ft_strdel(line);
	}
	return ((retout[1] == 2) ? get_next_line(fd, line) : retout[1]);
}
