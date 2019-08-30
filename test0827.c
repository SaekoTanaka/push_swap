/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test0827.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka <stanaka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 15:45:24 by stanaka           #+#    #+#             */
/*   Updated: 2019/08/29 16:46:53 by stanaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_move_stack half_cmd[2] = {
	{0, *move_ra, *move_pb, *move_rra},
	{1, *move_pa, *move_rb, *move_rrb}
};

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

void	split1(int n, int a_or_b, t_data *data, t_pivot_data *p_d)
{	
	int	move_num;

	if (n < 4)
	{
		

		if (n == 3)
			sort_3(a_or_b, data);
		else
			sort(a_or_b, data);

//print_stack(data->a);
//printf("ffffffaaaaa\n");
//print_stack(data->b);
//printf("bbbbb\n");

		return ;
	}

//print_stack(data->a);
//printf("aaaaa\n");
//print_stack(data->b);
//printf("bbbbb\n");
//

	move_num = get_split_num(n);
	find_p(n, move_num, a_or_b, data, p_d);
	m_node(n, move_num, a_or_b, data, p_d);
	split1(n - move_num, 0, data, p_d);
	split1(move_num, 1, data, p_d);
}

void	find_p(int n, int move_num, int a_or_b, t_data *data, t_pivot_data *p_d)
{
	t_stack	*tmp;
	t_node	*c_n;
	int i;
	int j;
	
	tmp = stack_a_or_b(a_or_b, data);
	i = 0;
	p_d->pivot = tmp->top;
	while (i < n && p_d->pivot)
	{
		c_n = tmp->top;
		j = 0;
		p_d->ret = 0;
		while (j < n && c_n)
		{
			if (p_d->pivot->i >= c_n->i)
				p_d->ret++;
			c_n = c_n->next;
			j++;
		}
		if (p_d->ret == move_num)
			return ;
		p_d->pivot = p_d->pivot->next;
		i++;
	}
}

void	m_node(int n, int move_num, int a_or_b, t_data *data, t_pivot_data *p_d)
{
	t_stack *tmp;
	int		i;

	tmp = stack_a_or_b(a_or_b, data);
	i = 0;
	while (i < n)
	{
		if (tmp->top->i > p_d->pivot->i)
			half_cmd[a_or_b].move_func1(data->a, data->b);
		else
			half_cmd[a_or_b].move_func2(data->a, data->b);
		i++;
	}
	i = 0;
	while (i < (a_or_b == 0 ? n - move_num : move_num))
	{
		half_cmd[a_or_b].move_func3(data->a, data->b);
		i++;
	}
}

int	check_stack(t_data *data)
{
	t_node	*tmp;

	tmp = data->a->top;
	while (tmp->next && tmp->i < tmp->next->i)
		tmp = tmp->next;
	if (tmp->next == NULL)
		return (1);
	else
		return (0);		
}

int main(int ac, char **av)//asobi
{
	t_data *data;
	t_pivot_data *p_d;
	
	data = init_data(ac);
	p_d = init_p_data();
	if (!read_arg_make_stack(ac, av, data->a))
		return (0);
	if (ac == 2 || check_stack(data))
	{
		print_stack(data->a);
		return (0);
	}
	split1(ac - 1, 0,data,p_d);
//	sort_chunk(ac - 1, data);

print_stack(data->a);
printf("ffffffaaaaa\n");
print_stack(data->b);
printf("bbbbb\n");

	return (0);
}