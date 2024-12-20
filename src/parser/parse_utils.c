/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvigara- <mvigara-@student.42school.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 15:45:18 by mvigara-          #+#    #+#             */
/*   Updated: 2024/12/19 09:39:26 by mvigara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Checks if a string contains only valid number characters
** Returns 1 if valid, 0 if invalid
*/
int	is_valid_input(char *str)
{
	int	i;

	i = 0;
	if (!str || !*str)
		return (0);
	while (ft_iswhitespace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]) && !ft_iswhitespace(str[i]))
			return (0);
		i++;
	}
	return (1);
}

/*
** Process a single argument string that might contain multiple numbers
** Returns 1 if successful, 0 if error
*/
static int	validate_and_convert_number(char *str, t_stack **stack_a)
{
	long	num;

	if (!is_valid_input(str))
		return (0);
	num = ft_atoll(str);
	if (num > INT_MAX || num < INT_MIN)
		return (0);
	stack_add_back(stack_a, stack_new((int)num));
	return (1);
}

static int	process_numbers_array(char **numbers, t_stack **stack_a)
{
	int	i;

	i = 0;
	while (numbers[i])
	{
		if (!validate_and_convert_number(numbers[i], stack_a))
		{
			ft_split_free(numbers);
			return (0);
		}
		i++;
	}
	ft_split_free(numbers);
	return (1);
}

static int	process_arg_string(char *str, t_stack **stack_a)
{
	char	**numbers;
	char	*trimmed;

	trimmed = ft_strtrim(str, " \t\n\v\f\r");
	if (!trimmed)
		return (0);
	numbers = ft_split(trimmed, ' ');
	free(trimmed);
	if (!numbers)
		return (0);
	return (process_numbers_array(numbers, stack_a));
}

/*
** Process all input arguments
** Returns 1 if successful, 0 if error
*/
int	process_input(int ac, char **av, t_stack **stack_a)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (!process_arg_string(av[i], stack_a))
			return (0);
		i++;
	}
	return (!check_duplicates(*stack_a));
}
