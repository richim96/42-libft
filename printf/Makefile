# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rmei <rmei@student.42berlin.de>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/10 12:18:26 by rmei              #+#    #+#              #
#    Updated: 2024/05/17 15:29:15 by rmei             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#### -- VARIABLES -- ####
SRC = ft_printf.c ft_putargs.c
OBJS = $(SRC:%.c=%.o)

NAME = libftprintf.a

CPPFLAGS = -I./libft
CFLAGS = -Wall -Werror -Wextra

#### -- RULES -- ####
all: ${NAME}

# create archive
${NAME}: ${OBJS}
	ar -rcs $@ $^

%.o: %.c
	cc $(CPPFLAGS) $(CFLAGS) -c -o $@ $<

# remove all object files
clean:
	rm -f ${OBJS}

# remove all object files and the archive
fclean: clean
	rm -f ${NAME}

re: fclean all
