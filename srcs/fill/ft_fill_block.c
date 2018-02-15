/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_block.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frahaing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 13:33:43 by frahaing          #+#    #+#             */
/*   Updated: 2018/01/11 13:33:45 by frahaing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_ls.h"

void	ft_fill_block(t_dir_info *dir_info, struct stat *buf)
{
	if (!dir_info)
		return ;
	dir_info->block = buf->st_blocks;
}
