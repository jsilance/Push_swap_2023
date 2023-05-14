# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jusilanc <jusilanc@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/10 17:35:48 by jusilanc          #+#    #+#              #
#    Updated: 2023/05/14 16:10:45 by jusilanc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
FT_PRINTF = ft_printf

SRCS = main.c ft_pnlist_init.c ft_order_check.c ft_pnlist_utils.c ft_order_instr.c ft_pre_sort.c \
		ft_gestion_error.c ft_other_sorter.c \

SRC = $(addprefix srcs/, $(SRCS))

CFLAGS = -Wall -Wextra -Werror -I includes/ -I ${FT_PRINTF}/includes/

LDFLAGS = ${FT_PRINTF}/libftprintf.a

OBJ = ${SRC:.c=.o}

all: ${NAME}

${NAME}: ${OBJ} | ${FT_PRINTF}/libftprintf.a
		cc ${CFLAGS} ${OBJ} -o ${NAME} ${LDFLAGS}

${FT_PRINTF}/libftprintf.a:
		make -C ${FT_PRINTF}

%.o: srcs/%.c | includes/
		cc ${CFLAGS} -MMD -MP -c $< -o $@

-include $(OBJ:.o=.d)

clean:
		rm -rf ${OBJ} ${OBJ:.o=.d}
		make -C ${FT_PRINTF} clean

fclean: clean
		rm -rf ${NAME}
		make -C ${FT_PRINTF} fclean

re: fclean all

.PHONY: all re clean fclean
