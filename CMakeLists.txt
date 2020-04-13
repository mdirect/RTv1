cmake_minimum_required(VERSION 3.12.3)
project(RTv1 C)

set(CMAKE_C_STANDARD 11)

include_directories(.)
include_directories(minilibx_macos libft)

find_package(OpenCL REQUIRED)

add_library(libmlx STATIC
        minilibx_macos/mlx_shaders.c
        minilibx_macos/mlx_new_window.m
        minilibx_macos/mlx_init_loop.m
        minilibx_macos/mlx_new_image.m
        minilibx_macos/mlx_xpm.c
        minilibx_macos/mlx_int_str_to_wordtab.c)

add_library(libft STATIC
        libft/ft_atoi.c
        libft/ft_bzero.c
        libft/ft_isalnum.c
        libft/ft_isalpha.c
        libft/ft_isascii.c
        libft/ft_isdigit.c
        libft/ft_isprint.c
        libft/ft_itoa.c
        libft/ft_lenint.c
        libft/ft_lstadd.c
        libft/ft_lstbackadd.c
        libft/ft_lstdel.c
        libft/ft_lstdelone.c
        libft/ft_lstiter.c
        libft/ft_lstmap.c
        libft/ft_lstnew.c
        libft/ft_max.c
        libft/ft_memalloc.c
        libft/ft_memccpy.c
        libft/ft_memchr.c
        libft/ft_memcmp.c
        libft/ft_memcpy.c
        libft/ft_memdel.c
        libft/ft_memmove.c
        libft/ft_memset.c
        libft/ft_min.c
        libft/ft_putchar.c
        libft/ft_putchar_fd.c
        libft/ft_putendl.c
        libft/ft_putendl_fd.c
        libft/ft_putnbr.c
        libft/ft_putnbr_fd.c
        libft/ft_putstr.c
        libft/ft_putstr_fd.c
        libft/ft_strcat.c
        libft/ft_strchr.c
        libft/ft_strclr.c
        libft/ft_strcmp.c
        libft/ft_strcpy.c
        libft/ft_strdel.c
        libft/ft_strdup.c
        libft/ft_strequ.c
        libft/ft_striter.c
        libft/ft_striteri.c
        libft/ft_strjoin.c
        libft/ft_strjoinfree.c
        libft/ft_strlcat.c
        libft/ft_strlen.c
        libft/ft_strmap.c
        libft/ft_strmapi.c
        libft/ft_strncat.c
        libft/ft_strncmp.c
        libft/ft_strncpy.c
        libft/ft_strnequ.c
        libft/ft_strnew.c
        libft/ft_strnstr.c
        libft/ft_strrchr.c
        libft/ft_strrev.c
        libft/ft_strsplit.c
        libft/ft_strstr.c
        libft/ft_strsub.c
        libft/ft_strtrim.c
        libft/ft_tolower.c
        libft/ft_toupper.c
        libft/get_next_line.c
        libft/libft.h)

add_compile_options (-Wall -Werror -Wextra -g)

add_executable(RTv1 rt.h scene/scene.h
        main.c keyboard_control.c
        help_functions.c draw.c figures.c vectors.c hit_figures.c
        rotate.c normal.c
        scene/scene1.c scene/scene2.c scene/scene3.c scene/scene4.c
        scene/scene5.c)

target_link_libraries(RTv1 libmlx libft "-framework OpenGL" "-framework AppKit" OpenCL::OpenCL)
