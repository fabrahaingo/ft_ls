/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_elem.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frahaing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 17:55:43 by frahaing          #+#    #+#             */
/*   Updated: 2017/12/19 16:21:53 by frahaing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

t_dir_info	*ft_swap_elem(t_dir_info *elem1, t_dir_info *elem2)
{
	if (elem1->prev)
		elem1->prev->next = elem2;
	if (elem2->next)
		elem2->next->prev = elem1;
	elem1->next = elem2->next;
	elem2->prev = elem1->prev;
	elem2->next = elem1;
	elem1->prev = elem2;
	return (elem2);
}
