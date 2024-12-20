/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_ops.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvigara- <mvigara-@student.42school.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 08:27:13 by mvigara-          #+#    #+#             */
/*   Updated: 2024/12/20 08:52:08 by mvigara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../bonus/inc/checker.h"

int	execute_instruction(char *line, t_stack **a, t_stack **b, t_log *log)
{
	if (ft_strcmp(line, "sa\n") == 0)
		checker_sa(a, log);
	else if (ft_strcmp(line, "sb\n") == 0)
		checker_sb(b, log);
	else if (ft_strcmp(line, "ss\n") == 0)
		checker_ss(a, b, log);
	else if (ft_strcmp(line, "pa\n") == 0)
		checker_pa(a, b, log);
	else if (ft_strcmp(line, "pb\n") == 0)
		checker_pb(a, b, log);
	else if (ft_strcmp(line, "ra\n") == 0)
		checker_ra(a, log);
	else if (ft_strcmp(line, "rb\n") == 0)
		checker_rb(b, log);
	else if (ft_strcmp(line, "rr\n") == 0)
		checker_rr(a, b, log);
	else if (ft_strcmp(line, "rra\n") == 0)
		checker_rra(a, log);
	else if (ft_strcmp(line, "rrb\n") == 0)
		checker_rrb(b, log);
	else if (ft_strcmp(line, "rrr\n") == 0)
		checker_rrr(a, b, log);
	else
		return (0);
	return (1);
}
