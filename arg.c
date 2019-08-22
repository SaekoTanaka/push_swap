/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka <stanaka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 14:02:33 by stanaka           #+#    #+#             */
/*   Updated: 2019/08/20 16:06:52 by stanaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		str_is_digit(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] != '\0' && ft_isdigit(str[i]))
		i++;
	if (str[i] == '\0')
		return (1);
	return (0);
}

int	ft_atoi2(char *str, int *data)
{
	int i;
	int n;
	unsigned long sum;

	i = 0;
	n = 1;
	sum = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			n = -1;
		i++;
	}
	while (str[i] != '\0' && sum <= 2147483648) 
	{
		sum = str[i] - 48 + sum * 10;
		i++; 
	}
	if ((str[i] != '\0') || (sum == 2147483648 && n == 1))
		return (0);
	*data = (int)sum * n;
	return (1);
}

int	node_dup_check(int data, t_stack *stack)
{
	t_node	*tmp;

	if (stack_is_empty(stack))
		return(1);
	tmp = stack->top;
	while (tmp)
	{
		if (data == tmp->i)
			return(0);
		tmp = tmp->next;
	}
	return (1);
}


void	make_stack(t_stack *stack, int data)
{
	t_node	*new;
	t_node	*tmp;
	
	new = malloc(sizeof(t_node));
	new->i = data;
	new->next = NULL;
	if (stack_is_empty(stack))
		stack->top = new;
	else
	{
		tmp = stack->top;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}


int	read_arg_make_stack(int ac, char **av, t_stack *stack)
{
	int	i;
	int	data;

	i = 1;
	while (i < ac && str_is_digit(av[i]))
	{
		if (ft_atoi2(av[i], &data) && node_dup_check(data, stack))
		//node_push(stack, data); //!!!!!!!!!!!!!!!!!!!!!!!!
		{
			make_stack(stack, data);
			//new = malloc(sizeof(t_node));
			//new->i = data;
			//new->next = NULL;
			//if (stack_is_empty(stack))
			//	stack->top = new;
			//else
			//{
			//	tmp = stack->top;
			//	while (tmp->next)
			//		tmp = tmp->next;
			//	tmp->next = new;
			//}
		}
		else
			break ;
		i++;
	}
	if (ac == 1 || ac != i)
	{
		print_ret(0);
		return (0);
	}
	return (1);
}