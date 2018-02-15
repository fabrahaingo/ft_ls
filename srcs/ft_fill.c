/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frahaing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 13:28:50 by frahaing          #+#    #+#             */
/*   Updated: 2018/01/15 13:28:51 by frahaing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

t_dir_info	*ft_fill(char *path)
{
	t_dir_info		*list;
	t_dir_info		*tmp;
	struct stat		buf;

	list = ft_create_list(path);
	if (list)
	{
		tmp = list;
		ft_fill_user_group(list);
		ft_fill_sym(list);
		while (list)
		{
			ft_bzero((void *)&buf, sizeof(struct stat));
			lstat(list->full_path, &buf);
			ft_fill_mode(list, &buf);
			ft_fill_time_day_month(list, &buf);
			ft_fill_links(list, &buf);
			ft_fill_size(list, &buf);
			ft_fill_block(list, &buf);
			list = list->next;
		}
		list = ft_sort_alpha(tmp);
	}
	return (list);
}
