CHECK = checker
P_S = push_swap

CHECK_SRC = get_next_line/get_next_line.c \
	dispatch.c check_main.c stack.c arg.c cmd.c \

P_S_SRC = \

FLAG = -Wall -Werror -Wextra -I push_swap.h

FA = -fsanitize=address

all: $(CHECK) $(P_S)

$(CHECK):
	make -C libft/ re
	gcc $(FLAG) $(CHECK_SRC) -Llibft -lft -o $(NAME)

$(P_S):


clean:
	make -C libft/ clean

fclean: clean
	make -C libft/ fclean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: all fclean clean re