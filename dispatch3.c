/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatch3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka <stanaka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 11:33:49 by stanaka           #+#    #+#             */
/*   Updated: 2019/08/29 20:54:15 by stanaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_rra(t_stack *a, t_stack *b)
{
	t_node	*tmp;

	if (!b || a->top == NULL || a->top->next == NULL)
		return ;
	if (a->top->next->next == NULL)
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
	printf("rra\n");
}

void	move_rrb(t_stack *a, t_stack *b)
{
	t_node	*tmp;

	if (!a || b->top == NULL || b->top->next == NULL)
		return ;
	if (b->top->next->next == NULL)
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
	printf("rrb\n");
}

void	move_rrr(t_stack *a, t_stack *b)
{
	move_rra(a, b);
	move_rrb(a, b);
}

void	m_rrb(t_stack *a, t_stack *b, int i)
{
	int	n;

	n = 0;
	while (n < i)
	{
		move_rrb(a, b);
		n++;
	}
}
