/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_numbers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marta <marta@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 14:27:00 by marta             #+#    #+#             */
/*   Updated: 2024/09/20 16:20:34 by marta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*convert_to_numbers(char ***tokens, int count)
{
	int	*numbers;
	int	i;
	int	j;
	int	index;

	numbers = ft_calloc(count, sizeof(int));
	if (!numbers)
		return (NULL);
	i = 1;
	index = 0;
	while (tokens[i])
	{
		j = 0;
		while (tokens[i][j])
		{
			numbers[index] = ft_atoi(tokens[i][j]);
			index++;
			j++;
		}
		i++;
	}
	numbers[index] = 0;
	return (numbers);
}
