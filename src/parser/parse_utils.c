/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvigara- <mvigara-@student.42school.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 15:45:18 by mvigara-          #+#    #+#             */
/*   Updated: 2024/12/17 11:49:05 by mvigara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Checks if a string is a valid integer representation.
   Returns 1 if valid, 0 if not */
int	is_valid_input(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	if (str[i] == '-' || str[i] == '+')
	{
		if (!str[i + 1])
			return (0);
		i++;
	}
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

/* Checks for duplicate values in the stack.
   Returns 1 if duplicates found, 0 if not */
int	check_duplicates(t_stack *stack)
{
	t_stack	*current;
	t_stack	*compare;

	if (!stack)
		return (0);
	current = stack;
	while (current)
	{
		compare = current->next;
		while (compare)
		{
			if (current->value == compare->value)
				return (1);
			compare = compare->next;
		}
		current = current->next;
	}
	return (0);
}

/* Validates if a string can be converted to a valid integer
   Returns 1 if valid, 0 if overflow or invalid */
int	is_valid_number(char *str)
{
	long long	num;

	if (!str || !is_valid_input(str))
		return (0);
	num = ft_atoll(str);
	if (num > INT_MAX || num < INT_MIN)
		return (0);
	return (1);
}

/* Frees memory allocated by ft_split */
static void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

/* Processes a string of space-separated numbers.
   Returns 1 if successfully processed, 0 if error */
int	process_arg_string(char *str, t_stack **stack)
{
	char		**numbers;
	int			i;
	t_stack		*new;

	numbers = ft_split(str, ' ');
	if (!numbers)
		return (0);
	i = 0;
	while (numbers[i])
	{
		if (!is_valid_number(numbers[i]))
		{
			free_split(numbers);
			return (0);
		}
		new = stack_new(ft_atoi(numbers[i]));
		if (!new)
		{
			free_split(numbers);
			return (0);
		}
		stack_add_back(stack, new);
		i++;
	}
	free_split(numbers);
	return (1);
}
