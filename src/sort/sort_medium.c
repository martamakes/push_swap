/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_medium.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvigara- <mvigara-@student.42school.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 15:56:06 by mvigara-          #+#    #+#             */
/*   Updated: 2024/12/03 08:16:36 by mvigara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_medium(t_stack *a, t_stack *b)
{
	int	total_chunks;
	int	i;

	if (!a || !b || a->size <= 1)
		return ;
	if (is_sorted(a))
		return ;

	// Definimos el número de chunks basado en el tamaño del stack
	if (a->size <= 100)
		total_chunks = 5;  // Para 100 números o menos
	else
		total_chunks = 10; // Para números más grandes

	// Enviamos números a B por chunks
	i = 0;
	while (i < total_chunks && !is_sorted(a))
	{
		push_optimal_chunk(a, b, i, total_chunks);
		i++;
	}

	// Devolvemos los números ordenados a A
	push_back_optimized(a, b);
}
