SOURCE = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c

OBJ = $(SOURCE:.c=.o)

NAME = libft.a

all:
	cc -Wall -Wextra -Werror -c $(SOURCE)
	ar -rcs $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

#Debug
dbg:
	cc debug/debug.c -I. -L. -lft -o dbg

dclean:
	rm -f dbg

norm:
	norminette *.c *.h
