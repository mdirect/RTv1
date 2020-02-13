/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdirect <mdirect@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 18:58:58 by mdirect           #+#    #+#             */
/*   Updated: 2019/09/17 19:45:23 by mdirect          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	unsigned long long	n;
	int					sign;

	n = 0;
	sign = 1;
	while (*str && (((*str) >= 9 && (*str) <= 13) || *str == 32))
		str++;
	if (*str == '+' || *str == '-')
	{
		sign = (*str == '-') ? -1 : 1;
		str++;
	}
	while (ft_isdigit(*str))
	{
		n = n * 10 + (*str - '0');
		str++;
	}
	if (n > (long long)9223372036854775807 && sign == 1)
		return (-1);
	if (n > (long long)9223372036854775807 && sign == -1)
		return (0);
	return ((int)(n * sign));
}
