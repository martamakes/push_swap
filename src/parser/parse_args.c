/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvigara- <mvigara-@student.42school.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 15:46:17 by mvigara-          #+#    #+#             */
/*   Updated: 2024/12/01 15:53:28 by mvigara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void process_split(char **split, t_stack *stack, int *pos)
{
    int j;

    j = 0;
    while (split[j])
    {
        if (!is_valid_number(split[j]))
        {
            free_split(split);
            free_stack(stack);
            error_exit();
        }
        stack->numbers[(*pos)++] = ft_atoi(split[j]);
        j++;
    }
}

t_stack *parse_args(int argc, char **argv)
{
    t_stack *stack;
    char    **split;
    int     i;
    int     pos;

    if (argc < 2)
        return (NULL);
    stack = init_stack(count_numbers(argv));
    pos = 0;
    i = 1;
    while (argv[i])
    {
        split = ft_split(argv[i], ' ');
        if (!split)
        {
            free_stack(stack);
            error_exit();
        }
        process_split(split, stack, &pos);
        free_split(split);
        i++;
    }
    return (stack);
}
