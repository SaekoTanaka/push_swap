/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka <stanaka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 12:01:38 by stanaka           #+#    #+#             */
/*   Updated: 2019/08/23 19:33:59 by stanaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int    power(int time)
{
    int n;

    n = 1;
    while (time > 0)
    {
        n *= 2;
        time--;
    }
    return (n);
}

int main(int ac, char **av) 
{

	t_data			*data;
	t_pivot_data	*p_d;

	data = malloc(sizeof(t_data));
	p_d = malloc(sizeof(t_pivot_data));
	init_data(data, ac);
	init_p_data(p_d);
	if (!read_arg_make_stack(ac, av, data->a))
		return (0);
	//the number of numbers is ac - 1;
	while (data->a_n > 4)
	{
		find_pivot(data, p_d);

printf("small %d\n", p_d->small);

		move_half(data, p_d);
		//did I chenge a_n????
		data->b_n = p_d->small;
		data->a_n -= p_d->small; 
	}

	print_stack(data->a);
printf("aaaaaaaaaaaaaaa\n");
	print_stack(data->b);
printf("bbbbbbbbbbbbbbb\n");
	//b_n should be something
	return (0);
}

void	find_pivot(t_data *data, t_pivot_data *p_d)
{
	t_node	*tmp;

int t = 0;

	p_d->pivot = data->a->top;
	p_d->ret = check_num_order(data);
	//anytime we have some stack in a???
	tmp = data->a->top;
	while (p_d->pivot && t < 100)
	{
		p_d->small = 0;
		while (tmp) //???? mawaru???/
		{
			if (p_d->pivot->i > tmp->i) //????
			//if ??? while ???
				p_d->small++; //small is the num that show how many nums is smaller than current pivot.
				//these ones go to stack B.
			tmp = tmp->next;
		}
		if (p_d->small == p_d->ret || p_d->small == p_d->ret - 1) //small and ret are...
			return ;
		p_d->pivot = p_d->pivot->next;


		t++;
	}
}

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

int		check_num_order(t_data *data)
{
	int	time;

	time = 0;
	//small should be power(~~~) -1 or power(~~~~)
	while (data->a_n > 3 //now this condition is included in main 
	&& power(time) <= data->a_n)
		time++;
	//if (small == power(time - 2))
	//	return (2);//not include small
	//else if (small == power(time - 2) - 1)
	//	return (1);//include small one we have to move
	return (power(time - 2));
}
