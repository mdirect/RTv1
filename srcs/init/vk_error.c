/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vk_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epainter <epainter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 14:34:38 by epainter          #+#    #+#             */
/*   Updated: 2020/01/30 15:10:36 by mdirect          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include <stdlib.h>
#include "libft.h"

void	vk_error(VkResult res)
{
	if (res != VK_SUCCESS)
	{
		ft_putstr("Vulkan error: ");
		ft_putnbr(res);
		exit(res);
	}
}
