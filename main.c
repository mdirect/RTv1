/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdirect <mdirect@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 12:41:49 by mdirect           #+#    #+#             */
/*   Updated: 2020/03/12 15:08:32 by mdirect          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	make_scene(t_scene *scene)
{
	scene->bg_color = 0x000000;
	scene->o = (t_point){0.0, 0.0, 0.0};
	scene->light[0] = make_light(1, 0.6, (t_point){2.0, 1.0, 0.0});
	scene->light[1] = make_light(0, 0.2, (t_point){0.0, 0.0, 0.0});
	scene->light[2] = make_light(2, 0.2, (t_point){1.0, 4.0, 4.0});
	scene->sph[0] = make_sphere((t_point){-2.0, 0.0, 7.0}, 1.2, 0x00FF00);
	scene->sph[1] = make_sphere((t_point){0.0, -1.0, 6.0}, 1.5, 0xFF0000);
	scene->sph[2] = make_sphere((t_point){2.0, 3.0, 10.0}, 1.0, 0x0000FF);
	scene->sph[3] = make_sphere((t_point){7.5, -5.0, 20.0}, 2.0, 0x00FFCC);
}

int		main(int argc, char **argv)
{
	t_param_window	p;

	if (argc != 1)
		return (ft_usage());
	argv[1] = NULL;
	create_windows(&p);
	make_scene(&p.scene);
	draw(&p);
	push_control(&p);
	mlx_loop(p.mlx);
	return (0);
}
