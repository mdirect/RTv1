# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdirect <mdirect@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/22 15:09:25 by mdirect           #+#    #+#              #
#    Updated: 2020/06/08 14:21:07 by estel            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = RTv1
LIBSINC = -L./libft/ -L./minilibx_macos/
LIBFTPATH = ./libft/
MINILIBXPATH = ./minilibx_macos/
LIBS = -lft -lmlx
LIBSNAME = libft.a libmlx.a
INCLUDES = -I./libft/ -I./minilibx_macos/ -I./inc/
HEADERS = ./inc/rt.h ./inc/keys.h
SRCS = ./src/main.c ./src/keyboard_control.c ./src/help_functions.c src/draw.c \
        ./src/figures.c ./src/vectors.c ./src/hit_figures.c ./src/rotate.c \
        ./src/normal.c ./src/threads.c ./scene/scene5.c
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
	@$(CC) $(FLAGS) -o $(NAME) $(OBJS) $(LIBSINC) $(LIBS)

clean:
	$(MAKE) fclean -C $(LIBFTPATH)
	$(MAKE) clean -C $(MINILIBXPATH)
	/bin/rm -f $(OBJS)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all
