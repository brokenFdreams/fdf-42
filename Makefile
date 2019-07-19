#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fsinged <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/19 13:49:20 by fsinged           #+#    #+#              #
#    Updated: 2019/07/19 14:13:31 by fsinged          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = fdf
FLAGS = -Wall -Wextra -Werror
SRCS_PATH = ./src/
SRCS_FILES = validation.c reading.c main.c ft_list.c ft_error.c ft_atoi_base.c
SRCS = $(addprefix $(SRCS_PATH), $(SRCS_FILES))
LIB_PATH = ./libft/
LIB = -L $(LIB_PATH)
HEADER = -I ./includes/fdf.h

all:$(NAME)

$(NAME):$(SRCS)
	@make -C $(LIB_PATH)
	@gcc $(HEADER) $(LIB) $(SRCS) -o $(NAME)

clean:
	@make fclean -C $(LIB_PATH)

fclean:clean
	@/bin/rm -f $(NAME)

re:fclean all