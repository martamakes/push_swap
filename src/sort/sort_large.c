/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvigara- <mvigara-@student.42school.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 19:14:26 by mvigara-          #+#    #+#             */
/*   Updated: 2024/12/20 08:09:32 by mvigara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Main sorting function that chooses the appropriate algorithm
** based on the size of the stack
*/
void	sort_stack(t_stack **a, t_stack **b)
{
	int	size;

	if (!a || !*a || is_sorted(*a))
		return ;
	size = stack_size(*a);
	if (size == 2)
		sa(a);
	else if (size == 3)
		sort_three(a);
	else if (size < 150)
		sort_small(a, b, size);
	else
		turkish_sort(a, b);
}

/*
** Shifts the stack until the smallest number is at the top
** Uses the most efficient rotation direction based on position
*/
void	shift_stack(t_stack **stack)
{
	int	lowest_pos;
	int	size;

	if (!stack || !*stack)
		return ;
	size = stack_size(*stack);
	lowest_pos = get_min_pos(*stack);
	if (lowest_pos > size / 2)
	{
		while (lowest_pos < size)
		{
			rra(stack);
			lowest_pos++;
		}
	}
	else
	{
		while (lowest_pos > 0)
		{
			ra(stack);
			lowest_pos--;
		}
	}
}

/*
** Moves the cheapest number from stack a to stack b
*/
void	move_cheapest_to_b(t_stack **a, t_stack **b)
{
	t_stack	*cheapest;
	int		cost_a;
	int		cost_b;

	get_target_positions(*a, *b);
	get_cost(*a, *b);
	cheapest = get_cheapest(*a);
	cost_a = cheapest->cost_a;
	cost_b = cheapest->cost_b;
	do_rotations(a, b, cost_a, cost_b);
	pb(a, b);
}

/*
** Moves the cheapest number from stack b to stack a
*/
void	move_cheapest_to_a(t_stack **a, t_stack **b)
{
	t_stack	*cheapest;
	int		cost_a;
	int		cost_b;

	get_target_positions(*b, *a);
	get_cost(*b, *a);
	cheapest = get_cheapest(*b);
	cost_a = cheapest->cost_a;
	cost_b = cheapest->cost_b;
	do_rotations(a, b, cost_a, cost_b);
	pa(a, b);
}

/*
** Turkish sort algorithm implementation
*/
void	turkish_sort(t_stack **a, t_stack **b)
{
	// Inicialización: Push primeros dos números y ordenarlos
	pb(a, b);
	pb(a, b);
	if ((*b)->value < (*b)->next->value)
		sb(b);
	// Primera fase: Push al stack B manteniendo orden descendente
	while (stack_size(*a) > 3)
		move_cheapest_to_b(a, b);
	// Segunda fase: Ordenar los tres números restantes en A
	if (!is_sorted(*a))
		sort_three(a);
	// Tercera fase: Devolver números a A en orden
	while (*b)
		move_cheapest_to_a(a, b);
	// Fase final: Asegurar que el mínimo está arriba
	shift_stack(a);
}
