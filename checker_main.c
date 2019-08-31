/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka <stanaka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 10:43:55 by stanaka           #+#    #+#             */
/*   Updated: 2019/08/30 20:03:24 by stanaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int ac, char **av)
{
	t_stack *a;
	t_stack	*b;
	
	a = stack_init();
	b = stack_init();
	if (!read_arg_make_stack(ac, av, a))
		return (0);
	if (read_cmd_move_node(a, b))
	{
		if (stack_order_check(a, b))
			print_ret(1);
		else
			print_ret(2);
	}
	else
		print_ret(0);
	return (0);
}

void	move_sa(t_stack *a, t_stack *b)
{
	t_node *tmp;

	if (!b || a->top == NULL || a->top->next == NULL)
		return ;
	tmp = a->top->next;
	a->top->next = a->top->next->next;
	tmp->next = a->top;
	a->top = tmp;
}

void	move_sb(t_stack *a, t_stack *b)
{
	t_node *tmp;

	if (!a || b->top == NULL || b->top->next == NULL)
		return ;
	tmp = b->top->next;
	b->top->next = b->top->next->next;
	tmp->next = b->top;
	b->top = tmp;
}

void	move_ss(t_stack *a, t_stack *b)
{
	t_node *tmp;

	if (!b || a->top == NULL || a->top->next == NULL)
		return ;
	tmp = a->top->next;
	a->top->next = a->top->next->next;
	tmp->next = a->top;
	a->top = tmp;
	if (!a || b->top == NULL || b->top->next == NULL)
		return ;
	tmp = b->top->next;
	b->top->next = b->top->next->next;
	tmp->next = b->top;
	b->top = tmp;
}
