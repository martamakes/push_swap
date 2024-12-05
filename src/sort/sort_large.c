/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvigara- <mvigara-@student.42school.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 08:52:39 by mvigara-          #+#    #+#             */
/*   Updated: 2024/12/05 09:50:34 by mvigara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// sort_large.c
void sort_large(t_stack *stack_a, t_stack *stack_b)
{
    t_chunk_info *chunk;

    if (!stack_a || !stack_b || stack_a->size <= 5)
        return ;
    if (is_sorted(stack_a))
        return ;
    chunk = init_chunk_info(stack_a);
    if (!chunk)
        error_exit();
    move_to_b(stack_a, stack_b, chunk);
    move_back_to_a(stack_a, stack_b);
    free_chunk_info(chunk);
}
