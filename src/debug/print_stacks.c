/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stacks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvigara- <mvigara-@student.42school.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 07:25:00 by mvigara-          #+#    #+#             */
/*   Updated: 2024/12/18 08:35:50 by mvigara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_debug_str(char *str)
{
	if (!VISUALS)
		return ;
	write(1, "\033[0;90m", 7);
	write(1, str, ft_strlen(str));
	write(1, "\033[0m", 4);
}

void	print_debug_nbr(int n)
{
	if (!VISUALS)
		return ;
	write(1, "\033[0;90m", 7);
	ft_putnbr_fd(n, 1);
	write(1, "\033[0m", 4);
}

void	print_debug_char(char c)
{
	if (!VISUALS)
		return ;
	write(1, "\033[0;90m", 7);
	write(1, &c, 1);
	write(1, "\033[0m", 4);
}

void	print_stacks(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*temp_a;
	t_stack	*temp_b;

	if (!VISUALS)
		return ;
	temp_a = stack_a;
	temp_b = stack_b;
	print_debug_str("Stack A: ");
	while (temp_a)
	{
		print_debug_nbr(temp_a->value);
		temp_a = temp_a->next;
		if (temp_a)
			print_debug_char(' ');
	}
	print_debug_char('\n');
	print_debug_str("Stack B: ");
	while (temp_b)
	{
		print_debug_nbr(temp_b->value);
		temp_b = temp_b->next;
		if (temp_b)
			print_debug_char(' ');
	}
	print_debug_str("\n");
}

void	print_one(t_stack *stack, char stack_name)
{
	t_stack	*temp;

	if (!VISUALS)
		return ;
	temp = stack;
	print_debug_str("Stack ");
	print_debug_char(stack_name);
	print_debug_str(": ");
	while (temp)
	{
		print_debug_nbr(temp->value);
		temp = temp->next;
		if (temp)
			print_debug_char(' ');
	}
	print_debug_str("\n");
}
