/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test0824.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka <stanaka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 14:55:43 by stanaka           #+#    #+#             */
/*   Updated: 2019/08/25 15:17:21 by stanaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack		*stack_a_or_b(int a_or_b, t_data *data)
{
	t_stack *tmp;
	
	if (!a_or_b)
		tmp = data->a;
	else
		tmp = data->b;
		return (tmp);
}
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

void    sort(int n, int a_or_b, t_data *data, t_pivot_data *p_d)
{
	int i = 1;

	if (!a_or_b)
		printf("a");
	else
		printf("b");
	
	while (i <= n)
	{
		printf("%d", i);
		i++;
	}
	printf("\n");
}


//split 
//in if, chunk has less than 4 numbers(3 or 2)
// i have to sort these num and if(stack a)ra, if (stack b)keep these order.
void    split(int n, int a_or_b, t_data *data, t_pivot_data *p_d)//n is how many numbers the stack has.
{
	int move_num;

	if (n < 4)
	{
		sort(n, a_or_b, data, p_d);
		return ;
	}
	move_num = get_split_num(n);
	find_pivot(n, move_num, a_or_b, data, p_d);
	move_node(a_or_b, data, p_d);
	split(n - move_num, 0, data, p_d); //stack a //large
	split(move_num, 1, data, p_d); //stack b //small
}

int     get_split_num(int n)
{
	int time;
	int tmp;

	time = 0;
	while (power(time) <= n)
		time++;
	tmp = power(time - 2);
	return (tmp);
}

void	find_pivot(int n, int move_num, int a_or_b, t_data *data, t_pivot_data *p_d)
{
	t_stack	*tmp;
	t_node	*check_num;
	
	tmp = stack_a_or_b(a_or_b, data);
	p_d->pivot = tmp->top;
	while (p_d->pivot) //small num including this pivot or not??? find small number is move_num.
	{
		check_num = tmp->top;
		p_d->ret = 0;
		while (check_num)
		{
			if (check_num->i <= p_d->pivot->i)
				p_d->ret++;
			check_num = check_num->next;
		}
		if (p_d->ret == move_num)
			return ;
		p_d->pivot = p_d->pivot->next;
	}
}

void	move_node(int a_or_b, t_data *data, t_pivot_data *p_d)
{
	t_stack *tmp;
	t_node	*check_num;
	
	tmp = stack_a_or_b(a_or_b, data);
	check_num = tmp->top;
	while (check_num)
	{
		if (check_num->i > p_d->pivot->i)
			//move_ra;
			half_cmd[a_or_b].move_func1(data->a, data->b);

		else
			half_cmd[a_or_b].move_func2(data->a, data->b);
		check_num = check_num->next;
	}
}

t_move_stack half_cmd[2] = {
	{0, *move_ra, *move_pb},
	{1, *move_rb, *move_pa}
};

int main()
{
	t_data *data;
	t_pivot_data *p_d;
	split (35, 0, data, p_d);
	sort_chunk(data);//
	return (0);
}


void	sort_chunk(t_data *data)
{
	while (!stack_is_empty(data->b)) /////?????????
	{
		move_rrb(data->a, data->b);
		move_pa(data->a, data->b);
		move_rrb(data->a, data->b);	
		move_pa(data->a, data->b);
		move_ra(data->a, data->b);
		move_ra(data->a, data->b);
		move_ra(data->a, data->b);
		move_ra(data->a, data->b);
	}
	if (data->a->top) //compare a(top) and a(second)
		//ra or nothing
}

//sort //in sort acsend de