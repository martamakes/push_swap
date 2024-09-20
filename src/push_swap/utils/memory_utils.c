/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marta <marta@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 13:18:33 by marta             #+#    #+#             */
/*   Updated: 2024/09/19 13:18:38 by marta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void *ft_calloc_wrapper(size_t count, size_t size)
{
    void *ptr;

    ptr = ft_calloc(count, size);
    if (!ptr)
        exit(1);
    return (ptr);
}
