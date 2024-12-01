/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvigara- <mvigara-@student.42school.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 15:46:17 by mvigara-          #+#    #+#             */
/*   Updated: 2024/12/01 17:06:38 by mvigara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int check_duplicates(t_stack *stack, int pos, int new_num)
{
    int i;

    i = 0;
    while (i < pos)
    {
        if (stack->numbers[i] == new_num)
            return (1);
        i++;
    }
    return (0);
}

static int add_number(t_stack *stack, char *str, int *pos)
{
    long long num;

    if (!is_valid_number(str))
        return (0);
    num = ft_atoll(str);
    if (check_duplicates(stack, *pos, (int)num))
        return (0);
    stack->numbers[(*pos)++] = (int)num;
    return (1);
}

static int process_split(char **split, t_stack *stack, int *pos)
{
    int j;

    j = 0;
    while (split[j])
    {
        if (!add_number(stack, split[j], pos))
            return (0);
        j++;
    }
    return (1);
}

static t_stack *init_and_validate(int count)
{
    t_stack *stack;

    stack = init_stack(count);
    if (!stack)
        error_exit();
    return (stack);
}

t_stack *parse_args(int argc, char **argv)
{
    t_stack *stack;
    char    **split;
    int     i;
    int     pos;

    if (argc < 2)
        return (NULL);
    stack = init_and_validate(count_numbers(argv));
    pos = 0;
    i = 1;
    while (argv[i])
    {
        split = ft_split(argv[i], ' ');
        if (!split || !process_split(split, stack, &pos))
        {
            free_stack(stack);
            free_split(split);
            error_exit();
        }
        free_split(split);
        i++;
    }
    stack->size = pos;
    return (stack);
}
