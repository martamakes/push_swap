/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_numbers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marta <marta@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 13:11:06 by marta             #+#    #+#             */
/*   Updated: 2024/09/19 14:04:33 by marta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int count_quoted_numbers(const char *str)
{
    int count;
    int i;

    count = 0;
    i = 1;  // Start after the opening quote
    while (str[i] && str[i] != '"')
    {
        while (str[i] && ft_iswhitespace(str[i]))
            i++;
        if (str[i] && !ft_iswhitespace(str[i]))
        {
            count++;
            while (str[i] && !ft_iswhitespace(str[i]))
                i++;
        }
    }
    return (count);
}

int count_numbers(int argc, char **argv)
{
    int count;
    int i;

    count = 0;
    i = 1;
    while (i < argc)
    {
        if (argv[i][0] == '"')
            count += count_quoted_numbers(argv[i]);
        else
            count++;
        i++;
    }
    return (count);
}
