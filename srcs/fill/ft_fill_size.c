/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frahaing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 00:20:51 by frahaing          #+#    #+#             */
/*   Updated: 2018/01/09 19:57:57 by frahaing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_ls.h"

void	ft_fill_size(t_dir_info *dir_info, struct stat *buf)
{
	if (!dir_info)
		return ;
	dir_info->size = buf->st_size;
}
