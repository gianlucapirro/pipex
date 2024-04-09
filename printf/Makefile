# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: gpirro <gpirro@student.42.fr>                +#+                      #
#                                                    +#+                       #
#    Created: 2021/10/22 14:28:23 by gpirro        #+#    #+#                  #
#    Updated: 2022/02/28 15:32:57 by gpirro        ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

SRCS =	conversions/int_to_hex.c\
		conversions/void_to_hex.c\
		srcs/ft_printf.c\
		tools/ft_putchar.c\
		tools/ft_putnbr.c\
		tools/ft_putnbru.c\
		tools/ft_putstr.c\
		tools/ft_rev_int_tab.c\
		tools/ft_strlowcase.c\
		tools/ft_calloc.c\
		tools/ft_memset.c
	
OBJS =	int_to_hex.o\
		void_to_hex.o\
		ft_printf.o\
		ft_putchar.o\
		ft_putnbr.o\
		ft_putnbru.o\
		ft_putstr.o\
		ft_rev_int_tab.o\
		ft_strlowcase.o\
		ft_calloc.o\
		ft_memset.o

NAME = libftprintf.a

${NAME}:
	gcc -Wall -Wextra -Werror -c ${SRCS}
	ar rc ${NAME} ${OBJS}

all: ${NAME}

clean:
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re .c.o norm