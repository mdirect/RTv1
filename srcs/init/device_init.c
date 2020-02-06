/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   device_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epainter <epainter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 16:26:10 by epainter          #+#    #+#             */
/*   Updated: 2020/01/30 15:10:36 by mdirect          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	device_info(t_vulkan *vk)
{
	vk->device_info.sType = VK_STRUCTURE_TYPE_DEVICE_CREATE_INFO;
	vk->device_info.pNext = NULL;
	vk->device_info.flags = 0;
}

void	device_init(t_vulkan *vk)
{
	vkCreateDevice(vk->gpu, &vk->device_info, &vk->p_alloc, &vk->device);
}