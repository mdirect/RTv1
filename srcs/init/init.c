/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epainter <epainter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 21:07:47 by epainter          #+#    #+#             */
/*   Updated: 2020/01/30 15:10:36 by mdirect          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_params	init(void)
{
	t_params	params;
	t_vulkan	p_vulkan;

	params.p_glfw = init_window();
	init_vulkan(&p_vulkan);
	params.p_vulkan = p_vulkan;
	return (params);
}
