/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdirect <mdirect@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 12:41:49 by mdirect           #+#    #+#             */
/*   Updated: 2020/03/04 13:13:48 by estel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	make_scene(t_scene *scene)
{
	scene->bg_color = 0x000000;
	scene->o = (t_point){0.0, 0.0, 0.0};
	scene->light = (t_point){5.0, 5.0, 20.0};
	scene->sph = make_sphere((t_point){0.0, 0.0, 20.0}, 2.0, 0x00FF00);
}

int		main(int argc, char **argv)
{
	t_param_window	p;
	t_scene			scene;

	if (argc != 1)
		return (ft_usage());
	argv[1] = NULL;
	create_windows(&p);
	make_scene(&scene);
	draw(&p, &scene);
	push_control(&p);
	mlx_loop(p.mlx);
	return (0);
}
