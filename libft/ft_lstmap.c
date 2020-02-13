/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdirect <mdirect@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 14:22:55 by mdirect           #+#    #+#             */
/*   Updated: 2019/09/17 21:59:52 by mdirect          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *begin;
	t_list *elf;

	begin = NULL;
	if (f)
	{
		while (lst)
		{
			elf = f(lst);
			if (begin)
				ft_lstbackadd(&begin, elf);
			else
				begin = elf;
			lst = lst->next;
		}
	}
	return (begin);
}
