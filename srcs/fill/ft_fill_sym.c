/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_sym.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frahaing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 22:19:16 by frahaing          #+#    #+#             */
/*   Updated: 2017/12/26 12:32:28 by frahaing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_ls.h"

void	ft_fill_sym(t_dir_info *dir_info)
{
	char	buf[1024];
	ssize_t	len;

	while (dir_info->next)
	{
		if ((len = readlink(dir_info->full_path, buf, sizeof(buf) - 1)) != -1)
		{
			buf[len] = '\0';
			dir_info->sym_path = (char *)malloc(sizeof(char) * ft_strlen(buf));
			dir_info->sym_path = ft_strcpy(dir_info->sym_path, buf);
		}
		dir_info = dir_info->next;
	}
}
