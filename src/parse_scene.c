/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_scene.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdean <hdean@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/21 12:18:15 by hdean             #+#    #+#             */
/*   Updated: 2020/06/25 09:18:58 by estel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include "read.h"

static int	terminate(char *error, t_lines **lines, t_scene *scene)
{
	if (*lines)
		delete_list(lines);
	if (scene->light)
		free(scene->light);
	if (scene->obj)
		free(scene->obj);
	ft_putstr(error);
	exit(1);
}

static void	parse_line(int key, char *line, t_count *current, t_scene *scene)
{
	if (key == BG_COLOR)
		parse_bg_color(line + 9, scene);
	if (key == O_PARAM)
		scene->o = parse_point(line + 2);
	if (key == ANGLE)
		scene->angle = parse_point(line + 6);
	if (key == LIGHT)
	{
		if (parse_light(line + 6, scene, &current->light))
			exit(1);
	}
	if (key == SPHERE || key == CYLINDER || key == CONE || key == PLANE)
	{
		if (parse_object(key, line, scene, &current->object))
			exit(1);
	}
}

static int	choose_parameter(char *line)
{
	int key;

	key = -1;
	if (ft_strcmp_head(line, "bg_color:"))
		key = BG_COLOR;
	else if (ft_strcmp_head(line, "o:"))
		key = O_PARAM;
	else if (ft_strcmp_head(line, "angle:"))
		key = ANGLE;
	else if (ft_strcmp_head(line, "light:"))
		key = LIGHT;
	else if (ft_strcmp_head(line, "sphere:"))
		key = SPHERE;
	else if (ft_strcmp_head(line, "cylinder:"))
		key = CYLINDER;
	else if (ft_strcmp_head(line, "cone:"))
		key = CONE;
	else if (ft_strcmp_head(line, "plane:"))
		key = PLANE;
	return (key);
}

static void	check_scene(t_scene *scene, t_lines **lines, char *filename)
{
	read_lines_from_file(lines, filename, scene);
	if (scene->light_quant == 0 || scene->obj_quant == 0)
	{
		ft_putstr("Warning: empty scene\n");
		if (scene->light_quant == 0)
			scene->light_quant++;
		if (scene->obj_quant == 0)
			scene->obj_quant++;
	}
	scene->light = (t_light *)ft_memalloc(sizeof(t_light) * scene->light_quant);
	scene->obj = (t_object *)ft_memalloc(sizeof(t_object) * scene->obj_quant);
}

int			read_scene(char *filename, t_scene *scene)
{
	t_lines	*lines;
	t_lines	*tmp;
	t_count current;
	int		key;

	scene->light_quant = 0;
	scene->obj_quant = 0;
	current.light = 0;
	current.object = 0;
	lines = NULL;
	check_scene(scene, &lines, filename);
	if (!scene->light || !scene->obj)
		terminate("Error: memory allocation failed\n", &lines, scene);
	tmp = lines;
	while (tmp)
	{
		key = choose_parameter(tmp->line);
		if (key < 0)
			terminate("Error: wrong name of scene parameter\n", &lines, scene);
		parse_line(key, tmp->line, &current, scene);
		tmp = tmp->next;
	}
	delete_list(&lines);
	return (0);
}
