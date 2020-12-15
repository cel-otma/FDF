# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cel-otma <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/04 10:26:05 by cel-otma          #+#    #+#              #
#    Updated: 2019/12/04 10:26:18 by cel-otma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Werror -Wextra

NAME = fdf

CC = gcc

SRC = check_file.c \
	  dess.c \
	  get_next_line.c \
	  main.c \
	  stock.c \
	  insial.c

OBJS = $(SRC:.c=.o)

MLX = /usr/local/lib/ -lmlx -framework OpenGL -framework AppKit

LIBFT = libft/libft.a

all : $(NAME)

$(NAME) : $(OBJS)
	@make -C libft
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -L $(MLX) -o $(NAME)

clean :
	@make clean -C libft
	@rm -rf $(OBJS)

fclean : clean
	@make fclean -C libft
	@rm -rf $(NAME)

re : fclean all