/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka <stanaka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 14:07:22 by stanaka           #+#    #+#             */
/*   Updated: 2019/08/29 15:52:33 by stanaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	case6(t_data *data)
{
	move_pa(data->a, data->b);
	move_ra(data->a, data->b);
	move_sb(data->a, data->b);
	move_pa(data->a, data->b);
	move_pa(data->a, data->b);
	move_rra(data->a, data->b);
}

void	case7(t_data *data)
{
	move_sb(data->a, data->b);
	move_pa(data->a, data->b);
	move_sb(data->a, data->b);
	move_pa(data->a, data->b);
	move_pa(data->a, data->b);
}

void	case8(t_data *data)
{
	move_rb(data->a, data->b);
	move_sb(data->a, data->b);
	move_pa(data->a, data->b);
	move_rrb(data->a, data->b);
	move_pa(data->a, data->b);
	move_pa(data->a, data->b);
}

void	case9(t_data *data)
{
	move_sb(data->a, data->b);
	move_pa(data->a, data->b);
	move_pa(data->a, data->b);
	move_pa(data->a, data->b);
}

void	case10(t_data *data)
{
	move_pa(data->a, data->b);
	move_sb(data->a, data->b);
	move_pa(data->a, data->b);
	move_pa(data->a, data->b);
}

void	case11(t_data *data)
{
	move_pa(data->a, data->b);
	move_pa(data->a, data->b);
	move_pa(data->a, data->b);
}
