# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rmei <rmei@student.42berlin.de>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/23 12:10:35 by rmei              #+#    #+#              #
#    Updated: 2024/04/26 17:56:54 by rmei             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#### -- VARIABLES -- ####
SRC = $(addsuffix .c, $(addprefix ft_, atoi bzero calloc isalnum isalpha isascii isdigit isprint memchr memcmp memcpy memmove memset strchr strdup strlcat strlcpy strlen strncmp strnstr strrchr tolower toupper))

OBJS := ${SRC:%.c=%.o}

NAME = libft.a

CPPFLAGS = -I/.

CCFLAGS = -Wall -Wextra -Werror -g

#### -- RULES -- ####
all: ${NAME}

# create archive
${NAME}: ${OBJS}
	 @ar rcs $@ $^

# create object files
%.o: %.c
	@cc ${CPPFLAGS} ${CCFLAGS} -o $@ -c $<

# remove object files
clean:
	@rm -f ${OBJS}

# remove object files and archive
fclean: clean
	@rm -f ${NAME}

re: fclean all
