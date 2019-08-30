/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3_help.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka <stanaka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 22:03:08 by stanaka           #+#    #+#             */
/*   Updated: 2019/08/29 20:59:25 by stanaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	case1(t_data *data)
{
	move_ra(data->a, data->b);
	move_sa(data->a, data->b);
	move_rra(data->a, data->b);
}

void	case2(t_data *data)
{
	move_sa(data->a, data->b);
}

void	case3(t_data *data)
{
	move_ra(data->a, data->b);
	move_sa(data->a, data->b);
	move_ra(data->a, data->b);
	move_rra(data->a, data->b);
	move_rra(data->a, data->b);
	move_sa(data->a, data->b);
}

void	case4(t_data *data)
{
	move_sa(data->a, data->b);
	move_ra(data->a, data->b);
	move_sa(data->a, data->b);
	move_rra(data->a, data->b);
}

void	case5(t_data *data)
{
	move_sa(data->a, data->b);
	move_ra(data->a, data->b);
	move_sa(data->a, data->b);
	move_rra(data->a, data->b);
	move_sa(data->a, data->b);
}
