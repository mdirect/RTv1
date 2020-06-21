/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdean <hdean@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/21 12:47:15 by hdean             #+#    #+#             */
/*   Updated: 2020/06/21 18:06:28 by hdean            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READ_H
# define READ_H

# define SPHERE 1
# define CYLINDER 2
# define CONE 3
# define PLANE 4
# define BG_COLOR 5
# define O_PARAM 6
# define ANGLE 7
# define LIGHT 8

typedef	struct	s_count
{
	int		light;
	int		object;
}				t_count;

#endif