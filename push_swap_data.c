/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_data.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka <stanaka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/23 10:36:01 by stanaka           #+#    #+#             */
/*   Updated: 2019/08/29 21:17:05 by stanaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_data				*init_data(int ac)
{
	t_data			*data;

	data = malloc(sizeof(t_data));
	data->a = stack_init();
	data->b = stack_init();
	data->move_num = 0;
	return (data);
}

t_pivot_data		*init_p_data(void)
{
	t_pivot_data	*p_d;

	p_d = malloc(sizeof(t_pivot_data));
	p_d->ret = 0;
	p_d->pivot = malloc(sizeof(t_node));
	p_d->pivot->i = 0;
	p_d->pivot->next = NULL;
	return (p_d);
}
