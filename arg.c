/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka <stanaka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 14:02:33 by stanaka           #+#    #+#             */
/*   Updated: 2019/08/30 19:51:31 by stanaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_ret(int i)
{
	if (i == 1)
		printf("OK\n");
	else if (i == 0)
		printf("Error\n");
	else
		printf("KO\n");	
}

int		str_is_digit(char **str)
{
	int	i;

	while (*str)
	{
		i = 0;
		if ((*str)[i] == '-' || (*str)[i] == '+')
			i++;
		while ((*str)[i] != '\0' && (*str)[i] != ' ' && ft_isdigit((*str)[i]))
			i++;	
		if ((*str)[i] != '\0')
		{
			return (0);
		}
		str++;

	}
	return (1);
}

int	ft_atoi2(char **str, t_stack *stack)
{
	int i;
	int n;
	unsigned long sum;

	while (*str)
	{
		i = 0;
		n = 1;
		sum = 0;
		if ((*str)[i] == '-' || (*str)[i] == '+')
		{
			if ((*str)[i] == '-')
				n = -1;
			i++;
		}
		while ((*str)[i] != '\0' && (*str)[i] != ' ' && sum <= 2147483648) 
		{
			sum = (*str)[i] - 48 + sum * 10;
			i++; 
		}
		if (((*str)[i] != '\0' && (*str)[i] != ' ') || (sum == 2147483648 && n == 1))
			return (0);
		if (make_stack(stack, (int)sum * n))
			str++;
		else
			return (0);		
	}
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


int	make_stack(t_stack *stack, int arr)
{
	t_node	*new;
	t_node	*tmp;

	new = malloc(sizeof(t_node));
	if (!node_dup_check(arr, stack))
		return (0);
	new->i = arr;
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
	return (1);
}


int	read_arg_make_stack(int ac, char **av, t_stack *stack)
{
	char	**arr;
	int		i;

	i = 0;
	if (ac == 1)
	{
		print_ret(0);
		return (0);
	}
	arr = ft_strsplit3(ac, av, ' ');
	if (!str_is_digit(arr) || !ft_atoi2(arr, stack))
	{
		print_ret(0);
		while (arr[i])
		{
			free(arr[i]);
			i++;
		}
		free(arr);
		return (0);
	}
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	return (1);
}
