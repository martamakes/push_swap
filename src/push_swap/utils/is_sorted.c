/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvigara- <mvigara-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 01:02:19 by marta             #+#    #+#             */
/*   Updated: 2024/10/18 18:12:51 by mvigara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(int *numbers, int count)
{
	int	i;

	if (!numbers || count <= 1)
		return (1);
	i = 0;
	while (i < count - 1)
	{
		if (numbers[i] > numbers[i + 1])
			return (0);
		i++;
	}
	return (1);
}
