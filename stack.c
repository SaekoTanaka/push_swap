/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka <stanaka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 16:02:18 by stanaka           #+#    #+#             */
/*   Updated: 2019/08/25 19:40:39 by stanaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int     stack_is_empty(t_stack *stack)
{
	if (stack->top == NULL)
		return (1);
	return (0);
}

t_stack    *stack_init(void)
{
	t_stack *stack;

	stack = malloc(sizeof(t_stack));
	stack->top = NULL;
	return (stack);
}

void    node_push(t_stack *stack, int data)
{
	t_node *new;

	new = malloc(sizeof(t_node));
	new->i = data;
	new->next = stack->top;
	stack->top = new;
}

int		node_pop(t_stack *stack)
{
	int		data;
	t_node	*tmp;

	data = stack->top->i;
	tmp = stack->top->next;
	free(stack->top);
	stack->top = tmp;
	return(data);
}

void	print_stack(t_stack *stack)
{
	t_node	*tmp;

	tmp = stack->top;
	while (tmp)
	{
		printf("%d\n", tmp->i);
		tmp = tmp->next;
	}
}

int		stack_order_check(t_stack *a, t_stack *b)
{
	t_node	*tmp;
	int		small_data;
	int		big_data;

	if (b->top != NULL)
		return (0);
	if (a->top == NULL || a->top->next == NULL)
		return (1);
	tmp = a->top;
	while (tmp->next)
	{
		small_data = tmp->i;
		tmp = tmp->next;
		big_data = tmp->i;
		if (small_data >= big_data)
			return (0);
	}
	return (1);
}