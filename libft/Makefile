# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rmei <rmei@student.42berlin.de>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/23 12:10:35 by rmei              #+#    #+#              #
#    Updated: 2024/05/04 20:27:35 by rmei             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#### -- VARIABLES -- ####
SRC = $(addsuffix .c, $(addprefix ft_, atoi bzero calloc isalnum isalpha isascii isdigit isprint itoa memchr memcmp memcpy memmove memset putchar_fd putendl_fd putnbr_fd putstr_fd split substr strchr strdup striteri strjoin strlcat strlcpy strlen strmapi strncmp strnstr strrchr strtrim tolower toupper))

OBJS = ${SRC:%.c=%.o}

SRC_BONUS = $(addsuffix _bonus.c, $(addprefix ft_, lstadd_front lstnew))

OBJS_BONUS = $(SRC_BONUS:%.c=%.o)

NAME = libft.a

CPPFLAGS = -I.

CCFLAGS = -Wall -Wextra -Werror

#### -- RULES -- ####
all: ${NAME}

# create archive
${NAME}: ${OBJS}
	 @ar rcs $@ $^

$(OBJS): %.o: %.c
	@cc ${CPPFLAGS} ${CCFLAGS} -o $@ -c $<

# update archive with bonus
bonus: $(OBJS_BONUS)
	@ar rcs $(NAME) $^

$(OBJS_BONUS): %.o: %.c
	@cc $(CPPFLAGS) $(CCFLAGS) -o $@ -c $<

# remove all object files
clean:
	@rm -f ${OBJS} $(OBJS_BONUS)

# remove all object files and the archive
fclean: clean
	@rm -f ${NAME}

re: fclean all
