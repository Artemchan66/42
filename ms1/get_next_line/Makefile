SOURCE = get_next_line.c get_next_line_utils.c

OBJ = $(SOURCE:.c=.o)

NAME = libgetnextline.a

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
	cc -g debug.c -I. -L. -lgetnextline -o dbg

dclean: fclean
	rm -f dbg libgetnextline

norm:
	norminette *.c *.h

dre: fclean dclean all dbg
dall: all dbg

ghcpy:
	cp -fr ../ms0 ../../github/
