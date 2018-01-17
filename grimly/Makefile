# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: husui <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/11 10:04:33 by husui             #+#    #+#              #
#    Updated: 2018/01/17 15:26:31 by husui            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = grimly

all: $(NAME)

$(NAME):
	@gcc -c -Wall -Werror -Wextra libft/*.c -I libft/libft.h
	@ar -q libft/libft.a *.o
	@gcc -Wall -Wextra -Werror -Llibft -lft *.c -o grimly

clean:
	@rm -rf *.o *.a libft/*.a libft/*.o

fclean: clean
	@rm -rf grimly

re: fclean all
