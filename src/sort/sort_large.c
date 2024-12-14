/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvigara- <mvigara-@student.42school.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 19:14:26 by mvigara-          #+#    #+#             */
/*   Updated: 2024/12/14 19:14:28 by mvigara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    sort_large(t_stack *a, t_stack *b)
{
    t_chunk chunk;

    if (!a || !b || a->size <= 5)
        return ;

    // Inicializar información del chunk
    init_chunk_info(a, &chunk);

    // Fase 1: Empujar números a B en orden por chunks
    push_chunks_to_b(a, b, &chunk);

    // Fase 2: Ordenar los últimos 3 números en A
    sort_three(a);

    // Fase 3: Devolver números a A en orden
    push_back_to_a(a, b);
}
