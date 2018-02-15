/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_links.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frahaing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/17 23:20:21 by frahaing          #+#    #+#             */
/*   Updated: 2018/01/09 17:10:17 by frahaing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_ls.h"

void	ft_fill_links(t_dir_info *dir_info, struct stat *buf)
{
	if (!dir_info)
		return ;
	dir_info->links = buf->st_nlink;
}
