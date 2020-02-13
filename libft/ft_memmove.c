/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdirect <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 17:33:44 by mdirect           #+#    #+#             */
/*   Updated: 2019/09/28 22:16:50 by mdirect          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t i;

	if (!src && !dst)
		return (dst);
	if (src > dst || (src + len) < dst)
	{
		i = -1;
		while (++i < len)
			((unsigned char*)dst)[i] = ((unsigned char *)src)[i];
	}
	else
	{
		while (len--)
			((unsigned char*)dst)[len] = ((unsigned char *)src)[len];
	}
	return (dst);
}
