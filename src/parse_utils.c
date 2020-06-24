/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdean <hdean@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/21 14:20:14 by hdean             #+#    #+#             */
/*   Updated: 2020/06/24 20:14:59 by hdean            ###   ########.fr       */
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
	double	first;
	int		second;
	double	result;
	char	*tmp;
	int		k;

	tmp = (char *)str;
	first = (double)ft_atoi(tmp);
	while (*tmp && (ft_isspace(*tmp) || ft_isdigit(*tmp) || ft_issign(*tmp)))
		tmp++;
	if (*tmp == '.')
		tmp++;
	else
		return (first);
	second = (first < 0) ? (-1) * ft_atoi(tmp) : ft_atoi(tmp);
	k = 0;
	while (*tmp && ft_isdigit(*tmp))
	{
		k++;
		tmp++;
	}
	result = (second == 0) ? first : (first * ft_fast_pow(10, k) + second) /
										ft_fast_pow(10, k);
	return (result);
}

static double	parse_coordinate(char **p)
{
	double		coord;
	char		*tmp;

	tmp = *p;
	coord = parse_num(tmp);
	while (*tmp && (ft_isspace(*tmp) || ft_isdigit(*tmp) || *tmp == '.' ||
				ft_issign(*tmp)))
		tmp++;
	if (*tmp == ',')
		tmp++;
	else
	{
		ft_putstr("Error: something wrong with scene param values\n");
		exit(1);
	}
	*p = tmp;
	return (coord);
}

t_point			parse_point(char *str)
{
	char		*tmp;
	t_point		point;

	ft_bzero(&point, sizeof(point));
	tmp = str;
	while (*tmp && (ft_isspace(*tmp)))
		tmp++;
	point.x = parse_coordinate(&tmp);
	point.y = parse_coordinate(&tmp);
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
