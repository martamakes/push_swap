/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvigara- <mvigara-@student.42school.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 15:46:17 by mvigara-          #+#    #+#             */
/*   Updated: 2024/12/02 08:00:21 by mvigara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int process_split(char **split, t_stack *stack)
{
    int j;

    if (!split)
        return (0);
    j = 0;
    while (split[j])
    {
        if (!add_number(stack, split[j]))
        {
            free_split(split);
            return (0);
        }
        j++;
    }
    return (1);
}

t_stack *parse_args(int argc, char **argv)
{
    t_stack *stack;
    char    **split;
    int     i;

    if (argc < 2)
        return (NULL);
    stack = init_stack();
    if (!stack)
        return (NULL);
    i = 1;
    while (argv[i])
    {
        split = ft_split(argv[i], ' ');
        if (!process_split(split, stack))
        {
            free_stack(stack);
            return (NULL);
        }
        free_split(split);
        i++;
    }
    return (stack);
}
