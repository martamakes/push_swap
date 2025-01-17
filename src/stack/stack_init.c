/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvigara- <mvigara-@student.42school.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 15:46:40 by mvigara-          #+#    #+#             */
/*   Updated: 2025/01/17 18:55:13 by mvigara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Checks for duplicate values in the stack
** Returns 1 if duplicates are found, 0 otherwise
*/
int	check_duplicates(t_stack *stack)
{
	t_stack	*current;
	t_stack	*check;

	current = stack;
	while (current)
	{
		check = current->next;
		while (check)
		{
			if (current->value == check->value)
				return (1);
			check = check->next;
		}
		current = current->next;
	}
	return (0);
}

static t_stack  *get_min_node(t_stack *stack)
{
    t_stack *current;
    t_stack *min_node;
    int min_val;

    current = stack;
    min_node = NULL;
    min_val = INT_MAX;
    while (current)
    {
        if (current->index == -1 && current->value < min_val)
        {
            min_val = current->value;
            min_node = current;
        }
        current = current->next;
    }
    return (min_node);
}

void    index_stack(t_stack *stack)
{
    t_stack *current;
    int     size;
    int     i;

    if (!stack)
        return;
    size = stack_size(stack);
    i = 0;
    while (i < size)
    {
        current = get_min_node(stack);
        if (current)
            current->index = i;
        i++;
    }
    update_positions(stack);
    if (VISUALS)
    {
        ft_printf("\nFinal indexed stack:\n");
		print_stack_index(stack, 'A');
    }
}
