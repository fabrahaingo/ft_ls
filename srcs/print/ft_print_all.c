/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_all.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frahaing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 18:58:38 by frahaing          #+#    #+#             */
/*   Updated: 2018/01/09 15:00:41 by frahaing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_ls.h"

static void	ft_print_params(t_dir_info *list, char *arguments)
{
	if (list && arguments && ft_letter_there(arguments, 'l'))
	{
		ft_putstr(list->mode);
		ft_putstr("    ");
		ft_putnbr(list->links);
		ft_putstr(" ");
		ft_putstr(list->user);
		ft_putstr("  ");
		ft_putstr(list->group);
		ft_putstr("    ");
		ft_putnbr(list->size);
		ft_putstr(" ");
		ft_putstr(list->month);
		ft_putstr(" ");
		ft_putstr(list->day);
		ft_putstr(" ");
		ft_putstr(list->time);
		ft_putstr(" ");
	}
	ft_putstr(list->name);
}

static void	ft_putsym(char *sym_path)
{
	ft_putstr(" -> ");
	ft_putstr(sym_path);
}

void		ft_print_all(t_dir_info *list, char *arguments)
{
	if (list->next)
	{
		if (ft_letter_there(arguments, 'l'))
		{
			if (ft_letter_there(arguments, 'a') && list->next)
				ft_print_blocks(list, 0);
			if (!ft_letter_there(arguments, 'a') && list->next)
				ft_print_blocks(list, 1);
		}
	}
	while (list)
	{
		if (!(ft_letter_there(arguments, 'a')) && *list->name == '.')
		{
			list = list->next;
			continue ;
		}
		ft_print_params(list, arguments);
		if (list->sym_path != NULL && (ft_letter_there(arguments, 'l')))
			ft_putsym(list->sym_path);
		if (list->name)
			ft_putchar('\n');
		if (list)
			list = list->next;
	}
}
