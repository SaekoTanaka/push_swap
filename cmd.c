/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka <stanaka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 14:02:38 by stanaka           #+#    #+#             */
/*   Updated: 2019/08/29 20:52:23 by stanaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

struct s_command_type cmd_type[11] = {
	{"sa", &move_sa},
	{"sb", &move_sb},
	{"ss", &move_ss},
	{"pa", &move_pa},
	{"pb", &move_pb},
	{"ra", &move_ra},
	{"rb", &move_rb},
	{"rr", &move_rr},
	{"rra", &move_rra},
	{"rrb", &move_rrb},
	{"rrr", &move_rrr},
};

int	read_cmd_move_node(t_stack *a, t_stack *b)
{
	int		check;
	char	*line;

	check = 1;
	while (get_next_line(0, &line) > 0)
	{
		if (!cmd_check_move(line, a, b))
			return (0);
	}
	return (1);
}

int	cmd_check_move(char *buff, t_stack *a, t_stack *b)
{
	int	i;

	i = 0;
	while (i < 11)
	{
		if (ft_strequ(cmd_type[i].cmd, buff))
		{
			cmd_type[i].move_cmd(a, b);
			return (1);
		}
		i++;
	}
	return (0);
}
