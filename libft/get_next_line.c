/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdirect <mdirect@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 15:16:45 by mdirect           #+#    #+#             */
/*   Updated: 2019/10/12 21:14:00 by mdirect          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_enter(char **ost, char **line)
{
	char	*s;
	int		i;
	char	*tmp;

	s = *ost;
	i = 0;
	while (s[i] != '\n')
		if (!(s[i++]))
			return (0);
	s[i] = '\0';
	i++;
	*line = ft_strdup(*ost);
	tmp = ft_strdup(s + i);
	free(*ost);
	*ost = ft_strdup(tmp);
	free(tmp);
	tmp = NULL;
	return (1);
}

static int	ft_read_gnl(int fd, char *s, char **ost, char **line)
{
	int		i;

	while ((i = read(fd, s, BUFF_SIZE)) > 0)
	{
		ft_bzero(s + i, BUFF_SIZE - i);
		if (*ost != NULL)
			*ost = ft_strjoinfree(*ost, s, 1);
		else
			*ost = ft_strdup(s);
		if (ft_enter(ost, line))
			break ;
	}
	return ((i > 0) ? 1 : i);
}

int			get_next_line(const int fd, char **line)
{
	static char	*ost[1024] = {NULL};
	char		*s;
	int			i;

	if ((fd < 0 || fd > 1024) || !line || read(fd, NULL, 0) < 0
		|| !(s = ft_strnew(BUFF_SIZE)))
		return (-1);
	if (ost[fd] && ost[fd][0])
		if (ft_enter(&ost[fd], line))
		{
			ft_strdel(&s);
			return (1);
		}
	i = ft_read_gnl(fd, s, &ost[fd], line);
	ft_strdel(&s);
	if (!ost[fd] || i || !ost[fd][0])
	{
		if (*line && !i)
			*line = NULL;
		return (i);
	}
	*line = ost[fd];
	ost[fd] = NULL;
	return (1);
}
