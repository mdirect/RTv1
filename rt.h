/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdirect <mdirect@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 12:43:06 by mdirect           #+#    #+#             */
/*   Updated: 2020/02/24 15:52:43 by mdirect          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_H
# define RT_H
# define WIN_X 1000
# define WIN_Y 1000

# include "minilibx_macos/mlx.h"
# include "libft/libft.h"
# include <math.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct			s_point
{
	double				x;
	double				y;
	double				z;
}						t_point;

typedef struct			s_sphere
{
	t_point				c;
	double				r;
	__uint32_t			color;
	double				t;
	t_point				p;
	t_point				n;
}						t_sphere;

typedef struct			s_scene
{
	__uint32_t			bg_color;
	t_point				o;
	t_sphere			sph[3];
	t_point				light;
}						t_scene;

typedef struct			s_param_window
{
	void				*window;
	void				*mlx;
	void				*img;
	int					*img_data;
	int					bpp;
	int					win_x;
	t_scene				scene;
}						t_param_window;

typedef struct			s_mouse
{
	int					press_l;
	int					x;
	int					y;
	int					x_pred;
	int					y_pred;
}						t_mouse;

int						ft_usage(void);
void					create_windows(t_param_window *p);
t_sphere				make_sphere(t_point centre, double radius,
						__uint32_t color);
void					draw(t_param_window *p);
__uint32_t				k_color(double k, __uint32_t color);
__uint32_t				add_color(__uint32_t color1, __uint32_t color2);
t_point					vector(t_point a, t_point b);
double					scalar(t_point a, t_point b);
t_point					multi(double k, t_point a);
t_point					summa(t_point a, t_point b);
double					modul(t_point a);
double					quadr_eq_solve(double a, double b, double c);
double					hit_sphere(t_scene *scene, t_point d, int i);
__uint32_t				rt(t_param_window *p, double x, double y);
void					push_control(t_param_window *p);
int						push_key(int key, t_param_window *p);

/*
** int						push_mouse(int key, int x, int y, void *param);
** int						repush_mouse(int key, int x, int y, void *param);
** int						move_mouse(int x, int y, void *param);
*/

#endif
