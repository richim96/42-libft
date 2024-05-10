# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rmei <rmei@student.42berlin.de>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/23 12:10:35 by rmei              #+#    #+#              #
#    Updated: 2024/05/10 11:26:46 by rmei             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#### -- VARIABLES -- ####

SRC = atoi bzero calloc isalnum isalpha isascii isdigit isprint itoa memchr \
	memcmp memcpy memmove memset putchar_fd putendl_fd putnbr_fd putstr_fd \
	split substr strchr strdup striteri strjoin strlcat strlcpy strlen strmapi \
	strncmp strnstr strrchr strtrim tolower toupper
SRC := $(addsuffix .c, $(addprefix ft_, $(SRC)))
OBJS = ${SRC:%.c=%.o}

SRC_BONUS = lstadd_back lstadd_front lstclear lstdelone lstiter lstlast lstmap \
			lstnew lstsize
SRC_BONUS := $(addsuffix _bonus.c, $(addprefix ft_, $(SRC_BONUS)))
OBJS_BONUS = $(SRC_BONUS:%.c=%.o)

NAME = libft.a

CPPFLAGS = -I.
CFLAGS = -Wall -Wextra -Werror

#### -- RULES -- ####
all: ${NAME}

# create archive
${NAME}: ${OBJS}
	 @ar rcs $@ $^

%.o: %.c
	@cc ${CPPFLAGS} ${CFLAGS} -o $@ -c $<

# update archive with bonus
bonus: $(OBJS_BONUS)
	@ar rcs $(NAME) $^

# remove all object files
clean:
	@rm -f ${OBJS} $(OBJS_BONUS)

# remove all object files and the archive
fclean: clean
	@rm -f ${NAME}

re: fclean all
