#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fsinged <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/19 13:49:20 by fsinged           #+#    #+#              #
#    Updated: 2019/07/24 11:46:48 by fsinged          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = fdf

FLAGS = -Wall -Wextra -Werror
# src
SRCS = validation.c reading.c main.c ft_list.c ft_error.c ft_atoi_base.c \
	image.c keys.c
OBJS = $(addprefix $(OBJDIR), $(SRCS:.c=.o))
HEADER = -I ./includes/

# libft
LIBDIR = ./libft/
LIB = $(addprefix $(LIBDIR), libft.a)
LIB_INC = -I $(LIBDIR)

# mlx
MLX = ./minilibx/
MLX_LIB = $(addprefix $(MLX), mlx.a)
MLX_INC = -I ./minilibx/
MLX_FILES = -L ./minilibx/ -l mlx -framework OpenGL -framework AppKit

# dirs
OBJDIR = ./OBJ/
SRCDIR = ./src/


all:obj $(LIB) $(MLX_LIB) $(NAME)

obj:
	@mkdir $(OBJDIR)

$(OBJDIR)%.o:$(SRCDIR)%.c
	@gcc $(FLAGS) $(MLX_INC) $(LIB_INC) $(HEADER) -o $@ -c $<

$(LIB):
	@make -C $(LIBDIR)

$(MLX_LIB):
	@make -C $(MLX)

$(NAME):$(OBJS)
	@gcc $(OBJS) $(MLX_FILES) $(LIB) -lm -o $(NAME)

clean:
	@rm -rf $(OBJDIR)
	@make fclean -C $(LIBDIR)
	@make clean -C $(MLX)

fclean:clean
	@rm -f $(NAME)

re:fclean all