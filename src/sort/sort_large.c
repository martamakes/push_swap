/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvigara- <mvigara-@student.42school.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 19:14:26 by mvigara-          #+#    #+#             */
/*   Updated: 2024/12/15 05:25:53 by mvigara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    sort_large(t_stack *a, t_stack *b)
{
    t_chunk chunk;

    // Si tenemos 5 o menos números, usamos algoritmos específicos
    if (!a || !b || a->size <= 5)
        return ;
    
    // Para números entre 6 y 50, podríamos usar una estrategia intermedia
    if (a->size <= 50)
    {
        sort_medium(a, b);  // Nueva función a implementar
        return ;
    }

    // Para más de 50 números, usamos chunks
    init_chunk_info(a, &chunk);
    push_chunks_to_b(a, b, &chunk);
    sort_three(a, 'a');
    push_back(a, b);
    rotate_to_min(a); 
}
