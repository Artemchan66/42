SOURCE = ft_printf.c ft_print_numeric.c

OBJ = $(SOURCE:.c=.o)

NAME = libftprintf.a

all:
	cc -Wall -Wextra -Werror -c $(SOURCE)
	ar -rcs $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

#Debug
dbg: all
	cc -g debug.c -I. -L. -lftprintf -o dbg

dclean: fclean
	rm -f dbg libprintf

norm:
	norminette *.c *.h

dre: fclean dclean all dbg
dall: all dbg

ghcpy:
	cp -fr ../ms0 ../../github/
