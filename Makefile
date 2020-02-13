# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdirect <mdirect@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/22 15:09:25 by mdirect           #+#    #+#              #
#    Updated: 2020/01/22 15:21:12 by mdirect          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
LIBSINC = -L./libft/ -L./minilibx_macos/
LIBFTPATH = ./libft/
MINILIBXPATH = ./minilibx_macos/
LIBS = -lft -lmlx
LIBSNAME = libft.a libmlx.a
INCLUDES = -I./libft/ -I./minilibx_macos/
HEADERS = ./fractol.h
SRCS = f_open_cl.c help_functions.c keyboard_control.c mouse_control.c\
	make_params.c main.c
OBJS = $(SRCS:.c=.o)
CC = gcc
FLAGS = -Wall -Wextra -Werror

.PHONY: clean fclean re all

all: $(NAME)

%.o: %.c $(HEADERS)
	$(CC) $(FLAGS) $(INCLUDES) -o $@ -c $<

$(NAME): $(OBJS)
	@$(MAKE) -C $(LIBFTPATH)
	@$(MAKE) -C $(MINILIBXPATH)
	@$(CC) $(FLAGS) -o $(NAME) $(OBJS) $(LIBSINC) $(LIBS) -framework OpenGL -framework AppKit -framework OpenCL

clean:
	$(MAKE) fclean -C $(LIBFTPATH)
	$(MAKE) clean -C $(MINILIBXPATH)
	/bin/rm -f $(OBJS)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all
