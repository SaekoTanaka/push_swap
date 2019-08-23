/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka <stanaka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 12:01:38 by stanaka           #+#    #+#             */
/*   Updated: 2019/08/22 09:29:45 by stanaka          ###   ########.fr       */
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
		//did I chenge a_n????
		data->b_n = p_d->ret == 1 ? p_d->small + 1 : p_d->small;
		data->a_n -= p_d->ret == 1 ? p_d->small + 1 : p_d->small; 
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
	p_d->pivot = data->a->top; //anytime we have some stack in a???
	while (p_d->pivot->next)
	{
		if (p_d->pivot->i > p_d->pivot->next->i)
			p_d->small++; //small is the num that show how many nums is smaller than current pivot.
			//these ones go to stack B.
		if ((p_d->ret = check_num_order(data, p_d->small))!= 0)
			return ;
		p_d->pivot = p_d->pivot->next;
	}
}

int		check_num_order(t_data *data, int small)
{
	int	time;

	time = 0;
	//small should be power(~~~) -1 or power(~~~~)
	while (data->a_n > 3 //now this condition is included in main 
	&& power(time) <= data->a_n)
		time++;
	if (small == power(time - 2))
		return (2);//not include small
	else if (small == power(time - 2) - 1)
		return (1);//include small one we have to move
	return (0);
}

void	move_half_1(t_data *data, t_pivot_data *p_d)
{
	int	tmp;		

	tmp = p_d->small;
	//while (data->a->top)//nooooooo cause stack A always has some nodes
	while (tmp > -1)
	{
		if (p_d->pivot->i >= data->a->top->i)
		{
			node_push(data->b, data->a->top->i);
			node_pop(data->a);
			tmp--;
		}
		else
			move_ra(data->a, data->b);
	}	
}

void	move_half_2(t_data *data, t_pivot_data *p_d)
{
	int	tmp;		

	tmp = p_d->small;
	while (tmp > 0)
	{
		if (p_d->pivot->i > data->a->top->i)
		{
			node_push(data->b, data->a->top->i);
			node_pop(data->a);
			tmp--;
		}
		else
			move_ra(data->a, data->b);
	}	
}

void	move_half(t_data *data, t_pivot_data *p_d) //ret shows we should get the num (>) or (>=)
{
	if (p_d->ret == 1)
		move_half_1(data, p_d);
	else if (p_d->ret == 2)
		move_half_2(data, p_d);
}