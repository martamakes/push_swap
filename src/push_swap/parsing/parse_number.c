/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marta <marta@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 13:22:47 by marta             #+#    #+#             */
/*   Updated: 2024/09/20 09:02:17 by marta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

int parse_number(const char *str, int *number)
{
    char *end;
    long num;

    num = ft_strtol(str, &end, 10);
    if (*end != '\0' || num > INT_MAX || num < INT_MIN)
        return (0);
    *number = (int)num;
    return (1);
}

