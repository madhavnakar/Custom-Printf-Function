# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mnakar <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/22 20:14:02 by mnakar            #+#    #+#              #
#    Updated: 2018/07/28 14:49:23 by mnakar           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CFLAGS = -Wall -Wextra -Werror

FILES = ft_printf.c is.c parseopt.c putnumber.c additional_funcs.c handle/*.c

C_FILES = $(FILES) libft/*.c

LIBFT = libft/

OBJ = $(C_FILES:.c=.o)

all: $(NAME)

$(NAME) :
	@ make -C $(LIBFT)
	@ gcc $(CFLAGS) -c $(FILES)
	@ mv handle_* handle
	@ ar rc $(NAME) $(OBJ)
	@ ranlib $(NAME)

clean:
	@ make clean -C $(LIBFT)
	@ rm -f *.o
	@ rm -f handle/*.o

fclean: clean
	@ make fclean -C $(LIBFT)
	@ rm -f $(NAME)

re: fclean all

test: 
	@ gcc *.c libft/*.c handle/*.c
	@ ./a.out | cat -e

.PHONY: all clean fclean re
