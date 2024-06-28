# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rmei <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/25 20:57:11 by rmei              #+#    #+#              #
#    Updated: 2024/06/28 19:27:03 by rmei             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#### -- VARIABLES -- ####
SRC = wireframe.c
OBJS = $(SRC:%.c=%.o)
NAME = fdf

CPPFLAGS = -I./libft -I./minilibx
CFLAGS = -Wall -Werror -Wextra 
LDFLAGS = -L./libft -lft -L./minilibx -lmlx -lm -lX11 -lXext

#### -- RULES -- ####
all: $(NAME)

$(NAME): $(OBJS)
	make -sC libft
	make -sC minilibx
	cc $(OBJS) $(LDFLAGS) -o $(NAME)

%.o: %.c
	cc $(CPPFLAGS) $(CFLAGS) -c $< -o $@

clean:
	make clean -sC libft
	make clean -sC minilibx
	rm -f $(OBJS)

fclean: clean
	make fclean -sC libft
	make fclean -sC minilibx
	rm -f $(NAME)

re: fclean all
