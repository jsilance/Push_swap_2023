# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jusilanc <jusilanc@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/11 21:01:16 by jusilanc          #+#    #+#              #
#    Updated: 2023/04/24 13:24:34 by jusilanc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

FT_PRINTF = ft_printf

SRCS = main.c ft_pnlist_init.c ft_order_check.c ft_quick_sort.c ft_order_instr.c ft_pre_sort.c

SRC = $(addprefix srcs/, $(SRCS))

CFLAGS = -Wall -Wextra -I includes/ -I ${FT_PRINTF}/includes/

LDFLAGS = ${FT_PRINTF}/libftprintf.a

OBJ = ${SRC:.c=.o}

${NAME}: ft_printf ${OBJ}
		@cc ${CFLAGS} ${OBJ} ${LDFLAGS} -o ${NAME}

all: ${NAME}

%.o: %.c
		@cc ${CFLAGS} -c $< -o ${<:.c=.o}

clean:
		@rm -rf ${OBJ}
		@make -C ${FT_PRINTF} clean

fclean: clean
		@rm -rf ${NAME}
		@make -C ${FT_PRINTF} fclean

re: fclean all
		@clear

ft_printf:
		@make -C ${FT_PRINTF} all

.PHONY: all re clean fclean ft_printf
