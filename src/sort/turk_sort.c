/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvigara- <mvigara-@student.42school.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 09:51:45 by mvigara-          #+#    #+#             */
/*   Updated: 2024/12/25 11:06:09 by mvigara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	turkish_sort(t_stack **a, t_stack **b)
{
	int	size;

	size = stack_size(*a);
	if (size <= 3)
		return (sort_three(a));
	pb(a, b);
	pb(a, b);
	if ((*b)->index < (*b)->next->index)
    {
		if ((*a)->index > (*a)->next->index &&
            ft_abs((*a)->index - (*b)->next->index) < 
            ft_abs((*a)->next->index - (*b)->next->index))
            ss(a, b);
        else
            sb(b);
    }
	while (size > 3)
	{
		get_target_positions(*a, *b);
		get_cost(*a, *b);
		move_cheapest_to_b(a, b);
		size--;
	}
	sort_three(a);
	while (*b)
	{
		get_target_positions_b(*b, *a);
		get_cost(*b, *a);
		move_cheapest_to_a(a, b);
	}
	shift_stack(a);
}
