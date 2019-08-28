NAME = checker
P_S = push_swap

CHECK_SRC = get_next_line/get_next_line.c \
	dispatch.c checker_main.c stack.c arg.c cmd.c \

P_S_SRC = push_swap_main.c push_swap_data.c push_swap_move.c \
	pushswap_test.c test0824.c sort_3.c test0827.c \

FLAG = -Wall -Werror -Wextra -I push_swap.h

FA = -fsanitize=address

all: $(NAME)

$(NAME):
	make -C libft/ re
	gcc $(FLAG) $(CHECK_SRC) $(P_S_SRC) -Llibft -lft -o $(NAME)

clean:
	make -C libft/ clean

fclean: clean
	make -C libft/ fclean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: all fclean clean re