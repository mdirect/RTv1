/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdirect <mdirect@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 09:50:20 by mdirect           #+#    #+#             */
/*   Updated: 2019/09/28 22:16:50 by mdirect          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_itoa(int n)
{
	char	*str;
	int		len;
	int		begin;

	len = ft_lenint(n);
	if (!(str = ft_strnew(len)))
		return (NULL);
	begin = (n < 0) ? 1 : 0;
	str[len] = '\0';
	while (--len >= begin)
	{
		str[len] = (n < 0) ? (-1 * (n % 10) + '0') : ((n % 10) + '0');
		n = n / 10;
	}
	if (begin == 1)
		str[0] = '-';
	return (str);
}
