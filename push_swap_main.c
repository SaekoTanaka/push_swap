/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka <stanaka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 12:01:38 by stanaka           #+#    #+#             */
/*   Updated: 2019/08/25 19:56:42 by stanaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//int    power(int time)
//{
//    int n;
//
//    n = 1;
//    while (time > 0)
//    {
//        n *= 2;
//        time--;
//    }
//    return (n);
//}

//int main(int ac, char **av) 
//{
//
//	t_data			*data;
//	t_pivot_data	*p_d;
//
//	data = init_data(ac);
//	p_d = init_p_data();
//	if (!read_arg_make_stack(ac, av, data->a))
//		return (0);
//	//the number of numbers is ac - 1;
//	//while (data->a_n > 4)
//	//{
//		find_pivot(data, p_d);
//printf("small %d\n", p_d->small);
//		move_half(data, p_d);
//		change_data(data, p_d);
//	//}
//
//print_stack(data->a);
//printf("aaaaaaaaaaaaaaa\n");
//print_stack(data->b);
//printf("bbbbbbbbbbbbbbb\n");
//
//	return (0);
//}
//


//void	find_pivot(t_data *data, t_pivot_data *p_d)
//{
//	t_node	*tmp;
//
//int t = 0;//just in case
//
//	if (!p_d->a_or_b)
//		p_d->pivot = data->a->top;
//	else
//		p_d->pivot = data->b->top;
//	
//	p_d->ret = get_half_num(data, p_d);
//	//anytime we have some stack in a???
//	tmp = p_d->pivot; //just tmp = a->top or b->top
//	while (p_d->pivot)
//	{
//		p_d->small = 0;
//		while (tmp) //???? mawaru???/
//		{
//			if (p_d->pivot->i > tmp->i) //????
//			//if ??? while ???
//				p_d->small++; //small is the num that show how many nums is smaller than current pivot.
//				//these ones go to stack B.
//			tmp = tmp->next;
//		}
//		if (p_d->small == p_d->ret || p_d->small == p_d->ret - 1) //small and ret are...
//			return ;
//		p_d->pivot = p_d->pivot->next;
//	}
//}
//
//int		get_half_num(t_data *data, t_pivot_data *p_d)
//{
//	int	time;
//	int	num;
//
//	time = 0;
//	if (p_d->a_or_b == 0)
//		num = data->a_n;
//	else
//		num = data->b_n;
//	
//	//small should be power(~~~) -1 or power(~~~~)
//	while (num > 3 //now this condition is included in main 
//	&& power(time) <= num)
//		time++;
//	//if (small == power(time - 2))
//	//	return (2);//not include small
//	//else if (small == power(time - 2) - 1)
//	//	return (1);//include small one we have to move
//	return (power(time - 2));
//}
//