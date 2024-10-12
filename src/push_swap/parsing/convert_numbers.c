/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_numbers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marta <marta@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 14:27:00 by marta             #+#    #+#             */
/*   Updated: 2024/10/13 00:42:11 by marta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*convert_to_numbers(char ***tokens, int count)
{
	int	*numbers;
	int	i;
	int	j;
	int	index;

	numbers = ft_calloc(count + 1, sizeof(int));
	if (!numbers)
		return (NULL);
	i = 0;
	index = 0;
	while (tokens[i] && index < count)
	{
		j = 0;
		while (tokens[i][j] && index < count)
		{
			numbers[index] = ft_atoi(tokens[i][j]);
			index++;
			j++;
		}
		i++;
	}
	numbers[count] = 0;
	return (numbers);
}
