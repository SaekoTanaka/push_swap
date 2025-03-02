/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka <stanaka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 10:44:01 by stanaka           #+#    #+#             */
/*   Updated: 2019/08/30 19:34:59 by stanaka          ###   ########.fr       */
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
	int				i;
	struct s_node	*next;
}					t_node;

typedef struct		s_stack
{
	t_node			*top;
}					t_stack;

typedef void	t_move_func(t_stack *a, t_stack *b);
typedef struct		s_command_type
{
	char			*cmd;
	t_move_func		*move_cmd;
}					t_commmand_type;

typedef struct 		s_data
{
	t_stack			*a;
	t_stack			*b;
	int				move_num;
}					t_data;

typedef struct 		s_pivot_data
{
	int				ret;
	t_node			*pivot;
}					t_pivot_data;


int					stack_is_empty(t_stack *stack);
t_stack				*stack_init(void);
void				node_push(t_stack *stack, int data);
int					node_pop(t_stack *stack);
void				print_stack(t_stack *stack);
int					stack_order_check(t_stack *a, t_stack *b);
void				print_ret(int i);
void    			read_check_cmd(t_stack *stack);
int					read_cmd_move_node(t_stack *a, t_stack *b);
int					cmd_check_move(char *buff, t_stack *a, t_stack *b);
int					str_is_digit(char **str);
int					make_stack(t_stack *stack, int arr);
int					read_arg_make_stack(int ac, char **av, t_stack *stack);
int					ft_atoi2(char **str, t_stack *stack);
int					node_dup_check(int data, t_stack *stack);
void    			move_sa(t_stack *a, t_stack *b);
void    			move_sb(t_stack *a, t_stack *b);
void				move_ss(t_stack *a, t_stack *b);
void				move_pa(t_stack *a, t_stack *b);
void				move_pb(t_stack *a, t_stack *b);
void				move_ra(t_stack *a, t_stack *b);
void				move_rb(t_stack *a, t_stack *b);
void				move_rr(t_stack *a, t_stack *b);
void				move_rra(t_stack *a, t_stack *b);
void				move_rrb(t_stack *a, t_stack *b);
void				move_rrr(t_stack *a, t_stack *b);
void				move_half_1(t_data *data, t_pivot_data *p_d);
void				move_half_2(t_data *data, t_pivot_data *p_d);
void				move_half(t_data *data, t_pivot_data *p_d);

typedef	void		move_func(t_stack *a, t_stack *b);
typedef struct		s_move_stack{
	int				a_or_b;
	move_func		*move_func1;
	move_func		*move_func2;
	move_func		*move_func3;
}					t_move_stack;

t_data    			*init_data(void);
t_pivot_data		*init_p_data(void);
typedef void		case_3(t_data *data);
typedef struct 		s_3_sort_case{
	int				i;
	case_3			*c;
}					t_3_sort_case;

t_stack				*stack_a_or_b(int a_or_b, t_data *data);
void				sort_chunk(int i, t_data *data);
void				move_node(int n, int move_num, int a_or_b, t_data *data, t_pivot_data *p_d);
void				find_pivot(int n, int move_num, int a_or_b, t_data *data, t_pivot_data *p_d);
void				sort(int a_or_b, t_data *data);
t_stack				*stack_a_or_b(int a_or_b, t_data *data);
int					power(int time);
void				sort_as(t_data *data);
void				sort_de(t_data *data);
void				sort_3(int a_or_b, t_data *data);
void    			case0(t_data *data);
void    			case1(t_data *data);
void    			case2(t_data *data);
void    			case3(t_data *data);
void    			case4(t_data *data);
void    			case5(t_data *data);
void    			case6(t_data *data);
void    			case7(t_data *data);
void    			case8(t_data *data);
void    			case9(t_data *data);
void    			case10(t_data *data);
void    			case11(t_data *data);
void				split1(int a, int b, t_data *data, t_pivot_data *p_d);
void				find_p(int n, int a_or_b, t_data *data, t_pivot_data *p_d);
void				m_node(int n, int a_or_b, t_data *data, t_pivot_data *p_d);
void				m_pa(t_stack *a, t_stack *b, int i);
void				m_pb(t_stack *a, t_stack *b, int i);
void				m_rrb(t_stack *a, t_stack *b, int i);

#endif