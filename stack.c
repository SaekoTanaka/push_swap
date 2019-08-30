/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka <stanaka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 16:02:18 by stanaka           #+#    #+#             */
/*   Updated: 2019/08/29 21:05:27 by stanaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			stack_is_empty(t_stack *stack)
{
	if (stack->top == NULL)
		return (1);
	return (0);
}

t_stack		*stack_init(void)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	stack->top = NULL;
	return (stack);
}

void		node_push(t_stack *stack, int data)
{
	t_node *new;

	new = malloc(sizeof(t_node));
	new->i = data;
	new->next = stack->top;
	stack->top = new;
}

int			node_pop(t_stack *stack)
{
	int		data;
	t_node	*tmp;

	data = stack->top->i;
	tmp = stack->top->next;
	free(stack->top);
	stack->top = tmp;
	return (data);
}
