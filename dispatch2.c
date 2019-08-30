/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatch2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka <stanaka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 11:32:28 by stanaka           #+#    #+#             */
/*   Updated: 2019/08/29 20:53:58 by stanaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_pa(t_stack *a, t_stack *b)
{
	int		tmp;

	if (stack_is_empty(b))
		return ;
	tmp = node_pop(b);
	node_push(a, tmp);
	printf("pa\n");
}

void	move_pb(t_stack *a, t_stack *b)
{
	int		tmp;

	if (stack_is_empty(a))
		return ;
	tmp = node_pop(a);
	node_push(b, tmp);
	printf("pb\n");
}

void	m_pa(t_stack *a, t_stack *b, int i)
{
	int	n;

	n = 0;
	while (n < i)
	{
		move_pa(a, b);
		n++;
	}
}

void	m_pb(t_stack *a, t_stack *b, int i)
{
	int	n;

	n = 0;
	while (n < i)
	{
		move_rrb(a, b);
		n++;
	}
}
