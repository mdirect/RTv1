/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_open_cl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdirect <mdirect@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 17:48:39 by mdirect           #+#    #+#             */
/*   Updated: 2020/02/13 13:58:14 by mdirect          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
/*
void				ret_error(int code)
{
	if (code)
	{
		write(1, "error while set openCL values: ", 31);
		ft_putnbr(code);
		write(1, "\n", 1);
		exit(code);
	}
}

t_cl		start_cl(void)
{
	t_cl	cl;

	cl.ret = clGetPlatformIDs(1, &cl.platforms, &cl.num_platforms);
	ret_error(cl.ret);
	cl.ret = clGetDeviceIDs(cl.platforms, CL_DEVICE_TYPE_DEFAULT, 1,
			&cl.device, &cl.num_devices);
	ret_error(cl.ret);
	cl.context = clCreateContext(NULL, 1, &cl.device, NULL, NULL, &cl.ret);
	ret_error(cl.ret);
	cl.command_queue = clCreateCommandQueue(cl.context, cl.device, 0, &cl.ret);
	ret_error(cl.ret);
	return (cl);
}

void		compile_cl(t_fractol *f)
{
	int			fd;
	size_t		source_size;
	char		*source_str;

	if (!(fd = open("open_cl.cl", O_RDONLY)))
	{
		write(1, "Failed to load kernel.\n", 23);
		exit(-1);
	}
	source_str = (char *)malloc(MAX_SOURCE_SIZE);
	source_size = read(fd, source_str, MAX_SOURCE_SIZE);
	close(fd);
	f->cl.prog = clCreateProgramWithSource(f->cl.context, 1,
			(const char **)&source_str,
			(const size_t *)&source_size, &f->cl.ret);
	ret_error(f->cl.ret);
	f->cl.ret = clBuildProgram(f->cl.prog, 1, &f->cl.device, NULL, NULL, NULL);
	ret_error(f->cl.ret);
	f->cl.kernel = clCreateKernel(f->cl.prog, "draw", &f->cl.ret);
	ret_error(f->cl.ret);
	free(source_str);
	make_buf_cl(f);
}

void		make_buf_cl(t_fractol *f)
{
	f->cl.memobj = clCreateBuffer(f->cl.context, CL_MEM_READ_WRITE,
			(WIN_X * WIN_Y) * sizeof(cl_int), NULL, &f->cl.ret);
	ret_error(f->cl.ret);
	f->cl.ret = clEnqueueWriteBuffer(f->cl.command_queue, f->cl.memobj, CL_TRUE,
			0, (WIN_X * WIN_Y) * sizeof(int), f->win.img_data, 0, NULL, NULL);
	ret_error(f->cl.ret);
	f->cl.ret = clSetKernelArg(f->cl.kernel, 0, sizeof(cl_mem),
			(void *)&f->cl.memobj);
	ret_error(f->cl.ret);
	draw_cl(f);
}

void		cl_arg(t_fractol *f)
{
	f->cl.ret = clSetKernelArg(f->cl.kernel, 1, sizeof(float), (void *)&f->x);
	ret_error(f->cl.ret);
	f->cl.ret = clSetKernelArg(f->cl.kernel, 2, sizeof(float), (void *)&f->y);
	ret_error(f->cl.ret);
	f->cl.ret = clSetKernelArg(f->cl.kernel, 3,
			sizeof(float), (void *)&f->zoom);
	ret_error(f->cl.ret);
	f->cl.ret = clSetKernelArg(f->cl.kernel, 4, sizeof(int), (void *)&f->type);
	ret_error(f->cl.ret);
	f->cl.ret = clSetKernelArg(f->cl.kernel, 5,
			sizeof(float), (void *)&f->j.re);
	ret_error(f->cl.ret);
	f->cl.ret = clSetKernelArg(f->cl.kernel, 6,
			sizeof(float), (void *)&f->j.im);
	ret_error(f->cl.ret);
	f->cl.ret = clSetKernelArg(f->cl.kernel, 7, sizeof(int), (void *)&f->max_i);
	ret_error(f->cl.ret);
	f->cl.ret = clSetKernelArg(f->cl.kernel, 8,
			sizeof(float), (void *)&f->color);
	ret_error(f->cl.ret);
}

void		draw_cl(t_fractol *f)
{
	size_t		global_work_size[1];
	char		*text;

	cl_arg(f);
	global_work_size[0] = WIN_X * WIN_Y;
	f->cl.ret = clEnqueueNDRangeKernel(f->cl.command_queue, f->cl.kernel, 1,
			NULL, global_work_size, NULL, 0, NULL, NULL);
	ret_error(f->cl.ret);
	f->cl.ret = clEnqueueReadBuffer(f->cl.command_queue, f->cl.memobj, CL_TRUE,
			0, (WIN_X * WIN_Y) * sizeof(int), f->win.img_data, 0, NULL, NULL);
	ret_error(f->cl.ret);
	mlx_put_image_to_window(f->win.mlx, f->win.window, f->win.img, 0, 0);
	mlx_string_put(f->win.mlx, f->win.window, 5, 980, 0xffffff,
			"Help: Right MB");
	mlx_string_put(f->win.mlx, f->win.window, 850, 980, 0xffffff,
			"Iteration:");
	text = ft_itoa(f->max_i);
	mlx_string_put(f->win.mlx, f->win.window, 955, 980, 0xffffff,
			text);
	free(text);
}
*/
