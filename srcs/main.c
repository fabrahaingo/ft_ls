/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frahaing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 15:05:01 by frahaing          #+#    #+#             */
/*   Updated: 2018/01/23 17:14:56 by frahaing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static char			*ft_parsing(char **argv)
{
	int		i;
	int		len;
	char	*args;

	i = 1;
	len = 0;
	args = NULL;
	while (argv[i] && argv[i][0] == '-')
	{
		if (ft_strequ(argv[i], "--"))
			break ;
		len += ft_strlen(argv[i]);
		i++;
	}
	i = 1;
	while (argv[i] && argv[i][0] == '-')
	{
		if (ft_strequ(argv[i], "--"))
			return (args);
		args = ft_strdup(argv[i] + 1);
		i++;
	}
	return (args);
}

static void			ft_recursive(t_dir_info *list, int argc, char *arguments)
{
	t_dir_info	*clone;

	if (list == 0)
		return ;
	list = shorten_ft_recursive(arguments, list);
	ft_print_all(list, arguments);
	clone = list;
	if (ft_letter_there(arguments, 'R'))
	{
		while (clone)
		{
			if (clone && (clone->mode)[0] == 'd' && ft_strcmp(clone->name, ".")
					!= 0 && ft_strcmp(clone->name, "..") != 0
					&& (clone->next || clone->prev) &&
					(ft_letter_there(arguments, 'a') || clone->name[0] != '.'))
			{
				ft_putendl("");
				ft_putstr(clone->full_path);
				ft_putendl(":");
				ft_recursive(ft_fill(clone->full_path), argc, arguments);
			}
			clone = clone->next;
		}
	}
	del_list(list);
}

static void			ft_shorten_shorten(t_dir_info **list, int argc,
						char *arguments)
{
	int			idx;
	struct stat	buf;
	char		*tmp;

	idx = 0;
	ft_sort_time_args(arguments, list);
	while (list[idx])
	{
		if (list[idx]->mode && list[idx]->mode[0] == 'd' && idx != 0)
			ft_putendl("");
		if (list[idx]->mode && list[idx]->mode[0] == 'd' && (idx != 0 ||
			(list[0] && list[1])))
		{
			ft_putstr(tmp = ft_strcutend(list[idx]->full_path, 1));
			ft_strdel(&tmp);
			ft_putendl(":");
		}
		if (!lstat(list[idx]->full_path, &buf))
			ft_recursive(list[idx], argc, arguments);
		else
			del_list(list[idx]);
		idx++;
	}
}

static void			ft_shorten_main(int argc, char *arguments, int i,
						char **argv)
{
	t_dir_info	**list;
	int			idx;
	char		*argv_illegal[3];

	idx = 0;
	list = (t_dir_info**)ft_memalloc(sizeof(t_dir_info*) * (argc - i + 1));
	if (i >= argc)
	{
		argv_illegal[0] = argv[0];
		argv_illegal[1] = ".";
		argv_illegal[2] = 0;
		argv = argv_illegal;
		argc = 2;
		i = 1;
	}
	while (i < argc)
	{
		list[idx] = ft_fill(argv[i]);
		i++;
		idx++;
	}
	list[idx] = NULL;
	ft_shorten_shorten(list, argc, arguments);
	free(list);
}

int					main(int argc, char **argv)
{
	int		i;
	char	*arguments;

	i = 1;
	arguments = ft_parsing(argv);
	if (ft_fbd_arg(arguments) == 1)
		return (-1);
	while (i < argc && argv[i][0] == '-')
	{
		i++;
		if (!argv[i - 1][1])
		{
			ft_putendl("ls: -: No such file or directory");
			break ;
		}
		if (argv[i - 1] && ft_strcmp(argv[i - 1], "--") == 0)
			break ;
	}
	ft_sort(argv + i);
	ft_shorten_main(argc, arguments, i, argv);
	free(arguments);
	return (0);
}
