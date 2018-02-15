/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frahaing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 15:02:06 by frahaing          #+#    #+#             */
/*   Updated: 2018/01/08 14:45:44 by frahaing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "../libft/libft.h"
# include <dirent.h>
# include <sys/stat.h>
# include <pwd.h>
# include <uuid/uuid.h>
# include <grp.h>
# include <sys/xattr.h>
# include <time.h>
# include <stdio.h>

# define FT_ISIFO(mode) ((mode & S_IFIFO) == S_IFIFO)
# define FT_ISCHR(mode) ((mode & S_IFCHR) == S_IFCHR)
# define FT_ISDIR(mode) ((mode & S_IFDIR) == S_IFDIR)
# define FT_ISBLK(mode) ((mode & S_IFBLK) == S_IFBLK)
# define FT_ISREG(mode) ((mode & S_IFREG) == S_IFREG)
# define FT_ISLNK(mode) ((mode & S_IFLNK) == S_IFLNK)
# define FT_ISSOCK(mode) ((mode & S_IFSOCK) == S_IFSOCK)
# define FT_ISWHT(mode) ((mode & S_IFWHT) == S_IFWHT)
# define FT_ISUID(mode) ((mode & S_ISUID) == S_ISUID)
# define FT_ISGID(mode) ((mode & S_ISGID) == S_ISGID)
# define FT_ISVTX(mode) ((mode & S_ISVTX) == S_ISVTX)
# define FT_IRWXU(mode) ((mode & S_IRWXU) == S_IRWXU)
# define FT_IRUSR(mode) ((mode & S_IRUSR) == S_IRUSR)
# define FT_IWUSR(mode) ((mode & S_IRUSR) == S_IRUSR)
# define FT_IXUSR(mode) ((mode & S_IXUSR) == S_IXUSR)
# define FT_IRWXG(mode) ((mode & S_IRWXG) == S_IRWXG)
# define FT_IRGRP(mode) ((mode & S_IRGRP) == S_IRGRP)
# define FT_IWGRP(mode) ((mode & S_IWGRP) == S_IWGRP)
# define FT_IXGRP(mode) ((mode & S_IXGRP) == S_IXGRP)
# define FT_IRWXO(mode) ((mode & S_IRWXO) == S_IRWXO)
# define FT_IROTH(mode) ((mode & S_IROTH) == S_IROTH)
# define FT_IWOTH(mode) ((mode & S_IWOTH) == S_IWOTH)
# define FT_IXOTH(mode) ((mode & S_IXOTH) == S_IXOTH)
# define FT_ISVTX(mode) ((mode & S_ISVTX) == S_ISVTX)
# define FT_ISGID(mode) ((mode & S_ISGID) == S_ISGID)
# define FT_ISUID(mode) ((mode & S_ISUID) == S_ISUID)

typedef struct	s_dir_info
{
	char				*mode;
	int					links;
	char				*user;
	char				*group;
	int					size;
	char				*month;
	char				*day;
	char				*time;
	char				*name;
	char				*full_path;
	char				*sym_path;
	int					block;
	struct s_dir_info	*next;
	struct s_dir_info	*prev;
}				t_dir_info;

t_dir_info		*ft_create_list(char *path);
t_dir_info		*new_elem(t_dir_info *prev, char *path, struct dirent *rep);
t_dir_info		*ft_sort_alpha(t_dir_info *list);
t_dir_info		*ft_sort_rev(t_dir_info	**list);
t_dir_info		*ft_sort_time(t_dir_info *list);
void			ft_sort_time_args(char *arguments, t_dir_info **list);
void			ft_sort_rev_args(t_dir_info **list, int start, int end);
t_dir_info		*ft_swap_elem(t_dir_info *elem1, t_dir_info *elem2);
void			ft_fill_mode(t_dir_info *dir_info, struct stat *buf);
void			ft_fill_time_day_month(t_dir_info *dir_info, struct stat *buf);
void			ft_fill_user_group(t_dir_info *dir_info);
void			ft_fill_links(t_dir_info *dir_info, struct stat *buf);
void			ft_fill_size(t_dir_info *dir_info, struct stat *buf);
void			ft_fill_sym(t_dir_info *dir_info);
void			ft_fill_block(t_dir_info *dir_info, struct stat *buf);
void			ft_print_mode(t_dir_info *list);
void			ft_print_all(t_dir_info *list, char *arguments);
void			ft_print_blocks(t_dir_info *list, int visible);
int				ft_fbd_arg(char *str);
void			del_list(t_dir_info *list);
t_dir_info		*shorten_ft_recursive(char *arguments, t_dir_info *list);
t_dir_info		*ft_fill(char *path);

#endif
