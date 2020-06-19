/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdirect <mdirect@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 12:41:49 by mdirect           #+#    #+#             */
/*   Updated: 2020/06/08 14:02:21 by estel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int		main(int argc, char **argv)
{
	t_param_window	p;

	if (argc != 2)
		return (ft_usage());
	printf("%s\n", argv[1]);
	read_scene(argv[1], &p.scene);
	create_windows(&p);
	// scene_1(&p.scene);
//	scene_2(&p.scene);
//	scene_3(&p.scene);
	// scene_4(&p.scene);
	// scene_5(&p.scene);
	draw(&p);
	push_control(&p);
	mlx_loop(p.mlx);
	return (0);
}
