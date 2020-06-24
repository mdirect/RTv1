/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_params.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdean <hdean@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/21 13:18:19 by hdean             #+#    #+#             */
/*   Updated: 2020/06/24 17:55:30 by hdean            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include "read.h"

void parse_bg_color(char *line, t_scene *scene)
{
	scene->bg_color = parse_point(line);
	check_color_value(&scene->bg_color);	
}

static t_light		make_light(int type, double intens, t_point c)
{
	t_light light;

	light.type = type;
	light.intens = intens;
	light.c = c;
	return (light);
}

int parse_light(char *line, t_scene *scene, int *current_light)
{
	int		light_type;
	double	intens;
	char	*tmp;

	tmp = line;
	light_type = ft_atoi(tmp);
	if (light_type > 2 && light_type < 0)
		return (1);
	while (*tmp && (ft_isdigit(*tmp) || ft_isspace(*tmp)))
		tmp++;
	if (*tmp == ';')
		intens = parse_num(tmp + 1);
	else
		return (1); //think about terminate()
	tmp++;
	while (*tmp && (ft_isdigit(*tmp) || ft_isspace(*tmp) || *tmp == '.' ||
					ft_issign(*tmp)))
		tmp++;
	if (*tmp == ';')
		tmp++;
	else
		return (1); //think about terminate()
	scene->light[(*current_light)++] = make_light(light_type, intens,
													parse_point(tmp));
	return (0);	
}

int parse_object(int type, char *buf, t_scene *scene, int *current_object)
{
	char    *tmp;

	tmp = buf;
	scene->obj[*current_object].type = type;
	if (type == SPHERE)
	{
		if (parse_sphere(tmp + 7, scene, current_object))
			return (1);
	}
	if (type == CYLINDER)
	{
		if (parse_cylinder(tmp + 9, scene, current_object))
			return (1);
	}
	if (type == CONE)
	{
		if (parse_cone(tmp + 5, scene, current_object))
			return (1);		
	}
	if (type == PLANE)
	{
		if (parse_plane(tmp + 6, scene, current_object))
			return (1);	
	}
	return (0);
}