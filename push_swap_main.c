/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka <stanaka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 12:01:38 by stanaka           #+#    #+#             */
/*   Updated: 2019/08/21 17:28:38 by stanaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int ac, char **av)
{

	t_data			*data;
	t_pivot_data	*p_d;

	data = malloc(sizeof(t_data));
	p_d = malloc(sizeof(t_pivot_data));
	data->a = stack_init();
	data->b = stack_init();
	if (!read_arg_make_stack(ac, av, data->a))
		return (0);
	//the number of numbers is ac - 1;

	data->a_n = ac - 1;
	data->b_n = 0;
	while (data->a_n > 4)
	{
		find_pivot(data, p_d);
		move_half(data, p_d);
	}
	
	return (0);
}

void	find_pivot(t_data *data, t_pivot_data *p_d)
{
	int		small;

	small = 0;
	p_d->pivot = data->a->top; //anytime we have some stack in a???
	while (p_d->pivot->next)
	{
		if (p_d->pivot->i > p_d->pivot->next->i)
			small++; //small is the num that show how many nums is smaller than current pivot.
			//these ones go to stack B.
		if ((p_d->ret = check_num_order(data, small))!= 0)
			return (p_d);
		p_d->pivot = p_d->pivot->next;
	}
}

int		check_num_order(t_data *data, int small)
{
	int	time;
	//small should be power(~~~) -1 or power(~~~~)
	while (data->a_n > 3 && power(time) <= data->a_n)
		time++;
	if (small == power(time - 2))
		return (2);
	else if (small == power(time - 2) - 1)
		return (1);
	return (0);
}


void	move_half(t_data *data, int ret) //ret shows we should get the num (>) or (>=)
{
	if (ret == 1)
		
}