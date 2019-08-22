/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka <stanaka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 10:43:55 by stanaka           #+#    #+#             */
/*   Updated: 2019/08/21 12:16:53 by stanaka          ###   ########.fr       */
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

//int main(int ac, char **av)
//{
//	t_stack *a;
//	t_stack	*b;
//	
//	a = stack_init();
//	b = stack_init();
//	if (!read_arg_make_stack(ac, av, a))
//		return (0);
//	if (read_cmd_move_node(a, b))
//	{
//		if (stack_order_check(a, b))
//			print_ret(1);
//		else
//			print_ret(2);
//	}
//	else
//		print_ret(0);
//	return (0);
//}