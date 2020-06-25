/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdean <hdean@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/20 14:44:53 by hdean             #+#    #+#             */
/*   Updated: 2020/06/25 09:18:58 by estel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include <fcntl.h>

static int		check_fd(int fd, char *filename)
{
	if (fd < 0)
	{
		ft_putstr("Error: file ");
		write(1, filename, ft_strlen(filename));
		ft_putstr(" doesn't exist\n");
		exit(1);
	}
	if (fd == 0 || read(fd, NULL, 0) == -1)
	{
		ft_putstr("Error: can't read the file: ");
		write(1, filename, ft_strlen(filename));
		ft_putchar('\n');
		exit(1);
	}
	return (0);
}

static t_lines	*new_line(t_lines **list, char *line)
{
	t_lines *new;

	if ((new = (t_lines *)ft_memalloc(sizeof(t_lines))) &&
												(new->line = ft_strdup(line)))
	{
		new->next = NULL;
		if (!*list)
			*list = new;
		else
		{
			new->next = *list;
			*list = new;
		}
	}
	return (*list);
}

static int		check_line(char *buf)
{
	char *tmp;

	tmp = buf;
	while (*tmp)
	{
		if (!ft_isspace(*tmp) && !ft_isalnum(*tmp) && !ft_issign(*tmp) &&
		*tmp != '.' && *tmp != ',' && *tmp != ';' && *tmp != '_' && *tmp != ':')
			return (1);
		tmp++;
	}
	return (0);
}

static void		count_objects_and_lights(t_scene *scene, char *buf)
{
	if (ft_strcmp_head(buf, "light:"))
		scene->light_quant++;
	else if (ft_strcmp_head(buf, "sphere:") ||
			ft_strcmp_head(buf, "cylinder:") ||
			ft_strcmp_head(buf, "cone:") ||
			ft_strcmp_head(buf, "plane:"))
		scene->obj_quant++;
}

void			read_lines_from_file(t_lines **lines, char *filename,
																t_scene *scene)
{
	int		fd;
	char	*buf;

	fd = open(filename, O_RDONLY);
	check_fd(fd, filename);
	while ((get_next_line(fd, &buf)))
	{
		if (!ft_strcmp(buf, ""))
		{
			free(buf);
			continue;
		}
		if (check_line(buf) || !(new_line(lines, buf)))
		{
			close(fd);
			free(buf);
			delete_list(lines);
			ft_putstr("Error: something failed while reading file\n");
			exit(1);
		}
		count_objects_and_lights(scene, buf);
		free(buf);
	}
	close(fd);
}
