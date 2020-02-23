/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdirect <mdirect@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 12:43:06 by mdirect           #+#    #+#             */
/*   Updated: 2020/02/23 14:43:54 by mdirect          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_H
# define RT_H
# define WIN_X 1000
# define WIN_Y 1000
# define MAX_SOURCE_SIZE 10000
# ifdef cl_khr_fp64
# elif defined(cl_amd_fp64)
# endif

# include <OpenCL/opencl.h>
# include "minilibx_macos/mlx.h"
# include "libft/libft.h"
# include <math.h>
# include <unistd.h>
# include <stdlib.h>

/*
typedef struct			s_cl
{
	cl_int				ret;
	cl_context			context;
	cl_command_queue	command_queue;
	cl_platform_id		platforms;
	cl_uint				num_platforms;
	cl_device_id		device;
	cl_uint				num_devices;
	cl_program			prog;
	cl_kernel			kernel;
	cl_mem				memobj;
}						t_cl;
*/

typedef struct			s_param_window
{
	void				*window;
	void				*mlx;
	void				*img;
	int					*img_data;
	int					win_x;
}						t_param_window;

typedef struct			s_mouse
{
	int					press_l;
	int					x;
	int					y;
	int					x_pred;
	int					y_pred;
}						t_mouse;

typedef struct			s_point
{
	double 				x;
	double 				y;
	double 				z;
}						t_point;

typedef struct 			s_sphere
{
	t_point				c;
	double 				r;
	__uint32_t			color;
}						t_sphere;

typedef struct			s_scene
{
	__uint32_t			bg_color;
	t_point				o;
	t_sphere			sph;
}						t_scene;

int						ft_usage(void);
void					create_windows(t_param_window *p);
t_sphere				make_sphere(t_point centre, double radius, __uint32_t color);
void 					draw(t_param_window *p, t_scene *scene);
__uint32_t				k_color(double k, __uint32_t color);
__uint32_t				add_color(__uint32_t color1, __uint32_t color2);
double					scalar(t_point a, t_point b);
double 					hit_sphere(t_scene *scene, t_point d);
void					push_control(t_param_window *p);
int						push_key(int key, t_param_window *p);

/*
int						push_mouse(int key, int x, int y, void *param);
int						repush_mouse(int key, int x, int y, void *param);
int						move_mouse(int x, int y, void *param);
t_cl					start_cl(void);
void					compile_cl(t_param_window *p);
void					make_buf_cl(t_param_window *p);
void					draw_cl(t_param_window *p);
void					ret_error(int code);
 */

#endif
