/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marta <marta@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 12:41:10 by marta             #+#    #+#             */
/*   Updated: 2024/09/20 08:59:24 by marta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include "push_swap.h"

static int parse_single_arg(char *arg, int *numbers, int *index)
{
    if (arg[0] == '"')
        return (parse_quoted_numbers(arg, numbers, index));
    if (!parse_number(arg, &numbers[*index]))
        return (0);
    (*index)++;
    return (1);
}

static int parse_all_args(int argc, char **argv, int *numbers)
{
    int i;
    int index;

    i = 1;
    index = 0;
    while (i < argc)
    {
        if (!parse_single_arg(argv[i], numbers, &index))
            return (0);
        i++;
    }
    return (1);
}

int *parse_args(int argc, char **argv, int *count)
{
    int *numbers;

    *count = count_numbers(argc, argv);
    numbers = ft_calloc(*count, sizeof(int));
    if (!numbers)
        return (NULL);
    if (!parse_all_args(argc, argv, numbers) || !check_duplicates(numbers, *count))
    {
        free(numbers);
        return (NULL);
    }
    return (numbers);
}
