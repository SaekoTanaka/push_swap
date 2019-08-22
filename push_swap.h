/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka <stanaka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 10:44:01 by stanaka           #+#    #+#             */
/*   Updated: 2019/08/21 17:27:41 by stanaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <string.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>

#include "libft/libft.h"
#include "get_next_line/get_next_line.h"

typedef struct		s_node
{
	int				i; //data usually void*
	struct s_node	*next;
}					t_node;

typedef struct	s_stack
{
	t_node		*top;
}				t_stack;

typedef void	t_move_func(t_stack *a, t_stack *b);
typedef struct	s_command_type
{
	char		*cmd;
	t_move_func	*move_cmd;
}				t_commmand_type;

typedef struct s_data
{
	t_stack *a;
	t_stack *b;
	int		a_n;
	int		b_n;
}				t_data;

typedef struct s_pivot_data
{
	int		ret;
	t_node	*pivot;
}				t_pivot_data;


//stack.c
int     stack_is_empty(t_stack *stack);
t_stack	*stack_init(void);
void    node_push(t_stack *stack, int data);
int		node_pop(t_stack *stack);
void	print_stack(t_stack *stack);
int		stack_order_check(t_stack *a, t_stack *b);

//main.c
void	print_ret(int i);

//cmd.c
void    read_check_cmd(t_stack *stack);
int	read_cmd_move_node(t_stack *a, t_stack *b);
int	cmd_check_move(char *buff, t_stack *a, t_stack *b);
//arg.c
int		str_is_digit(char *str);
void	make_stack(t_stack *stack, int data);
int		read_arg_make_stack(int ac, char **av, t_stack *stack);
int		ft_atoi2(char *str, int *data);
int		node_dup_check(int data, t_stack *stack);

//dispatch.c
void    move_sa(t_stack *a, t_stack *b);
void    move_sb(t_stack *a, t_stack *b);
void	move_ss(t_stack *a, t_stack *b);
void	move_pa(t_stack *a, t_stack *b);
void	move_pb(t_stack *a, t_stack *b);
void	move_ra(t_stack *a, t_stack *b);
void	move_rb(t_stack *a, t_stack *b);
void	move_rr(t_stack *a, t_stack *b);
void	move_rra(t_stack *a, t_stack *b);
void	move_rrb(t_stack *a, t_stack *b);
void	move_rrr(t_stack *a, t_stack *b);
#endif