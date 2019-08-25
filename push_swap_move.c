/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_move.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka <stanaka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/23 10:25:16 by stanaka           #+#    #+#             */
/*   Updated: 2019/08/25 14:52:11 by stanaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"




//it should be
//{
//	{0, *move_ra, *move_pb, data->a, p_d->a_n}
//	{1, *move_rb, *move_pa, data->b, p_d->b_n}
//};
void	move_half(t_data *data, t_pivot_data *p_d) //ret shows we should get the num (>) or (>=)
{
	int		tmp;
	t_stack	*stack;

	tmp = p_d->small;
	if (!p_d->a_or_b)
		stack = data->a;
	else
		stack = data->b;
	//while (data->a->top)//nooooooo cause stack A always has some nodes
	while (tmp > (p_d->small == p_d->ret ? 0 : 1))//it could be -1
	{
		if (p_d->pivot->i >= stack->top->i)
		{
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

//void	find_pivot(t_data *data, t_pivot_data *p_d)
//{
//	p_d->pivot = data->a->top;
//	 //anytime we have some stack in a???
//	while (p_d->pivot)
//	{
//
//		if (p_d->pivot->i > p_d->pivot->next->i)
//			p_d->small++; //small is the num that show how many nums is smaller than current pivot.
//			//these ones go to stack B.
//		if ((p_d->ret = check_num_order(data, p_d->small))!= 0)
//			return ;
//		p_d->pivot = p_d->pivot->next;
//	}
//}

