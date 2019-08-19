NAME = checker

SRC = dispatch.c main.c stack.c arg.c cmd.c

FLAG = -Wall -Werror -Wextra -I push_swap.h

FA = -fsanitize=address

all: $(NAME)

$(NAME):
	make -C libft/ re
	gcc $(FLAG) $(SRC) -Llibft -lft -o $(NAME)

clean:
	make -C libft/ clean

fclean: clean
	make -C libft/ fclean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: all fclean clean re