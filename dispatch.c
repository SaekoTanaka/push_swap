/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatch.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka <stanaka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 10:43:52 by stanaka           #+#    #+#             */
/*   Updated: 2019/08/18 20:24:06 by stanaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    move_sa(t_stack *stack)
{
	int top_tmp;
	int second_tmp;

	if (stack->top->next == NULL)
		return ;
	top_tmp = node_pop(stack);
	second_tmp = node_pop(stack);
	node_push(stack, top_tmp);
	node_push(stack, second_tmp);
}

void    move_sb(t_stack *stack)
{
	int top_tmp;
	int second_tmp;

	if (stack->top->next == NULL || stack->top == NULL)
		return ;
	top_tmp = node_pop(stack);
	second_tmp = node_pop(stack);
	node_push(stack, top_tmp);
	node_push(stack, second_tmp);
}

void	move_ss(t_stack *a, t_stack *b)
{
	move_sa(a);
	move_sb(b);
}

void	move_pa(t_stack *a, t_stack *b)
{
	int		tmp;

	if (stack_is_empty(b))
		return ;
	tmp = node_pop(b);
	node_push(a, tmp);	
}

void	move_pb(t_stack *a, t_stack *b)
{
	int		tmp;

	if (stack_is_empty(a))
		return ;
	tmp = node_pop(a);
	node_push(b, tmp);	
}

void	move_ra(t_stack *stack)
{
	int tmp;
	t_node	*node;
	t_node	*new_node;

	if (stack_is_empty(stack))
		return ;
	tmp = node_pop(stack);
	node = stack->top->next;
	while(node->next)
		node = node->next;
	new_node = malloc(sizeof(t_node));
	new_node->i = tmp;
	new_node->next = NULL;
	node->next = new_node;
	stack->top = stack->top->next;
}

void	move_rb(t_stack *stack)
{
	int tmp;
	t_node	*node;
	t_node	*new_node;

	if (stack_is_empty(stack))
		return ;
	tmp = node_pop(stack);
	node = stack->top->next;
	while(node->next)
		node = node->next;
	new_node = malloc(sizeof(t_node));
	new_node->i = tmp;
	new_node->next = NULL;
	node->next = new_node;
}

void	move_rr(t_stack *a, t_stack *b)
{
	move_ra(a);
	move_rb(b);
}

void	move_rra(t_stack *stack)
{
	t_node	*node;
	int		tmp;

	if (stack_is_empty(stack))
		return ;
	node = stack->top;
	if (node->next && node->next->next)
	{
		while (node->next->next)
			node = node->next;
		tmp = node->next->i;
		free(node->next);
		node->next = NULL;
		node_push(stack, tmp);
	}
}

void	move_rrb(t_stack *stack)
{
	t_node	*node;
	int		tmp;

	if (stack_is_empty(stack))
		return ;
	node = stack->top;
	if (node->next && node->next->next)
	{
		while (node->next->next)
			node = node->next;
		tmp = node->next->i;
		free(node->next);
		node->next = NULL;
		node_push(stack, tmp);
	}
}

void	move_rrr(t_stack *a, t_stack *b)
{
	move_rra(a);
	move_rrb(b);
}