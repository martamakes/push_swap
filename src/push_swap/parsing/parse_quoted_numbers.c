/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_quoted_numbers.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marta <marta@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 13:24:17 by marta             #+#    #+#             */
/*   Updated: 2024/09/20 08:59:53 by marta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int parse_quoted_numbers(const char *str, int *numbers, int *index)
{
    int i;
    char *end;
    long num;

    i = 0;
    while (str[i])
    {
        while (str[i] && ft_iswhitespace(str[i]))
            i++;
        if (str[i])
        {
            num = ft_strtol(&str[i], &end, 10);
            if (end == &str[i] || num > INT_MAX || num < INT_MIN)
                return (0);
            numbers[(*index)++] = (int)num;
            i = end - str;
        }
    }
    return (1);
}