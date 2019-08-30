/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3_help.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka <stanaka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 22:03:08 by stanaka           #+#    #+#             */
/*   Updated: 2019/08/29 15:40:36 by stanaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_move_stack_2 c2[2] = {
	{0, *move_ra, *move_pb, *move_sa, *move_pa},
	{1, *move_rb, *move_pa, *move_sb, *move_pb}
};

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

//void	case1(t_data *data)
//{
//	move_ra(data->a, data->b);
//	move_sa(data->a, data->b);
//	move_ra(data->a, data->b);
//	move_ra(data->a, data->b);
//}
//
//void	case2(t_data *data)
//{
//	move_sa(data->a, data->b);
//	move_ra(data->a, data->b);
//	move_ra(data->a, data->b);
//	move_ra(data->a, data->b);
//}
//
//void	case3(t_data *data)
//{
//	move_pb(data->a, data->b);
//	move_sa(data->a, data->b);
//	move_ra(data->a, data->b);
//	move_pa(data->a, data->b);
//	move_ra(data->a, data->b);
//	move_ra(data->a, data->b);
//}
//
//void	case4(t_data *data)
//{
//	move_sa(data->a, data->b);
//	move_ra(data->a, data->b);
//	move_sa(data->a, data->b);
//	move_ra(data->a, data->b);
//	move_ra(data->a, data->b);
//}
//
//void	case5(t_data *data)
//{
//	move_pb(data->a, data->b);
//	move_sa(data->a, data->b);
//	move_ra(data->a, data->b);
//	move_ra(data->a, data->b);
//	move_pa(data->a, data->b);
//	move_ra(data->a, data->b);
//}