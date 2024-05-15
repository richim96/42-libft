# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rmei <rmei@student.42berlin.de>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/10 12:18:26 by rmei              #+#    #+#              #
#    Updated: 2024/05/13 15:46:13 by rmei             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#### -- VARIABLES -- ####
SRC = ft_printf.c
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
	cd libft && make
	cc $(CPPFLAGS) $(CFLAGS) -c -o $@ $<

# remove all object files
clean:
	cd libft && make clean
	rm -f $(OBJS)

# remove all object files and the archive
fclean:
	cd libft && make fclean
	rm -f $(OBJS)
	rm -f $(NAME)

re: fclean all
