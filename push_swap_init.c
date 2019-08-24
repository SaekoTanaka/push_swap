/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka <stanaka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/23 10:36:01 by stanaka           #+#    #+#             */
/*   Updated: 2019/08/23 19:05:02 by stanaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    init_data(t_data *data, int ac)
{
	data->a = stack_init();
	data->b = stack_init();
	data->a_n = ac - 1;
	data->b_n = 0;
}

void	init_p_data(t_pivot_data *p_d)
{
	p_d->ret = 0;
	p_d->pivot = malloc(sizeof(t_node));
	p_d->pivot->i = 0;
	p_d->pivot->next = NULL;
	p_d->small = 0;
}