/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_object.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdean <hdean@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/21 15:24:15 by hdean             #+#    #+#             */
/*   Updated: 2020/06/25 09:18:58 by estel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include "read.h"

static	int	move_pointer(char **p, int point)
{
	char *tmp;

	tmp = *p;
	if (point)
	{
		while (*tmp && (ft_isdigit(*tmp) || ft_isspace(*tmp) || *tmp == ',' ||
				*tmp == '.' || ft_issign(*tmp)))
			tmp++;
	}
	else
	{
		while (*tmp && (ft_isdigit(*tmp) || ft_isspace(*tmp) || *tmp == '.' ||
				ft_issign(*tmp)))
			tmp++;
	}
	if (*tmp == ';')
	{
		tmp++;
		*p = tmp;
		return (0);
	}
	return (1);
}

int			parse_sphere(char *tmp, t_scene *scene, int *i)
{
	scene->obj[*i].c = parse_point(tmp);
	if (move_pointer(&tmp, 1))
		return (1);
	scene->obj[*i].r = parse_num(tmp);
	if (move_pointer(&tmp, 1))
		return (1);
	scene->obj[*i].color = parse_point(tmp);
	check_color_value(&(scene->obj[*i].color));
	if (move_pointer(&tmp, 1))
		return (1);
	scene->obj[*i].specular = parse_num(tmp);
	if (move_pointer(&tmp, 0))
		return (1);
	scene->obj[*i].mirror = parse_num(tmp);
	*i += 1;
	return (0);
}

int			parse_cylinder(char *tmp, t_scene *scene, int *i)
{
	t_point line;

	scene->obj[*i].c = parse_point(tmp);
	if (move_pointer(&tmp, 1))
		return (1);
	scene->obj[*i].r = parse_num(tmp);
	if (move_pointer(&tmp, 0))
		return (1);
	line = parse_point(tmp);
	scene->obj[*i].l = multi(1 / modul(line), line);
	if (move_pointer(&tmp, 1))
		return (1);
	scene->obj[*i].color = parse_point(tmp);
	check_color_value(&(scene->obj[*i].color));
	if (move_pointer(&tmp, 1))
		return (1);
	scene->obj[*i].specular = parse_num(tmp);
	if (move_pointer(&tmp, 0))
		return (1);
	scene->obj[*i].mirror = parse_num(tmp);
	*i += 1;
	return (0);
}

int			parse_cone(char *tmp, t_scene *scene, int *i)
{
	t_point line;

	scene->obj[*i].c = parse_point(tmp);
	if (move_pointer(&tmp, 1))
		return (1);
	line = parse_point(tmp);
	scene->obj[*i].l = multi(1 / modul(line), line);
	if (move_pointer(&tmp, 1))
		return (1);
	scene->obj[*i].angle = parse_num(tmp);
	if (move_pointer(&tmp, 0))
		return (1);
	scene->obj[*i].color = parse_point(tmp);
	check_color_value(&(scene->obj[*i].color));
	if (move_pointer(&tmp, 1))
		return (1);
	scene->obj[*i].specular = parse_num(tmp);
	if (move_pointer(&tmp, 0))
		return (1);
	scene->obj[*i].mirror = parse_num(tmp);
	*i += 1;
	return (0);
}

int			parse_plane(char *tmp, t_scene *scene, int *i)
{
	t_point line;

	scene->obj[*i].c = parse_point(tmp);
	if (move_pointer(&tmp, 1))
		return (1);
	line = parse_point(tmp);
	scene->obj[*i].l = multi(1 / modul(line), line);
	if (move_pointer(&tmp, 1))
		return (1);
	scene->obj[*i].color = parse_point(tmp);
	check_color_value(&(scene->obj[*i].color));
	if (move_pointer(&tmp, 1))
		return (1);
	scene->obj[*i].specular = parse_num(tmp);
	if (move_pointer(&tmp, 0))
		return (1);
	scene->obj[*i].mirror = parse_num(tmp);
	*i += 1;
	return (0);
}
