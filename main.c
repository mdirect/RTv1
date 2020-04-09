/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdirect <mdirect@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 12:41:49 by mdirect           #+#    #+#             */
/*   Updated: 2020/04/09 11:27:08 by estel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	make_scene(t_scene *scene)
{
	scene->bg_color = (t_point){0, 0, 0};
	scene->o = (t_point){0.0, 0.0, 0.0};
	scene->matrix[0][0] = 1;
	scene->matrix[0][1] = 0;
	scene->matrix[0][2] = 0;
	scene->matrix[1][0] = 0;
	scene->matrix[1][1] = 1;
	scene->matrix[1][2] = 0;
	scene->matrix[2][0] = 0;
	scene->matrix[2][1] = 0;
	scene->matrix[2][2] = 1;
	scene->angle = (t_point) {0, 0, 0};
	scene->light[0] = make_light(0, 0.3, (t_point){0.0, 0.0, 0.0});
	scene->light[1] = make_light(1, 0.6, (t_point){2.0, 1.0, 0.0});
	scene->light[2] = make_light(2, 0.2, (t_point){1.0, 4.0, 4.0});
//	scene->sph[0] = make_sphere((t_point){-2.0, 0.0, 4.0}, 1.0, (t_point){0, 255, 0}, 500.0, 0.3);
//	scene->sph[1] = make_sphere((t_point){0.0, -1.0, 3.0}, 1.0, (t_point){255, 0, 0}, 500.0, 0.2);
//	scene->sph[2] = make_sphere((t_point){2.0, 0.0, 4.0}, 1.0, (t_point){0, 0, 255}, 10.0, 0.4);
//	scene->sph[3] = make_sphere((t_point){0, -5001.0, 5.0}, 5000.0, (t_point){255, 255, 0}, 1000.0, 0.5);
	scene->sph[0] = make_sphere((t_point){-2.0, 0.0, 7.0}, 1.2, (t_point){0, 255, 0}, 100.0, 0.5);
	scene->sph[1] = make_sphere((t_point){-0.2, -1.0, 6.0}, 1.5, (t_point){255, 0, 0}, 50.0, 0.4);
	scene->sph[2] = make_sphere((t_point){2.0, 3.0, 10.0}, 2.0, (t_point){0, 0, 255}, 100.0, 0.6);
	scene->sph[3] = make_sphere((t_point){6.2, -1.5, 17.0}, 2.0, (t_point){0, 255, 255}, 10.0, 0.3);
	scene->sph[4] = make_sphere((t_point){0, -500.0, 5.0}, 499.0, (t_point){255, 255, 0}, 1000.0, 0.5);
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
