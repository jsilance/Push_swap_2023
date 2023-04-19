# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jusilanc <jusilanc@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/03 21:43:42 by jusilanc          #+#    #+#              #
#    Updated: 2023/04/11 21:49:04 by jusilanc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ../libft.a


SRC = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c \
		ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c \
		ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_calloc.c ft_strmapi.c ft_substr.c ft_strjoin.c \
		ft_strtrim.c ft_strdup.c ft_split.c ft_itoa.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c \
		ft_putnbr_fd.c ft_atoi.c \

BONUS = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c ft_lstadd_back_bonus.c \
		ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c \

BONUS_OBJ = ${BONUS:.c=.o}

FLAGS = -Wall -Wextra -Werror

OBJ = ${SRC:.c=.o}

${NAME}: ${OBJ}
		@ar rc ${NAME} ${OBJ}
		@ranlib ${NAME}

all: ${NAME}

%.o: %.c
		@cc ${FLAGS} -I ./ -c $< -o ${<:.c=.o}

clean:
		@rm -rf ${OBJ} ${BONUS_OBJ}

fclean: clean
		@rm -rf ${NAME}

re: fclean all

bonus: ${OBJ} ${BONUS_OBJ}
		@ar rc ${NAME} ${OBJ} ${BONUS_OBJ}
		@ranlib ${NAME}

.PHONY: all re clean fclean bonus
