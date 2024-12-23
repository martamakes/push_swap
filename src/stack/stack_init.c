/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvigara- <mvigara-@student.42school.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 15:46:40 by mvigara-          #+#    #+#             */
/*   Updated: 2024/12/23 22:42:46 by mvigara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

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

void    index_stack(t_stack *stack)
{
    t_stack *current;
    t_stack *tmp;
    int     size;
    int     min;
    int     index;

    size = stack_size(stack);
    index = 0;
    while (index < size)
    {
        min = INT_MAX;
        current = stack;
        while (current)
        {
            if (current->index == -1 && current->value <= min)
                min = current->value;
            current = current->next;
        }
        tmp = stack;
        while (tmp)
        {
            if (tmp->value == min && tmp->index == -1)
            {
                tmp->index = index;
                break;
            }
            tmp = tmp->next;
        }
        index++;
    }
}
