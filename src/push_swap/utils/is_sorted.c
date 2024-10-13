/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marta <marta@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 01:02:19 by marta             #+#    #+#             */
/*   Updated: 2024/10/13 01:13:43 by marta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int is_sorted(int *numbers, int count)
{
    int i;

    if (!numbers || count <= 1)
        return (1);  // An empty array or single element is considered sorted
    i = 0;
    while (i < count - 1)
    {
        if (numbers[i] > numbers[i + 1])
            return (0);  // Found an out-of-order pair
        i++;
    }
    return (1);  // All elements are in ascending order
}
