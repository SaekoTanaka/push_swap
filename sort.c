/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka <stanaka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 22:05:11 by stanaka           #+#    #+#             */
/*   Updated: 2019/08/29 21:27:12 by stanaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_de(t_data *data)
{
	if (data->b->top->i < data->b->top->next->i)
		move_sb(data->a, data->b);
	move_pa(data->a, data->b);
	move_pa(data->a, data->b);
}

void	sort(int a_or_b, t_data *data)
{
	if (!a_or_b)
		sort_as(data);
	else
		sort_de(data);
}

void	sort_as(t_data *data)
{
	t_node *tmp;

	tmp = data->a->top;
	if (tmp->i > tmp->next->i && data->b->top->i < data->b->top->next->i)
		move_ss(data->a, data->b);
	else if (tmp->i > tmp->next->i)
		move_sa(data->a, data->b);
}
