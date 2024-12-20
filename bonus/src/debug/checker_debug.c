/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_debug.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvigara- <mvigara-@student.42school.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 08:27:56 by mvigara-          #+#    #+#             */
/*   Updated: 2024/12/20 09:07:03 by mvigara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	init_log(t_log *log)
{
	log->total_ops = 0;
	log->valid_ops = 0;
	log->invalid_ops = 0;
	log->last_op = NULL;
	log->debug_mode = getenv("DEBUG") != NULL;
}

void	log_operation(t_log *log, const char *op)
{
	if (!log || !op)
		return ;
	log->total_ops++;
	log->valid_ops++;
	log->last_op = (char *)op;
	if (log->debug_mode)
		ft_printf("DEBUG: Executed operation: %s\n", op);
}

void	print_stack(t_stack *stack, char stack_name)
{
	ft_printf("Stack %c: ", stack_name);
	while (stack)
	{
		ft_printf("%d ", stack->value);
		stack = stack->next;
	}
	ft_printf("\n");
}

void	print_debug_info(t_stack *a, t_stack *b, t_log *log)
{
	ft_printf("\n=== Debug Information ===\n");
	ft_printf("Total operations: %d\n", log->total_ops);
	ft_printf("Valid operations: %d\n", log->valid_ops);
	ft_printf("Invalid operations: %d\n", log->invalid_ops);
	if (log->last_op)
		ft_printf("Last operation: %s\n", log->last_op);
	else
		ft_printf("Last operation: none\n");
	ft_printf("\nFinal stack state:\n");
	print_stack(a, 'A');
	print_stack(b, 'B');
	ft_printf("======================\n");
}
