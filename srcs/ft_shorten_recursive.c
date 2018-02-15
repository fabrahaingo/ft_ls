/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shorten_recursive.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frahaing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 17:27:18 by frahaing          #+#    #+#             */
/*   Updated: 2018/01/11 17:27:20 by frahaing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

t_dir_info	*shorten_ft_recursive(char *arguments, t_dir_info *list)
{
	if (list == NULL)
		return (list);
	if (ft_letter_there(arguments, 't'))
		list = ft_sort_time(list);
	if (ft_letter_there(arguments, 'r'))
		list = ft_sort_rev(&list);
	return (list);
}
