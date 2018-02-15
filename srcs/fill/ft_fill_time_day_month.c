/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_time_day_month.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frahaing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 20:05:52 by frahaing          #+#    #+#             */
/*   Updated: 2018/01/09 20:25:57 by frahaing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_ls.h"

static char	*ft_month(char *str)
{
	char *month;

	month = ft_strnew(4);
	month = ft_strncpy(month, str + 4, 3);
	return (month);
}

static char	*ft_day(char *str)
{
	char *day;

	day = ft_strnew(3);
	day = ft_strncpy(day, str + 8, 2);
	return (day);
}

static char	*ft_time(char *str)
{
	char *time;

	time = ft_strnew(5);
	time = ft_strncpy(time, str + 11, 5);
	return (time);
}

void		ft_fill_time_day_month(t_dir_info *list, struct stat *buf)
{
	char			*time;

	time = ft_strdup(ctime(&buf->st_mtime));
	list->month = ft_month(time);
	list->day = ft_day(time);
	list->time = ft_time(time);
	ft_strdel(&time);
}
