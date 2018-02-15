/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_time.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frahaing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 16:47:41 by frahaing          #+#    #+#             */
/*   Updated: 2017/12/26 19:09:42 by frahaing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_ls.h"

static char		*ft_shortenpath(char *path)
{
	char	*tmp;

	if (!path)
		return (NULL);
	tmp = ft_strrchr(path, '/');
	if (tmp && *(tmp + 1) == 0)
		return ("\rls: ");
	else if (tmp)
		return (tmp + 1);
	else
		return (path);
}

static int		ft_open(char **path)
{
	struct stat			buf;

	if (!*path)
		return (0);
	if (lstat(*path, &buf) < 0)
	{
		ft_putstr("ls: ");
		perror(ft_shortenpath(*path));
		ft_strdel(path);
		return (0);
	}
	return (1);
}

int				ft_time_file(t_dir_info **list, char *arguments, int i)
{
	struct stat	buf1;
	struct stat buf2;

	lstat(list[i]->full_path, &buf1);
	lstat(list[i + 1]->full_path, &buf2);
	if (FT_ISDIR(buf1.st_mode) && !FT_ISDIR(buf2.st_mode))
	{
		ft_swap((void **)&list[i], (void **)&list[i + 1]);
		i = -1;
	}
	if (ft_letter_there(arguments, 't') && list[i] && list[i + 1])
		if (buf1.st_mtime < buf2.st_mtime &&
			(opendir(list[i + 1]->full_path)))
		{
			ft_swap((void **)&list[i], (void **)&list[i + 1]);
			i = -1;
		}
	return (i);
}

void			ft_sort_time_args(char *arguments, t_dir_info **list)
{
	int			i;

	i = 0;
	if (!list[i + 1])
		ft_open(&list[i]->full_path);
	while (list[i] && list[i + 1])
	{
		while (list[i] && !ft_open(&list[i]->full_path))
			i++;
		if (!list[i] || !list[i + 1])
			return ;
		else if (!ft_open(&list[i]->full_path))
			i++;
		i = ft_time_file(list, arguments, i);
		i++;
	}
	if (ft_letter_there(arguments, 'r') && list[0] && list[1])
		ft_sort_rev_args(list, 0, i);
}

t_dir_info		*ft_sort_time(t_dir_info *list)
{
	struct stat	buf1;
	struct stat	buf2;

	while (list && list->next)
	{
		lstat(list->full_path, &buf1);
		lstat(list->next->full_path, &buf2);
		if (buf1.st_mtime < buf2.st_mtime)
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
