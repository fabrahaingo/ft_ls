/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_blocks.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frahaing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 00:01:55 by frahaing          #+#    #+#             */
/*   Updated: 2018/01/09 14:46:51 by frahaing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_ls.h"

void	ft_print_blocks(t_dir_info *list, int visible)
{
	blkcnt_t		res;

	res = 0;
	if (list == NULL)
		return ;
	while (list)
	{
		if (visible == 1 && (list->name)[0] != '.')
			res += list->block;
		if (visible == 0)
			res += list->block;
		list = list->next;
	}
	ft_putstr("total ");
	ft_putnbr(res);
	ft_putchar('\n');
}
