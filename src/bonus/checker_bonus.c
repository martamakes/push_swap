/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvigara- <mvigara-@student.42school.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 10:45:33 by mvigara-          #+#    #+#             */
/*   Updated: 2025/01/19 18:01:31 by mvigara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	execute_instruction(t_stack **a, t_stack **b, const char *inst)
{
	if (!ft_strcmp(inst, "sa"))
		sa(a, false);
	else if (!ft_strcmp(inst, "sb"))
		sb(b, false);
	else if (!ft_strcmp(inst, "ss"))
		ss(a, b, false);
	else if (!ft_strcmp(inst, "pa"))
		pa(a, b, false);
	else if (!ft_strcmp(inst, "pb"))
		pb(a, b, false);
	else if (!ft_strcmp(inst, "ra"))
		ra(a, false);
	else if (!ft_strcmp(inst, "rb"))
		rb(b, false);
	else if (!ft_strcmp(inst, "rr"))
		rr(a, b, false);
	else if (!ft_strcmp(inst, "rra"))
		rra(a, false);
	else if (!ft_strcmp(inst, "rrb"))
		rrb(b, false);
	else if (!ft_strcmp(inst, "rrr"))
		rrr(a, b, false);
	else
		return (0);
	return (1);
}

int	process_instruction(t_stack **a, t_stack **b, const char *inst)
{
	char	*clean_inst;
	int		len;
	int		is_valid;

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

static int	read_and_execute_instructions(t_stack **stack_a, t_stack **stack_b)
{
	char	*line;

	while (1)
	{
		line = get_next_line(0);
		if (!line)
			break ;
		if (!process_instruction(stack_a, stack_b, line))
		{
			free(line);
			error_exit(stack_a, stack_b);
		}
		free(line);
	}
	return (is_sorted(*stack_a) && !*stack_b);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		result;

	if (argc == 1)
		return (0);
	stack_a = NULL;
	stack_b = NULL;
	if (!process_input(argc, argv, &stack_a))
		error_exit(&stack_a, &stack_b);
	if (!stack_a)
		error_exit(&stack_a, &stack_b);
	result = read_and_execute_instructions(&stack_a, &stack_b);
	if (result)
		ft_putstr_fd("\033[32mOK\033[0m\n", 1);
	else
		ft_putstr_fd("\033[31mKO\033[0m\n", 1);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
