/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_mode.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frahaing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 15:20:15 by frahaing          #+#    #+#             */
/*   Updated: 2018/01/09 19:47:14 by frahaing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_ls.h"

static void	ft_fill_type(const int mode, char *str)
{
	if (FT_ISIFO(mode))
		str[0] = 'p';
	else if (FT_ISLNK(mode))
		str[0] = 'l';
	else if (FT_ISCHR(mode))
		str[0] = 'c';
	else if (FT_ISSOCK(mode))
		str[0] = 's';
	else if (FT_ISDIR(mode))
		str[0] = 'd';
	else if (FT_ISBLK(mode))
		str[0] = 'b';
	else if (FT_ISWHT(mode))
		str[0] = 'w';
	else
		str[0] = '-';
}

static void	ft_fill_user(const int mode, char *str)
{
	if (FT_IRUSR(mode))
		str[1] = 'r';
	else if (!FT_IRUSR(mode))
		str[1] = '-';
	if (FT_IWUSR(mode))
		str[2] = 'w';
	else if (!FT_IWUSR(mode))
		str[2] = '-';
	if (FT_ISUID(mode) && FT_IXUSR(mode))
		str[3] = 's';
	else if (FT_ISUID(mode))
		str[3] = 'S';
	else if (FT_IXUSR(mode))
		str[3] = 'x';
	else
		str[3] = '-';
}

static void	ft_fill_group(const int mode, char *str)
{
	if (FT_IRGRP(mode))
		str[4] = 'r';
	else if (!FT_IRGRP(mode))
		str[4] = '-';
	if (FT_IWGRP(mode))
		str[5] = 'w';
	else if (!FT_IWGRP(mode))
		str[5] = '-';
	if (FT_ISGID(mode) && FT_IXGRP(mode))
		str[6] = 's';
	else if (FT_ISGID(mode))
		str[6] = 'S';
	else if (FT_IXGRP(mode))
		str[6] = 'x';
	else
		str[6] = '-';
}

static void	ft_fill_other(const int mode, char *str)
{
	if (FT_IROTH(mode))
		str[7] = 'r';
	else if (!FT_IROTH(mode))
		str[7] = '-';
	if (FT_IWOTH(mode))
		str[8] = 'w';
	else if (!FT_IWOTH(mode))
		str[8] = '-';
	if (FT_ISVTX(mode) && FT_IXOTH(mode))
		str[9] = 't';
	else if (FT_ISVTX(mode))
		str[9] = 'T';
	else if (FT_IXOTH(mode))
		str[9] = 'x';
	else
		str[9] = '-';
}

void		ft_fill_mode(t_dir_info *dir_info, struct stat *buf)
{
	if (!dir_info)
		return ;
	dir_info->mode = ft_strnew(10);
	ft_fill_type(buf->st_mode, dir_info->mode);
	ft_fill_user(buf->st_mode, dir_info->mode);
	ft_fill_group(buf->st_mode, dir_info->mode);
	ft_fill_other(buf->st_mode, dir_info->mode);
}
