/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_mode.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frahaing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 16:13:42 by frahaing          #+#    #+#             */
/*   Updated: 2017/12/14 16:15:14 by frahaing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_ls.h"

void	ft_print_mode(t_dir_info *list)
{
	while (list->mode)
	{
		ft_putstr(list->mode);
		list = list->next;
	}
}
