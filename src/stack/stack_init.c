/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvigara- <mvigara-@student.42school.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 15:46:40 by mvigara-          #+#    #+#             */
/*   Updated: 2024/12/01 17:49:25 by mvigara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack *init_stack(int value)
{
    t_stack *new;

    new = malloc(sizeof(t_stack));
    if (!new)
        error_exit();
    new->value = value;
    new->next = NULL;
    return (new);
}
