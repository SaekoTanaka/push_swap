/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka <stanaka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 10:43:55 by stanaka           #+#    #+#             */
/*   Updated: 2019/08/18 20:20:09 by stanaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_ret(int i)
{
	if (i == 1)
		printf("OK\n");
	else if (i == 0)
		printf("ERROR\n");
	else
		printf("KO\n");	
}

int main(int ac, char **av)
{
	t_stack *stack;

	stack = stack_init();
	read_arg_make_stack(ac, av, stack);
	if (read_cmd_move_node(stack))
		print_ret(1);
	else
		print_ret(2);
	return (0);
}