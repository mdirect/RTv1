/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdean <hdean@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/20 14:44:53 by hdean             #+#    #+#             */
/*   Updated: 2020/06/20 19:12:33 by hdean            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include <fcntl.h>

static int	check_fd(int fd, char *filename)
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

static void	delete_list(t_list **list)
{
	t_list		*tmp;
	t_list		*next_list;

	tmp = *list;

	while (tmp->line)
	{
		next_list = tmp->next;
		free(tmp->line);
		tmp->line = next_list;
	}
	free(tmp);
	*list = NULL;
}

static t_list	*new_line(t_list **list, char *line)
{
	t_list *new;
	
	if (new = (t_list *)ft_memalloc(sizeof(t_list)) &&
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

int			check_line(char *buf)
{
	char *tmp;

	tmp = buf;
	while (*tmp && )
	while (*tmp)
	{
		if (!ft_isspace(*tmp) && !ft_isdigit(*tmp) &&
					*tmp != '.' && *tmp != ',' && *tmp != ';')
			return (1);
		tmp++;	
	}
	return (0);
}

void		read_lines_from_file(t_list **lines, char *filename,
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
		if (check_line(buf) || new_line(&lines, buf))
		{
			close(fd);
			delete_list(lines);
			ft_putstr("Error: something failed while reading file\n");
			exit(1);
		}
		if (ft_strcmp_head(buf, "light:"))
			scene->light_quant++;
		else if (ft_strcmp_head(buf, "sphere:") ||
				ft_strcmp_head(buf, "cylinder:") ||
				ft_strcmp_head(buf, "cone:") || ft_strcmp_head(buf, "plane:"))
			scene->obj_quant++;
		free(buf);
	}
	close(fd);
}