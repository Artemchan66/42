SOURCE = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_toupper.c \
ft_tolower.c ft_strchr.c ft_strrchr.c ft_strlcpy.c ft_strlcat.c ft_strncmp.c \
ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c

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

dclean: fclean
	rm -f dbg

norm:
	norminette *.c *.h

dre: fclean dclean all dbg
dall: all dbg

ghcpy:
	cp -fr ../ms0 ../../github/
