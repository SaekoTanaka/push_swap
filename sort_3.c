/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka <stanaka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 11:32:46 by stanaka           #+#    #+#             */
/*   Updated: 2019/08/27 06:33:45 by stanaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_3_sort_case	sort3[6] = {
	{0, *case0}, //123
	{1, *case1}, //132
	{2, *case2}, //213
	{3, *case3}, //231
	{4, *case4}, //312
	{5, *case5}, //321
};

int	check_sort_case(t_data *data)//sort_3 is always stack a
{
	t_node	*first;
	t_node	*second;
	t_node	*third;

	first = data->a->top;
	second = data->a->top->next;
	third = data->a->top->next->next;
	if (first->i < second->i)
	{
		if (second->i < third->i)
			return (0);
		else if (first->i < third->i)
			return (1);
		else
			return (3);		
	}
	if(second->i > third->i)
		return(5);
	else if (first->i > third->i)
		return (4);
	else
		return (2);
}

void	sort_3(t_data *data)
{
	int	i;

	i = check_sort_case(data);
	sort3[i].c(data);
}

void    case0(t_data *data)
{
    move_ra(data->a, data->b);
    move_ra(data->a, data->b);
    move_ra(data->a, data->b);
}

void	case1(t_data *data)
{
	move_ra(data->a, data->b);
	move_sa(data->a, data->b);
	move_ra(data->a, data->b);
	move_ra(data->a, data->b);
}

void	case2(t_data *data)
{
	move_sa(data->a, data->b);
	move_ra(data->a, data->b);
	move_ra(data->a, data->b);
	move_ra(data->a, data->b);
}

void	case3(t_data *data)
{
	move_pb(data->a, data->b);
	move_sa(data->a, data->b);
	move_ra(data->a, data->b);
	move_pa(data->a, data->b);
	move_ra(data->a, data->b);
	move_ra(data->a, data->b);
}

void	case4(t_data *data)
{
	move_sa(data->a, data->b);
	move_ra(data->a, data->b);
	move_sa(data->a, data->b);
	move_ra(data->a, data->b);
	move_ra(data->a, data->b);
}

void	case5(t_data *data)
{
	move_pb(data->a, data->b);
	move_sa(data->a, data->b);
	move_ra(data->a, data->b);
	move_ra(data->a, data->b);
	move_pa(data->a, data->b);
	move_ra(data->a, data->b);	
}



