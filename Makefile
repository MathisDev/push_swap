CC		= gcc
CFLAGS	= -Wall -Werror -Wextra
NAME	= push_swap

SRC_PATH = src/

SRC		= main.c \
		input_check.c input_check_utils.c \
		initialization.c \
		stack.c \
		swap.c push.c rotate.c reverse_rotate.c \
		sort_tiny.c sort.c \
		position.c cost.c do_move.c \
		utils.c
SRCS	= $(addprefix $(SRC_PATH), $(SRC))
INCS	= -I ./includes/

all: $(OBJ_PATH) $(NAME) 

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(SRC)-o $(NAME)

clean:
	rm -rf $(OBJ_PATH)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
