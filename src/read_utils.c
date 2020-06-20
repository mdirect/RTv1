/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdean <hdean@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/20 19:04:02 by hdean             #+#    #+#             */
/*   Updated: 2020/06/20 19:06:11 by hdean            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_strcmp_head(const char *str, const char *head)
{
	int i;

	if (!str || !head)
		return (0);
	i = 0;
	while (head[i])
	{
		if (head[i] != str[i])
			return (0);
		i++;
	}
	return (1);
}

int ft_isspace(char ch)
{
	return (ch == ' ' || ch == '\f' || ch == '\n' || ch == '\r' ||
                                                    ch == '\t' || ch == '\v');
}