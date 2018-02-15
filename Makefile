# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: frahaing <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/12 15:12:16 by frahaing          #+#    #+#              #
#    Updated: 2018/01/23 17:10:46 by frahaing         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		ft_ls

SRC =		srcs/fill/ft_fill_mode.c \
			srcs/fill/ft_fill_time_day_month.c \
			srcs/fill/ft_fill_user_group.c \
			srcs/fill/ft_fill_links.c \
			srcs/fill/ft_fill_size.c \
			srcs/fill/ft_fill_sym.c \
			srcs/fill/ft_fill_block.c \
			srcs/ft_create_list.c \
			srcs/new_elem.c \
			srcs/ft_swap_elem.c \
			srcs/ft_fbd_arg.c \
			srcs/ft_fill.c \
			srcs/ft_shorten_recursive.c \
			srcs/sort/ft_sort_alpha.c \
			srcs/sort/ft_sort_rev.c \
			srcs/sort/ft_sort_time.c \
			srcs/print/ft_print_all.c \
			srcs/print/ft_print_blocks.c \

OBJ =		$(SRC:.c=.o)

FLAG =		-Wall -Werror -Wextra -O3

INC =		includes/

MAIN =		srcs/main.c

all :		$(NAME)

$(NAME) : $(OBJ)
			@$(MAKE) -C libft/ all
			@gcc -o ft_ls $(FLAG) $(MAIN) $(SRC) -I $(INC) libft/libft.a

%.o: %.c
			@gcc -c $< -o $@ $(FLAG)

clean :
			@rm -f $(OBJ)
			@$(MAKE) -C libft/ clean

fclean :	clean
			@rm -f $(NAME)
			@$(MAKE) -C libft/ fclean

re :		fclean all
