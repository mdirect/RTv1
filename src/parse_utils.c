/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdean <hdean@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/21 14:20:14 by hdean             #+#    #+#             */
/*   Updated: 2020/06/21 19:24:50 by hdean            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static int		ft_fast_pow(int base, int pow)
{
	int res;

	res = 1;
	while (pow)
	{
		if (pow & 1)
			res *= base;
		base *= base;
		pow >>= 1;
	}
	return (res);
}

double			parse_num(const char *str)
{
	int		first;
	int		second;
	double	result;
	char	*tmp;
	int		k;

	tmp = (char *)str;
	first = ft_atoi(tmp);
	while (*tmp && *tmp != '.' && *tmp != ',')
		tmp++;
	if (*tmp == ',')
		return ((double)first);
	else
		tmp++;
	second = ft_atoi(tmp);
	k = 0;
	while (*tmp && ft_isdigit(*tmp))
	{
		k++;
		tmp++;
	}
	result = (second == 0) ? (double)first : (double)(first *
							ft_fast_pow(10, k) + second) / ft_fast_pow(10, k);
	return (result);
}

static double	parse_coordinate(char **p)
{
	double	coord;
	char	*tmp;

	tmp = *p;
	coord = parse_num(tmp);
	while (*tmp && (ft_isspace(*tmp) || ft_isdigit(*tmp) || *tmp == '.' ||
				ft_issign(*tmp)))
		tmp++;
	if (*tmp == ',')
		tmp++;
	else
	{
		ft_putstr("Error: something wrong with the point.\n");
		//think about free in case of error: how can handle, maybe some int value for check
		exit(1);
	}
	*p = tmp;
	return (coord);
}

t_point			parse_point(char *str)
{
	char	*tmp;
	t_point	point;

	ft_bzero(&point, sizeof(point));
	tmp = str;
	while (*tmp && (ft_isspace(*tmp)))
		tmp++;
	point.x = parse_coordinate(&tmp);
	point.y = parse_coordinate(&tmp);
	printf("|%s\n", tmp);
	point.z = parse_num(tmp);
	return (point);
}

void			check_color_value(t_point *color)
{
	if (color->x < 0.0)
		color->x = 0.0;
	if (color->y < 0.0)
		color->y = 0.0;
	if (color->z < 0.0)
		color->z = 0.0;
	if (color->x > 255.0)
		color->x = 255.0;
	if (color->y > 255.0)
		color->y = 255.0;
	if (color->z > 255.0)
		color->z = 255.0;
}
