/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvigara- <mvigara-@student.42school.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 10:45:33 by mvigara-          #+#    #+#             */
/*   Updated: 2025/01/19 17:10:45 by mvigara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

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
