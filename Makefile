NAME	=	pipex
VPATH	=	./input/ ./obj/
SRC		=	pipex.c\
			input.c
OBJS	=	$(SRC:.c=.o)
OBJ_DIR	=	./obj/
INC_DIR	=	./includes/
CFLAGS	=	-Wall -Wextra -Werror -I$(INC_DIR)
CC		=	gcc
LIBFT	=	libft/libft.a

all		:	$(NAME)

$(NAME): $(OBJS) $(LIBFT)
	mkdir -p $(OBJ_DIR)
	mv *.o $(OBJ_DIR)
	$(CC) $(CFLAGS) -o $(NAME) $(LIBFT) $(addprefix $(OBJ_DIR), $(OBJS))

$(LIBFT):
	make -C libft

clean:
	rm -f $(addprefix $(OBJ_DIR), $(OBJS))
	make clean -C libft

fclean: clean
	rm -rf $(NAME) $(LIBFT) $(OBJ_DIR)

re: fclean all

.PHONY: all clean fclean re