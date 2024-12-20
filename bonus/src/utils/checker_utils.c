/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvigara- <mvigara-@student.42school.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 08:33:49 by mvigara-          #+#    #+#             */
/*   Updated: 2024/12/20 08:34:05 by mvigara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	free_and_exit(t_stack **a, t_stack **b, int status)
{
	if (a)
		free_stack(a);
	if (b)
		free_stack(b);
	if (status)
		write(2, "Error\n", 6);
	exit(status);
}

int	check_number(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	is_valid_number_str(char *str)
{
	long	num;

	if (!check_number(str))
		return (0);
	num = ft_atoll(str);
	if (num > INT_MAX || num < INT_MIN)
		return (0);
	return (1);
}
