/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvigara- <mvigara-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 14:24:26 by marta             #+#    #+#             */
/*   Updated: 2024/10/18 12:44:29 by mvigara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_valid_number(const char *str)
{
	int			i;
	long long	num;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		i++;
		if (str[i] == '-' || str[i] == '+')
			return (0);
	}
	if (!str[i])
		return (0);
	if (str[0] == '-' && str[1] == '-')
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	num = ft_atoll(str);
	return (num >= INT_MIN && num <= INT_MAX);
}

int	validate_and_count_numbers(char ***tokens, int *argc)
{
	int	count;
	int	i;
	int	j;

	count = 0;
	i = 0;
	while (tokens[i])
	{
		j = 0;
		while (tokens[i][j])
		{
			if (!is_valid_number(tokens[i][j]))
			{
				ft_putstr_fd("Error\n", 2);
				return (-1);
			}
			count++;
			j++;
		}
		i++;
	}
	*argc = count;
	return (count);
}
