/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marta <marta@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 14:24:26 by marta             #+#    #+#             */
/*   Updated: 2024/09/20 14:27:18 by marta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_valid_number(const char *str)
{
	int			i;
	long long	num;

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
	num = ft_atoll(str);
	return (num >= INT_MIN && num <= INT_MAX);
}

int	validate_and_count_numbers(char ***tokens, int *argc)
{
	int	count;
	int	i;
	int	j;

	count = 0;
	i = 1;
	while (i < *argc)
	{
		j = 0;
		while (tokens[i][j])
		{
			if (!is_valid_number(tokens[i][j]))
				return (-1);
			count++;
			j++;
		}
		i++;
	}
	*argc = count;
	return (count);
}
