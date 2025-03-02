/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatch.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka <stanaka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 10:43:52 by stanaka           #+#    #+#             */
/*   Updated: 2019/08/30 09:11:49 by stanaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_sa(t_stack *a, t_stack *b)
{
	t_node *tmp;

	if (!b || a->top == NULL || a->top->next == NULL)
		return ;
	tmp = a->top->next;
	a->top->next = a->top->next->next;
	tmp->next = a->top;
	a->top = tmp;
	printf("sa\n");
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
	printf("sb\n");
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
	printf("ss\n");
}
