/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka <stanaka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 21:02:55 by stanaka           #+#    #+#             */
/*   Updated: 2019/08/30 09:28:10 by stanaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_stack *stack)
{
	t_node	*tmp;

	tmp = stack->top;
	while (tmp)
	{
		printf("%d ", tmp->i);
		tmp = tmp->next;
	}
	printf("\n");
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

int			power(int time)
{
	int		n;

	n = 1;
	while (time > 0)
	{
		n *= 2;
		time--;
	}
	return (n);
}

t_stack		*stack_a_or_b(int a_or_b, t_data *data)
{
	t_stack	*tmp;

	if (!a_or_b)
		tmp = data->a;
	else
		tmp = data->b;
	return (tmp);
}
