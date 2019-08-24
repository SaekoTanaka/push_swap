/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_move.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka <stanaka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/23 10:25:16 by stanaka           #+#    #+#             */
/*   Updated: 2019/08/23 19:21:12 by stanaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//void	move_half_1(t_data *data, t_pivot_data *p_d)
//{
//	int	tmp;		
//
//	tmp = p_d->small;
//	//while (data->a->top)//nooooooo cause stack A always has some nodes
//	while (tmp > -1)
//	{
//		if (p_d->pivot->i >= data->a->top->i)
//		{
//			node_push(data->b, data->a->top->i);
//			node_pop(data->a);
//			tmp--;
//		}
//		else
//			move_ra(data->a, data->b);
//	}	
//}
//
//void	move_half_2(t_data *data, t_pivot_data *p_d)
//{
//	int	tmp;		
//
//	tmp = p_d->small;
//	while (tmp > 0)
//	{
//		if (p_d->pivot->i > data->a->top->i)
//		{
//			node_push(data->b, data->a->top->i);
//			node_pop(data->a);
//			tmp--;
//		}
//		else
//			move_ra(data->a, data->b);
//	}	
//}

void	move_half(t_data *data, t_pivot_data *p_d) //ret shows we should get the num (>) or (>=)
{
	int	tmp;		

	tmp = p_d->small;
	//while (data->a->top)//nooooooo cause stack A always has some nodes
	while (tmp > (p_d->small == p_d->ret ? 0 : 1))
	{
		if (p_d->pivot->i >= data->a->top->i)
		{
			//node_push(data->b, data->a->top->i);
			//node_pop(data->a);
			move_pb(data->a, data->b);
			printf("pb\n");
			tmp--;
		}
		else
		{
			move_ra(data->a, data->b);
			printf("ra\n");
		}
	}
}