/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka <stanaka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 09:13:30 by stanaka           #+#    #+#             */
/*   Updated: 2019/08/30 09:16:34 by stanaka          ###   ########.fr       */
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
	tmp = a->top->next;
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
	t_node	*tmp;

	if (!b || a->top == NULL || a->top->next == NULL)
		return ;
	tmp = a->top;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = a->top;
	tmp = a->top->next;
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
}
