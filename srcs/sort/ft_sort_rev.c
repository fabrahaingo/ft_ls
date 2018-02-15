/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_rev.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frahaing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 16:49:36 by frahaing          #+#    #+#             */
/*   Updated: 2018/01/09 20:23:48 by frahaing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_ls.h"

static void	rev_list(t_dir_info *current, t_dir_info *prev, t_dir_info **list)
{
	t_dir_info	*next;

	if (!current->next)
	{
		*list = current;
		current->next = prev;
		return ;
	}
	next = current->next;
	current->next = prev;
	rev_list(next, current, list);
}

t_dir_info	*ft_sort_rev(t_dir_info **list)
{
	if (!list)
		return (NULL);
	rev_list(*list, NULL, list);
	return (*list);
}

void		ft_sort_rev_args(t_dir_info **list, int start, int end)
{
	int i;
	int j;
	int tmp;

	i = 0;
	j = 0;
	while (list[i]->mode[0] != 'd')
	{
		i++;
		start++;
	}
	tmp = start - 1;
	while (j < tmp)
	{
		ft_swap((void **)&list[j], (void **)&list[tmp]);
		j++;
		tmp--;
	}
	while (start < end)
	{
		ft_swap((void **)&list[start], (void **)&list[end]);
		start++;
		end--;
	}
}
