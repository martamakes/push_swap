/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester_parsing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marta <marta@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 13:52:00 by marta             #+#    #+#             */
/*   Updated: 2024/09/20 08:58:18 by marta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void test_parse_args(int argc, char **argv)
{
    int count;
    int *numbers = parse_args(argc, argv, &count);

    if (numbers == NULL)
    {
        printf("Error: Invalid input\n");
        return;
    }

    printf("Parsed %d numbers:\n", count);
    for (int i = 0; i < count; i++)
    {
        printf("%d ", numbers[i]);
    }
    printf("\n");

    free(numbers);
}

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        printf("Usage: %s [numbers...]\n", argv[0]);
        return 1;
    }
    test_parse_args(argc, argv);
    return 0;
}
