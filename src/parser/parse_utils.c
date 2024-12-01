/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvigara- <mvigara-@student.42school.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 15:45:18 by mvigara-          #+#    #+#             */
/*   Updated: 2024/12/01 15:45:26 by mvigara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int is_valid_number(char *str)
{
    long    num;
    char    *endptr;

    num = ft_strtol(str, &endptr, 10);
    if (*endptr != '\0' || num > INT_MAX || num < INT_MIN)
        return (0);
    return (1);
}

void    free_split(char **split)
{
    int i;

    i = 0;
    while (split[i])
    {
        free(split[i]);
        i++;
    }
    free(split);
}
