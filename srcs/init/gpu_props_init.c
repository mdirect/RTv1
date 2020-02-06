/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gpu_props_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epainter <epainter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 16:21:29 by epainter          #+#    #+#             */
/*   Updated: 2020/01/30 15:10:36 by mdirect          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include <stdlib.h>

void				gpu_props_init(t_vulkan *vk)
{
	vk->result = vkEnumeratePhysicalDevices(vk->instance, &vk->gpu_count, NULL);
	vk_error(vk->result);
	vkEnumeratePhysicalDevices(vk->instance, &vk->gpu_count, &vk->gpu);
	vk_error(vk->result);
	vkGetPhysicalDeviceProperties(vk->gpu, &vk->gpu_props);
	vkGetPhysicalDeviceMemoryProperties(vk->gpu, &vk->mem_properties);
	vkGetPhysicalDeviceQueueFamilyProperties(vk->gpu, &vk->count_queue, NULL);
	vk->queue_prop = malloc(sizeof(*vk->queue_prop) * vk->count_queue);
	vkGetPhysicalDeviceQueueFamilyProperties(vk->gpu,\
			&vk->count_queue, vk->queue_prop);
}
