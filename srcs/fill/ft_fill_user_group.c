/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_user_group.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frahaing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 21:56:35 by frahaing          #+#    #+#             */
/*   Updated: 2018/01/09 17:57:37 by frahaing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_ls.h"

void		ft_fill_user_group(t_dir_info *dir_info)
{
	struct stat		buf;
	struct passwd	*user;
	struct group	*group;
	char			*user2;
	char			*group2;

	while (dir_info)
	{
		ft_bzero((void *)&buf, sizeof(struct stat));
		stat(dir_info->full_path, &buf);
		if (!(user = getpwuid(buf.st_uid)))
			user2 = ft_itoa(buf.st_uid);
		if (!(group = getgrgid(buf.st_gid)))
			group2 = ft_itoa(buf.st_gid);
		if (user)
			dir_info->user = ft_strdup(user->pw_name);
		else
			dir_info->user = user2;
		if (group)
			dir_info->group = ft_strdup(group->gr_name);
		else
			dir_info->group = group2;
		dir_info = dir_info->next;
	}
}
