/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_b_to_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvigara- <mvigara-@student.42school.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 10:57:18 by mvigara-          #+#    #+#             */
/*   Updated: 2024/12/25 11:20:07 by mvigara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_target_pos_b_to_a(t_stack *b_node, t_stack *stack_a)
{
    if (!stack_a)
        return (0);
    return (find_closest_bigger_position(b_node, stack_a));
}