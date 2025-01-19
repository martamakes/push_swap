/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_ops_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvigara- <mvigara-@student.42school.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 10:45:33 by mvigara-          #+#    #+#             */
/*   Updated: 2025/01/19 17:31:13 by mvigara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static int	execute_instruction(t_stack **a, t_stack **b, const char *inst)
{
	if (!ft_strcmp(inst, "sa"))
		sa(a);
	else if (!ft_strcmp(inst, "sb"))
		sb(b);
	else if (!ft_strcmp(inst, "ss"))
		ss(a, b);
	else if (!ft_strcmp(inst, "pa"))
		pa(a, b);
	else if (!ft_strcmp(inst, "pb"))
		pb(a, b);
	else if (!ft_strcmp(inst, "ra"))
		ra(a);
	else if (!ft_strcmp(inst, "rb"))
		rb(b);
	else if (!ft_strcmp(inst, "rr"))
		rr(a, b);
	else if (!ft_strcmp(inst, "rra"))
		rra(a);
	else if (!ft_strcmp(inst, "rrb"))
		rrb(b);
	else if (!ft_strcmp(inst, "rrr"))
		rrr(a, b);
	else
		return (0);
	return (1);
}

int process_instruction(t_stack **a, t_stack **b, const char *inst)
{
    char    *clean_inst;
    int     len;
    int     is_valid;

    if (!inst)
        return (0);
    clean_inst = ft_strtrim(inst, "\n");
    if (!clean_inst)
        return (0);    
    len = ft_strlen(clean_inst);
    is_valid = 0;
    if (len > 0)
    	is_valid = execute_instruction(a, b, clean_inst);
    free(clean_inst);
    return (is_valid);
}
