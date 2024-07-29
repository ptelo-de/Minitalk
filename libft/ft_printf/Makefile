# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hepereir <hepereir@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/01 13:01:52 by hepereir          #+#    #+#              #
#    Updated: 2024/05/01 15:20:17 by hepereir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= libftprintf.a

SRC = ft_print_dec.c ft_print_hex.c ft_printf.c
OBJ = $(SRC:.c=.o)

CC				= cc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror

 all: $(NAME)

 %.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
 
$(NAME): $(OBJ)
	ar rsc $(NAME) $(OBJ)
 
clean:
	$(RM) $(OBJ)
 
fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re