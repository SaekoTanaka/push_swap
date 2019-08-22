/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatch.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka <stanaka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 10:43:52 by stanaka           #+#    #+#             */
/*   Updated: 2019/08/20 13:01:18 by stanaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    move_sa(t_stack *a, t_stack *b)
{
	t_node *tmp;

	if (!b || a->top == NULL || a->top->next == NULL)
		return ;
	tmp = a->top->next;
	a->top->next = a->top->next->next;
	tmp->next = a->top;
	a->top = tmp;
}

void    move_sb(t_stack *a, t_stack *b)
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
	move_sa(a, b);
	move_sb(a, b);
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

void	move_ra(t_stack *a, t_stack *b)
{
	t_node	*tmp;

	if (!b || a->top == NULL || a->top->next == NULL)
		return ;
	tmp = a->top;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = a->top;
	tmp = a->top->next; //tmp point 1
	a->top->next = NULL;
	a->top = tmp;
}

void	move_rb(t_stack *a, t_stack *b)
{
	t_node	*tmp;

	if (!a || b->top == NULL || b->top->next == NULL)
		return ;
	tmp = b->top;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = b->top;
	tmp = b->top->next;
	b->top->next = NULL;
	b->top = tmp;
}

void	move_rr(t_stack *a, t_stack *b)
{
	move_ra(a, b);
	move_rb(a, b);
}

void	move_rra(t_stack *a, t_stack *b)
{
	//t_node	*node;
	//int		tmp;
	t_node	*tmp;

	if (!b || a->top == NULL || a->top->next == NULL)
		return ;
	if (a->top->next->next == NULL) // 2 nodes
		move_sa(a, b);
	else
	{
		tmp = a->top;
		while (tmp->next->next)
			tmp = tmp->next;
		tmp->next->next = a->top;
		a->top = tmp->next;
		tmp->next = NULL;
	}
}
	
	
	//node = stack->top;
	//if (node->next && node->next->next)
	//{
	//	while (node->next->next)
	//		node = node->next;
	//	tmp = node->next->i;
	//	free(node->next);
	//	node->next = NULL;
	//	node_push(stack, tmp);
	//}


void	move_rrb(t_stack *a, t_stack *b)
{
	t_node	*tmp;

	if (!a || b->top == NULL || b->top->next == NULL)
		return ;
	if (b->top->next->next == NULL) // 2 nodes
		move_sb(a, b);
	else
	{
		tmp = b->top;
		while (tmp->next->next)
			tmp = tmp->next;
		tmp->next->next = b->top;
		b->top = tmp->next;
		tmp->next = NULL;
	}
}

void	move_rrr(t_stack *a, t_stack *b)
{
	move_rra(a, b);
	move_rrb(a, b);
}