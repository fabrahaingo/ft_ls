/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fbd_arg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frahaing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 13:59:46 by frahaing          #+#    #+#             */
/*   Updated: 2018/01/08 14:47:53 by frahaing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int		ft_fbd_arg(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i])
	{
		if (str[i] == 'a' || str[i] == 'l' || str[i] == 'r' || str[i] == 'R' ||
				str[i] == 't')
			i++;
		else
		{
			ft_putstr("ls: illegal option -- ");
			ft_putchar(str[i]);
			ft_putchar('\n');
			ft_putendl("usage: ls [-Ralrt] [file ...]");
			return (1);
		}
	}
	return (0);
}
