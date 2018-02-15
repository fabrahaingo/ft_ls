/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_alpha.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frahaing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 19:28:46 by frahaing          #+#    #+#             */
/*   Updated: 2018/01/09 20:19:21 by frahaing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_ls.h"

t_dir_info	*ft_sort_alpha(t_dir_info *list)
{
	if (list == NULL)
		return (NULL);
	while (list->next)
	{
		if (list->next->name &&
				(ft_strcmp(list->name, list->next->name) > 0))
		{
			ft_swap_elem(list, list->next);
			while (list->prev)
				list = list->prev;
			continue ;
		}
		list = list->next;
	}
	while (list->prev)
		list = list->prev;
	return (list);
}
