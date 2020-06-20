# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hdean <hdean@student.21-school.ru>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/22 15:09:25 by mdirect           #+#    #+#              #
#    Updated: 2020/06/20 19:06:46 by hdean            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= RTv1

UNAME_OS 	= $(shell uname -s)

SRC_DIR		= ./src/
#BUILD_DIR	= ./build/

LIBSINC 	= -L./libft/ -L./minilibx_macos/
LIBFTPATH 	= ./libft/
MINILIBXPATH 	= ./minilibx_macos/
LIBS 		= -lft -lmlx
LIBSNAME 	= libft.a libmlx.a

INCLUDES 	= -I./libft/ -I./minilibx_macos/ -I./inc/

ifeq ($(UNAME_OS),Linux)
	MINILIBXPATH	= ./minilibx/
	LIBS 		= -lm -lXext -lX11 -lpthread
	INCLUDES	= -I ./libft/ -I ./minilibx/ -I ./inc/
	LIBSINC		= -L ./libft/ -lft -L ./minilibx/ -lmlx
endif

HEADERS 	= ./inc/rt.h ./inc/keys.h

SRCS_LIST 	=	main.c					keyboard_control.c  \
		  		help_functions.c 		draw.c \
        		figures.c				vectors.c \
				hit_figures.c 			rotate.c \
        		normal.c 				threads.c \
		  		parse_scene.c			read.c \
				read_utils.c

SRCS		= $(addprefix $(SRC_DIR), $(SRCS_LIST))
OBJS		= $(SRCS:.c=.o)
#OBJS		= $(addprefix $(BUILD_DIR, $(SRCS:.c=.o))

CC 			= gcc

FLAGS 		= -Wall -Wextra -Werror

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
