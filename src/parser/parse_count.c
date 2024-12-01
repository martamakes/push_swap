/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_count.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvigara- <mvigara-@student.42school.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 15:45:46 by mvigara-          #+#    #+#             */
/*   Updated: 2024/12/01 15:45:50 by mvigara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 #include "push_swap.h"

static int count_split_numbers(char **split)
{
    int count;

    count = 0;
    while (split[count])
        count++;
    return (count);
}

int count_numbers(char **argv)
{
    int     i;
    int     count;
    char    **split;

    count = 0;
    i = 1;
    while (argv[i])
    {
        split = ft_split(argv[i], ' ');
        if (!split)
            error_exit();
        count += count_split_numbers(split);
        free_split(split);
        i++;
    }
    return (count);
}
