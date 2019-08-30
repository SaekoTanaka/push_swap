/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka <stanaka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 11:32:46 by stanaka           #+#    #+#             */
/*   Updated: 2019/08/29 15:41:05 by stanaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_move_stack c1[2] = {
	{0, *move_ra, *move_pb, *move_sa},
	{1, *move_pa, *move_rb, *move_sb}
};

t_3_sort_case	sort3[12] = {
	{0, *case0},
	{1, *case1},
	{2, *case2},
	{3, *case3},
	{4, *case4},
	{5, *case5},
	{6, *case6},
	{7, *case7},
	{8, *case8},
	{9, *case9},
	{10, *case10},
	{11, *case11},
};

int	check_sort_case(int a_or_b, t_data *data)
{
	t_node	*first;
	t_node	*second;
	t_node	*third;
	t_stack *tmp;

	tmp = stack_a_or_b(a_or_b, data);
	first = tmp->top;
	second = tmp->top->next;
	third = tmp->top->next->next;
	if (first->i < second->i)
	{
		if (second->i < third->i)
			return (0 + 6 * a_or_b);
		else if (first->i < third->i)
			return (1 + 6 * a_or_b);
		else
			return (3 + 6 * a_or_b);		
	}
	if(second->i > third->i)
		return(5 + 6 * a_or_b);
	else if (first->i > third->i)
		return (4 + 6 * a_or_b);
	else
		return (2 + 6 * a_or_b);
}

void	sort_3(int a_or_b, t_data *data)
{
	int	i;

	i = check_sort_case(a_or_b, data);
	sort3[i].c(data);
}

//void    case0(t_data *data)
//{
//    move_ra(data->a, data->b);
//    move_ra(data->a, data->b);
//    move_ra(data->a, data->b);
//}

void	case0(t_data *data)
{
	if (data != NULL)
		return ;
}





