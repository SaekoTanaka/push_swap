/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka <stanaka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 10:43:55 by stanaka           #+#    #+#             */
/*   Updated: 2019/08/29 11:56:19 by stanaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int ac, char **av)
{
	t_stack *a;
	t_stack	*b;
	
	a = stack_init();
	b = stack_init();
	if (!read_arg_make_stack(ac, av, a))
		return (0);
	if (read_cmd_move_node(a, b))
	{
		if (stack_order_check(a, b))
			print_ret(1);
		else
			print_ret(2);
	}
	else
		print_ret(0);
	return (0);
}