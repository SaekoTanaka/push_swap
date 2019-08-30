/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test0824.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka <stanaka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 14:55:43 by stanaka           #+#    #+#             */
/*   Updated: 2019/08/29 16:22:14 by stanaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack		*stack_a_or_b(int a_or_b, t_data *data)
{
	t_stack *tmp;
	
	if (!a_or_b)
		tmp = data->a;
	else
		tmp = data->b;
		return (tmp);
}

//int     get_split_num(int n)
//{
//	int time;
//	int tmp;
//
//	time = 0;
//	while (power(time) <= n)
//		time++;
//	tmp = power(time - 2);
//	if (tmp == 1)
//		tmp++;
//	return (tmp);
//}

int	get_split_num(int n)
{
	return (n / 2);
}

void	b_sort(t_data *data, int i)
{
	t_node *b_bottom;
	int		n;
	
	n = 0;
	while (!stack_is_empty(data->b) && n < i && data->b->top->next)
	{
		b_bottom = data->b->top;
		while (b_bottom->next)
			b_bottom = b_bottom->next;
		if (data->b->top->i < b_bottom->i)
			m_rrb(data->a, data->b, 2);
		else
			m_pb(data->a, data->b, 2);
		b_bottom = data->b->top;
		while (b_bottom->next)
			b_bottom = b_bottom->next;
		while (data->b->top->next && b_bottom->i < data->b->top->i)
			move_pa(data->a, data->b);
		n++;
	}
	if (i > 4)
		move_pa(data->a, data->b);
}

void	sort_chunk(int i, t_data *data)
{
	t_node *b_top;
	
	if (i <= 3)
		return ;
	b_top = data->b->top;
	while (!stack_is_empty(data->a))
		move_pb(data->a, data->b);
	while (data->b->top->i < b_top->i)
		move_rb(data->a, data->b);
	if (i % 2)
		m_pa(data->a, data->b, 5);
	else
		m_pa(data->a, data->b, 4);
	b_sort(data, i);
}