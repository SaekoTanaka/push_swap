/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test0827.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka <stanaka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 15:45:24 by stanaka           #+#    #+#             */
/*   Updated: 2019/08/29 21:20:15 by stanaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

struct s_move_stack half_cmd[2] = {
	{0, *move_ra, *move_pb, *move_rra},
	{1, *move_pa, *move_rb, *move_rrb}
};

void	split1(int n, int a_or_b, t_data *data, t_pivot_data *p_d)
{
	if (n < 4)
	{
		if (n == 3)
			sort_3(a_or_b, data);
		else
			sort(a_or_b, data);
		return ;
	}
	data->move_num = n / 2;
	find_p(n, a_or_b, data, p_d);
	m_node(n, a_or_b, data, p_d);
	split1(n - data->move_num, 0, data, p_d);
	split1(data->move_num, 1, data, p_d);
}

void	find_p(int n, int a_or_b, t_data *data, t_pivot_data *p_d)
{
	t_stack	*tmp;
	t_node	*c_n;
	int		i;
	int		j;

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
		if (p_d->ret == data->move_num)
			return ;
		p_d->pivot = p_d->pivot->next;
		i++;
	}
}

void	m_node(int n, int a_or_b, t_data *data, t_pivot_data *p_d)
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
	while (i < (a_or_b == 0 ? n - data->move_num : data->move_num))
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

int					main(int ac, char **av)
{
	t_data			*data;
	t_pivot_data	*p_d;

	data = init_data(ac);
	p_d = init_p_data();
	if (!read_arg_make_stack(ac, av, data->a))
		return (0);
	if (ac == 2 || check_stack(data))
	{
		print_stack(data->a);
		return (0);
	}
	split1(ac - 1, 0, data, p_d);

print_stack(data->a);
printf("ffffffaaaaa\n");
print_stack(data->b);
printf("bbbbb\n");

	return (0);
}
