NAME	=	pipex
SRC		=	pipex.c\
			input/input.c\
			utils/utils.c\
			utils/ft_split_first.c\
			utils/ft_calloc.c utils/ft_isalpha.c utils/ft_isprint.c utils/ft_memcmp.c utils/ft_memset.c utils/ft_putnbr_fd.c utils/ft_strchr.c utils/ft_strjoin.c utils/ft_strlen.c utils/ft_strnstr.c utils/ft_substr.c utils/ft_atoi.c utils/ft_get2dlength.c utils/ft_isascii.c utils/ft_itoa.c utils/ft_memcpy.c utils/ft_putchar_fd.c utils/ft_putstr_fd.c utils/ft_strdup.c utils/ft_strlcat.c utils/ft_strmapi.c utils/ft_strrchr.c utils/ft_tolower.c utils/ft_bzero.c utils/ft_isalnum.c utils/ft_isdigit.c utils/ft_memchr.c utils/ft_memmove.c utils/ft_putendl_fd.c utils/ft_split.c utils/ft_striteri.c utils/ft_strlcpy.c utils/ft_strncmp.c utils/ft_strtrim.c utils/ft_toupper.c
OBJS	=	$(SRC:.c=.o)
CFLAGS	=	-Wall -Wextra -Werror
CC		=	gcc
PRINTF	=	printf/libftprintf.a

all: $(NAME)

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}: ${OBJS} ${PRINTF}
	${CC} ${CFLAGS} ${OBJS} ${PRINTF} -o ${NAME} 

$(PRINTF):
	make -C printf

clean:
	rm -f $(OBJS)
	make clean -C printf

fclean: clean
	rm -rf $(NAME) $(PRINTF)

re: fclean all

.PHONY: all clean fclean re