/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatch1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka <stanaka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 11:30:52 by stanaka           #+#    #+#             */
/*   Updated: 2019/08/29 16:26:08 by stanaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	printf("ra\n");
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
	printf("rb\n");
}

void	move_rr(t_stack *a, t_stack *b)
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

	if (!a || b->top == NULL || b->top->next == NULL)
		return ;
	tmp = b->top;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = b->top;
	tmp = b->top->next;
	b->top->next = NULL;
	b->top = tmp;
	printf("rr\n");
}