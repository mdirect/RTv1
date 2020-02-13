/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdirect <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 14:13:31 by mdirect           #+#    #+#             */
/*   Updated: 2019/09/28 22:16:50 by mdirect          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t i;

	if (!src && !dst)
		return (dst);
	i = -1;
	while (++i < n)
		((unsigned char*)dst)[i] = ((unsigned char*)src)[i];
	return (dst);
}
