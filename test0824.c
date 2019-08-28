/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test0824.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka <stanaka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 14:55:43 by stanaka           #+#    #+#             */
/*   Updated: 2019/08/28 10:49:10 by stanaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
t_move_stack half_cmd1[2] = {
	{0, *move_ra, *move_pb, *move_rra},
	{1, *move_pa, *move_rb, *move_rrb}
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
	if (data->a->top->i > data->a->top->next->i)
		move_sa(data->a, data->b);
	move_ra(data->a, data->b);
	move_ra(data->a, data->b);	
}

void	sort_de(t_data *data)
{
	if (data->b->top->i < data->b->top->next->i)
		move_sb(data->a, data->b);
	move_rb(data->a, data->b);
	move_rb(data->a, data->b);
}

//void	sort_both(t_data *data)
//{
//	t_node *tmp;
//
//	tmp = data->a->top;
//	if (tmp->i > tmp->next->i)
//	{
//		if ()
//	}
//}

void    sort(int a_or_b, t_data *data)
{
	//int i = 1;

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
print_stack(data->a);
printf("       aaaaa\n");
print_stack(data->b);
printf("after_sort_bbbbb\n\n");
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
			//sort_3(data);
			printf("here3\n");
		else
			//sort(a_or_b, data);
			printf("here2\n");
		return ;
	}
	move_num = get_split_num(n);

	find_pivot(n, move_num, a_or_b, data, p_d);
	move_node(n, move_num, a_or_b, data, p_d);

print_stack(data->a);
printf("aaaaa\n");
printf("n:%d\n", n);
printf("a_or_b:%d\n", a_or_b);
printf("move_num:%d\n",move_num);
print_stack(data->b);
printf("bbbbb\n\n");

	split(n - move_num, 0, data, p_d); //stack a //large
	split(move_num, 1, data, p_d); //stack b //small
}

int     get_split_num(int n)//ok
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

void	find_pivot(int n, int move_num, int a_or_b, t_data *data, t_pivot_data *p_d)//ok
{
	t_stack	*tmp;
	t_node	*check_num;
	int i;
	int j;
	
	tmp = stack_a_or_b(a_or_b, data);
	p_d->pivot = tmp->top;
	j = 0;
	while (p_d->pivot && j < n) //small num including this pivot or not??? find small number is move_num.
	{
		printf("here9\n");
		check_num = tmp->top;
		p_d->ret = 0;
		i = 0;//
		while (check_num && i < n)//
		{
			if (check_num->i <= p_d->pivot->i)
				p_d->ret++;
			check_num = check_num->next;
			i++;
		}
		if (p_d->ret == move_num)
			return ;
		p_d->pivot = p_d->pivot->next;
		j++;
	}
}

void	move_node(int n, int move_num, int a_or_b, t_data *data, t_pivot_data *p_d)//ok
{
	t_stack *tmp;
	int		i;

	i = 0;
	tmp = stack_a_or_b(a_or_b, data);
	//while (i < move_num)
	while (i < n && move_num > 0)
	{
		if (tmp->top->i > p_d->pivot->i)
			half_cmd1[a_or_b].move_func1(data->a, data->b);

		else
		{
			half_cmd1[a_or_b].move_func2(data->a, data->b);
			//i++;
		}
		tmp = stack_a_or_b(a_or_b, data);
		i++;	
	}
}


//int main(int ac, char **av)//asobi
//{
//	t_data *data;
//	t_pivot_data *p_d;
//	
//	data = init_data(ac);//ok
//	p_d = init_p_data();//ok
//
//	if (!read_arg_make_stack(ac, av, data->a))//ok
//		return (0);//ok
//
////node_push(data->b, 12);
////node_push(data->b, 34);
////node_push(data->b, 56);
////node_push(data->b, 78);
////node_push(data->b, 55);
////node_push(data->b, 77);
////split(ac - 1, 0);
//	split(ac - 1, 0, data, p_d);
//	//sort_chunk(ac - 1, data);
//
//print_stack(data->a);
//printf("ffffffaaaaa\n");
//print_stack(data->b);
//printf("bbbbb\n");
//
//	return (0);
//}
//

//void	sort_chunk(int i, t_data *data)//ok
//{
//	while (!stack_is_empty(data->b))
//	{
//		move_rrb(data->a, data->b);
//		move_pa(data->a, data->b);
//		move_rrb(data->a, data->b);	
//		move_pa(data->a, data->b);
//		move_ra(data->a, data->b);
//		move_ra(data->a, data->b);
//		move_ra(data->a, data->b);
//		move_ra(data->a, data->b);
//	}
//	if (i > 3 && i % 2)
//		move_ra(data->a, data->b);
//}

void	small_num(t_data *data)
{
	move_pa(data->a, data->b);
	move_pa(data->a, data->b);
}

void	sort_chunk(int i, t_data *data)
{
//	t_node	*a_next_top;
	int n;

	t_node *b_top;

	if (i <= 3)
		return ;
	b_top = data->b->top;
	while (!stack_is_empty(data->a))
		move_pb(data->a, data->b);

print_stack(data->a);
printf("move_to_b  aaaaa\n");
print_stack(data->b);
printf("bbbbb\n");
printf("%d\n", b_top->i);
	while (data->b->top->i < b_top->i)
		move_rb(data->a, data->b);
print_stack(data->a);
printf("move_to_b  aaaaa\n");
print_stack(data->b);
printf("bbbbb\n");
	if (i % 2)
	{
		move_pa(data->a, data->b);
		move_pa(data->a, data->b);
		move_pa(data->a, data->b);
		move_pa(data->a, data->b);
		move_pa(data->a, data->b);
	}
	else
	{
		move_pa(data->a, data->b);
		move_pa(data->a, data->b);
		move_pa(data->a, data->b);
		move_pa(data->a, data->b);

	}
	n = 0;
	t_node *b_bottom;
	while (!stack_is_empty(data->b) && n < i && data->b->top->next)
	{
		b_bottom = data->b->top;
		while (b_bottom->next)
			b_bottom = b_bottom->next;
		if (data->b->top->i < b_bottom->i)
		{
			move_rrb(data->a, data->b);
			move_rrb(data->a, data->b);
		}
		else
		{
			move_pb(data->a, data->b);
			move_pb(data->a, data->b);
		}
		
		b_bottom = data->b->top;
		while (b_bottom->next)
			b_bottom = b_bottom->next;
		printf("here\n");
		while (data->b->top->next && b_bottom->i < data->b->top->i)
			move_pa(data->a, data->b);
	n++;
	printf("n:%d\n", n);
	}
			printf("he2re\n");

	if (i > 4)
		move_pa(data->a, data->b);

	//n = 0;
	//while (!stack_is_empty(data->b) && i > 3 && n < 50)
	//{
	//	//a_next_top = data->a->top;
	//	while (a_next_top->next && a_next_top->i < a_next_top->next->i)
	//		a_next_top = a_next_top->next;
	//	if (a_next_top->next == NULL)
	//	{
	//		small_num(data);
	//		return ;
	//	}
	//	else
	//		a_next_top = a_next_top->next;////////////////////
	//	
	//	while (a_next_top->i < data->b->top->i)
	//		move_pa(data->a, data->b);
	//	while (a_next_top->i != data->a->top->i)
	//		move_ra(data->a, data->b);
	//n++;
//

print_stack(data->a);
printf("             aaaaa\n");
print_stack(data->b);
printf("             bbbbb\n");

	
}



//void	sort_chunk(int i, t_data *data)
//{
//	
//}

//int main(int ac, char **av)
//{
//	t_data *data;
//	t_pivot_data *p_d;
//	
//	data = init_data(ac);//ok
//	p_d = init_p_data();//ok
//
//	if (!read_arg_make_stack(ac, av, data->a))//ok
//		return (0);//ok
//
//
//
//
//	split(ac - 1, 0, data, p_d);
//	sort_chunk(ac - 1, data);//ok
//
//
//	return (0);
//}
