CH = checker
P_S = push_swap

CHECK_SRC = get_next_line/get_next_line.c \
	dispatch.c dispatch1.c dispatch2.c dispatch3.c checker_main.c stack.c stack1.c arg.c cmd.c \

P_S_SRC = push_swap_data.c test0824.c sort_3.c sort_3_help.c test0827.c sort.c \
	get_next_line/get_next_line.c sort_3_1.c \
	dispatch.c dispatch1.c dispatch2.c dispatch3.c stack.c stack1.c arg.c cmd.c \

FLAG = -Wall -Werror -Wextra -I push_swap.h

FA = -fsanitize=address

all: $(P_S) $(CH)

$(CH):
	make -C libft/ re
	gcc $(FLAG) $(CHECK_SRC) -Llibft -lft -o $(CH)

$(P_S):
	make -C libft/ re
	gcc $(FLAG) $(P_S_SRC) -Llibft -lft -o $(P_S)

clean:
	make -C libft/ clean

fclean: clean
	make -C libft/ fclean
	/bin/rm -f $(P_S)
	/bin/rm -f $(CH)

re: fclean all

.PHONY: all fclean clean re