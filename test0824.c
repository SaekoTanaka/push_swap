#include "push_swap.h"

t_stack		*stack_a_or_b(int a_or_b)
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

void    sort(int n, int a_or_b)
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
void    split(int n, int a_or_b /*, stack *a, stack *b */)//n is how many numbers the stack has.
{
	int move_num;

	if (n < 4)
	{
		sort(n, a_or_b);
		return ;
	}
	move_num = get_split_num(n);
	find_pivot(n, move_num, a_or_b/*, a, b */);
	move_node(/*a,b */);
	split(n - move_num, 0 /*,a ,b */); //stack a //large
	split(move_num, 1 /*, a, b */); //stack b //small
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

void	find_pivot()
{
	t_stack	*tmp;
	t_node	*check_num;
	
	if (!a_or_b)//find in stack a
		tmp = data->a;
	else
		tmp = data->b;
	p_d->pivot = tmp->top;
	while (p_d->pivot) //small num including this pivot or not??? find small number is move_num.
	{
		check_num = tmp->top;
		p_d->ret = 0;
		while (check_num)
		{
			if (check_num->i <= pivot->i)
				p_d->ret++;
			check_num = check_num->next;
		}
		if (p_d->ret == move_num)
			return ;
		p_d->pivot = p_d->pivot->next;
	}
}

void	move_node()
{
	t_stack *tmp;
	t_node	*check_num;
	
	if (!a_or_b)
		tmp = data->a;
	else
		tmp = data->b;
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
	split (35, 0);
	return (0);
}