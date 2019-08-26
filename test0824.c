/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test0824.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka <stanaka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 14:55:43 by stanaka           #+#    #+#             */
/*   Updated: 2019/08/25 21:12:13 by stanaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_move_stack half_cmd[2] = {
	{0, *move_ra, *move_pb},
	{1, *move_rb, *move_pa}
};

t_3_sort_case	sort3[6] = {
	{0, *case0}, //123
	{1, *case1}, //132
	{2, *case2}, //213
	{3, *case3}, //231
	{4, *case4}, //312
	{5, *case5}, //321
};

t_stack		*stack_a_or_b(int a_or_b, t_data *data)
{
	t_stack *tmp;
	
	if (!a_or_b)
		tmp = data->a;
	else
		tmp = data->b;
		return (tmp);
}

void	sort_as(t_data *data)
{
	if (data->a->top > data->a->top->next)
		move_sa(data->a, data->b);
	move_ra(data->a, data->b);
	move_ra(data->a, data->b);	
}

void	sort_de(t_data *data)
{
	if (data->b->top < data->b->top->next)
		move_sb(data->a, data->b);
}

void    sort(int a_or_b, t_data *data)
{
	int i = 1;

	if (!a_or_b)
		//printf("a");
		sort_as(data); // top/s & sec/l and ra;
	else
		//printf("b");
		sort_de(data); // top/l & sec/s
	//while (i <= n)
	//{
	//	printf("%d", i);
	//	i++;
	//}
	//printf("\n");
}

void	check_sort_case(t_data *data)
{
	if (data->b->top)
}

void	sort_3(t_data *data)
{
	check_sort_case(data);
}

//split 
//in if, chunk has less than 4 numbers(3 or 2)
// i have to sort these num and if(stack a)ra, if (stack b)keep these order.
void    split(int n, int a_or_b, t_data *data, t_pivot_data *p_d)//n is how many numbers the stack has.
{
	int move_num;

	if (n < 4)
	{
		if (n == 3)
			sort_3(data);
		sort(a_or_b, data);

printf("a_or_b:%d,n:%d\n", a_or_b, n);

		return ;
	}
	move_num = get_split_num(n);

printf("move_num:%d\n", move_num);

	//find_pivot(move_num, a_or_b, data, p_d);
	//move_node(a_or_b, data, p_d);
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
	if (tmp == 1)
		tmp++;
	return (tmp);
}

void	find_pivot(int move_num, int a_or_b, t_data *data, t_pivot_data *p_d)
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


int main(int ac, char **av)
{
	t_data *data;
	t_pivot_data *p_d;
	
	data = init_data(ac);
	p_d = init_p_data();

	if (!read_arg_make_stack(ac, av, data->a))
		return (0);
	split(ac - 1, 0, data, p_d);
	sort_chunk(data);
	return (0);
}


void	sort_chunk(t_data *data)
{
	while (!stack_is_empty(data->b))
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
	//maybe if (n % 2 == 0)
	//	nothing
	//%2 == 1
	// move_ra
}

//sort //in sort acsend de