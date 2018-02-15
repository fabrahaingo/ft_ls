/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frahaing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 17:16:37 by frahaing          #+#    #+#             */
/*   Updated: 2018/01/09 16:34:08 by frahaing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static t_dir_info	*ft_is_dir(DIR *opened, struct dirent *rep,
						t_dir_info *list, char *path)
{
	t_dir_info	*tmp;

	while ((rep = readdir(opened)))
	{
		if (list)
		{
			list->next = new_elem(list, path, rep);
			list = list->next;
		}
		else
		{
			list = new_elem(list, path, rep);
			tmp = list;
		}
		list->next = 0;
	}
	return (tmp);
}

t_dir_info			*ft_create_list(char *path)
{
	DIR				*opened;
	struct dirent	*rep;
	t_dir_info		*list;
	t_dir_info		*tmp;
	struct stat		buf;

	list = NULL;
	rep = NULL;
	if ((opened = opendir(path)))
	{
		tmp = ft_is_dir(opened, rep, list, path);
		closedir(opened);
	}
	else if (!(stat(path, &buf)))
		tmp = new_elem(list, path, rep);
	else
		tmp = new_elem(list, path, rep);
	return (tmp);
}
