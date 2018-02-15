/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_elem.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frahaing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/27 18:57:39 by frahaing          #+#    #+#             */
/*   Updated: 2018/01/09 14:42:02 by frahaing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static char		*ft_dir_path(char *path, struct dirent *rep)
{
	char	*full_path;
	char	*tmp;

	tmp = NULL;
	if (rep)
	{
		tmp = ft_strjoin(path, "/");
		full_path = ft_strjoin(tmp, rep->d_name);
		ft_strdel(&tmp);
	}
	else
		full_path = ft_strdup(path);
	return (full_path);
}

t_dir_info		*new_elem(t_dir_info *prev, char *path, struct dirent *rep)
{
	t_dir_info	*init;

	if ((init = (t_dir_info *)ft_memalloc(sizeof(t_dir_info))) == NULL)
		return (NULL);
	init->mode = NULL;
	init->links = 0;
	init->user = NULL;
	init->group = NULL;
	init->size = 0;
	init->month = NULL;
	init->day = NULL;
	init->time = NULL;
	if (rep)
		init->name = ft_strdup(rep->d_name);
	else
		init->name = ft_strdup(path);
	init->full_path = ft_dir_path(path, rep);
	init->sym_path = NULL;
	init->block = 0;
	init->next = NULL;
	init->prev = prev;
	return (init);
}

void			del_list(t_dir_info *list)
{
	if (!list)
		return ;
	if (list->full_path)
		ft_strdel(&(list->full_path));
	if (list->sym_path)
		ft_strdel(&(list->sym_path));
	if (list->mode)
		ft_strdel(&(list->mode));
	if (list->user)
		ft_strdel(&(list->user));
	if (list->group)
		ft_strdel(&(list->group));
	if (list->month)
		ft_strdel(&(list->month));
	if (list->day)
		ft_strdel(&(list->day));
	if (list->time)
		ft_strdel(&(list->time));
	if (list->name)
		ft_strdel(&(list->name));
	del_list(list->next);
	list->prev = NULL;
	list->next = NULL;
	free(list);
}
