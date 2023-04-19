# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jusilanc <jusilanc@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/09 02:09:47 by jusilanc          #+#    #+#              #
#    Updated: 2023/04/11 21:48:43 by jusilanc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS = ft_printf.c ft_utils.c ft_print_hex.c ft_pointers.c ft_print_numbers.c

SRC = $(addprefix srcs/, $(SRCS))

FLAGS = -Wall -Wextra -Werror

OBJ = ${SRC:.c=.o}

${NAME}: libft ${OBJ}
		@ar -rcs ${NAME} ${OBJ}
		@ranlib ${NAME}

all: ${NAME}

%.o: %.c
		@gcc ${FLAGS} -g -I includes/ -c $< -o ${<:.c=.o}

clean:
		@rm -rf ${OBJ}
		@make -C libft clean

fclean: clean
		@rm -rf ${NAME}
		@make -C libft fclean
	
libft:
		@make -C libft bonus

re: fclean all

.PHONY: all re clean fclean libft
