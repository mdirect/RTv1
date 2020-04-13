/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdirect <mdirect@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 12:43:06 by mdirect           #+#    #+#             */
/*   Updated: 2020/04/13 11:25:19 by estel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_H
# define RT_H
# define WIN_X 800
# define WIN_Y 800
# define E 0.001
# define DEPTH 3
# define OBJ_C 5
# define LIGHT_C 3

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


/*
 * 1 - sphere
 * 2 - cylinder
 * 3 - cone
 * 4 - plane
 */

typedef struct			s_object
{
	int 				type;
	t_point				c;
	double				r;
	t_point				l;
	double				angle;
	t_point 			color;
	double				specular;
	double 				mirror;
	double				t[2];
	t_point				p;
	t_point				n;
}						t_object;

typedef struct			s_light
{
	int 				type;
	double 				intens;
	t_point				c;
}						t_light;

typedef struct			s_scene
{
	t_point				bg_color;
	t_point				o;
	t_point 		    angle;
	t_object			obj[OBJ_C];
	t_light				light[LIGHT_C];
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
t_object				make_sphere(t_point centre, double radius,
						t_point color, double specular, double mirror);
t_object				make_cylinder(t_point centre, double radius,
						t_point line, t_point color, double specular,
						double mirror);
t_object				make_cone(t_point centre, t_point line, double angle,
						t_point color, double specular, double mirror);
t_object				make_plane(t_point c, t_point line, t_point color,
						double specular, double mirror);
t_light					make_light(int type, double intens, t_point c);
void					draw(t_param_window *p);
__uint32_t				check_color(t_point c);
t_point					vector(t_point a, t_point b);
double					scalar(t_point a, t_point b);
t_point					multi(double k, t_point a);
t_point					summa(t_point a, t_point b);
double					modul(t_point a);
void					quadr_eq_solve(double a, double b, double c,
						double *t1, double *t2);
void					hit_figures(t_object *obj, t_point o, t_point d);
void					hit_sphere(t_object *sph, t_point o, t_point d);
void					hit_cylinder(t_object *cyl, t_point o, t_point d);
void					hit_cone(t_object *cone, t_point o, t_point d);
void					hit_plane(t_object *plane, t_point o, t_point d);
void					normal(t_object *obj, t_point o, t_point d);
void					normal_sphere(t_object *sph);
void					normal_cylinder(t_object *cyl, t_point o, t_point d);
void					normal_cone(t_object *cone, t_point o, t_point d);
void					normal_plane(t_object *plane);
int						closest(t_scene *s, t_point o, t_point d, double min_t,
						double max_t);
double					make_color(t_scene *s, t_point v, int i);
t_point					rt(t_scene *s, t_point o, t_point d, double min_t,
						double max_t, int depth);
void					push_control(t_param_window *p);
int						push_key(int key, t_param_window *p);
int						x_close(void *param);
t_point					rotate_matrix(t_scene *s, t_point d);
void					move_rotate(int key, t_param_window *p);
t_point					rotate_x(double angle, t_point d);
t_point					rotate_y(double angle, t_point d);
t_point					rotate_z(double angle, t_point d);

/*
** int						push_mouse(int key, int x, int y, void *param);
** int						repush_mouse(int key, int x, int y, void *param);
** int						move_mouse(int x, int y, void *param);
*/

#endif
