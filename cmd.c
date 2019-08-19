/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka <stanaka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 14:02:38 by stanaka           #+#    #+#             */
/*   Updated: 2019/08/18 20:29:02 by stanaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

struct t_command_type cmd_type[6] = {
	{"sa\n", &move_sa},
	{"sb\n", &move_sb},
	//{"ss\n", &move_ss},
	//{"pa\n", &move_pa},
	//{"pb\n", &move_pb},
	{"ra\n", &move_ra},
	{"rb\n", &move_rb},
	//{"rr\n", &move_rr},
	{"rra\n", &move_rra},
	{"rrb\n", &move_rrb},
	//{"rrr\n", &move_rrr},
};

struct t_command_type1	cmd_type1[5] = {
	{"ss\n", &move_ss},
	{"pa\n", &move_pa},
	{"pb\n", &move_pb},
	{"rr\n", &move_rr},
	{"rrr\n", &move_rrr},
};

int	read_cmd_move_node(t_stack *stack)
{
	int     ret;
	char    buff[6];
	//int		check_ret;

	while ((ret = read(0, buff, 5)) > 0)
	{
		buff[ret] = '\0';
		if (ret > 4 || !cmd_check_move(buff, &stack))
			return(0);
	}
	return(1);
}

int	cmd_check_move(char *buff, t_stack **stack)
{
	int	i;

	i = 0;
	while (i < 11)
	{
		if (ft_strequ(cmd_type[i].cmd, buff))
		{
			cmd_type[i].move_cmd(*stack);
			return (1); //match something
		}
		i++;
	}
	return (0); //it doesnot match
}