SOURCE_DIR = ./src
SOURCE = $(SOURCE_DIR)/push_swap.c

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

INCLUDES = -I$(LIBFT_DIR)

FLAGS = -Wall -Wextra -Werror

NAME = push_swap

ARGS = 1 2 3

ps:
	cc $(FLAGS) $(SOURCE) $(INCLUDES) $(LIBFT) -o $(NAME)

psd:
	cc -g $(SOURCE) $(INCLUDES) $(LIBFT) -o $(NAME)

val:
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) $(ARGS)
