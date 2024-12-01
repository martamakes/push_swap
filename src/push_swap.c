/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvigara- <mvigara-@student.42school.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 15:29:46 by mvigara-          #+#    #+#             */
/*   Updated: 2024/12/01 15:30:32 by mvigara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// src/push_swap.c

#include "push_swap.h"

void    error_exit(void)
{
    ft_putstr_fd("Error\n", 2);
    exit(1);
}

static int is_valid_number(char *str)
{
    long num;
    char *endptr;

    num = ft_strtol(str, &endptr, 10);
    if (*endptr != '\0' || num > INT_MAX || num < INT_MIN)
        return (0);
    return (1);
}

static int count_numbers(char **argv)
{
    int i;
    int count;
    char **split;

    count = 0;
    i = 1;
    while (argv[i])
    {
        split = ft_split(argv[i], ' ');
        if (!split)
            error_exit();
        for (int j = 0; split[j]; j++)
            count++;
        i++;
        // Free split array
        for (int j = 0; split[j]; j++)
            free(split[j]);
        free(split);
    }
    return (count);
}

t_stack *parse_args(int argc, char **argv)
{
    t_stack *stack;
    char **split;
    int i;
    int pos;

    if (argc < 2)
        return (NULL);
    
    stack = malloc(sizeof(t_stack));
    if (!stack)
        error_exit();
    
    stack->size = count_numbers(argv);
    stack->numbers = malloc(sizeof(int) * stack->size);
    if (!stack->numbers)
    {
        free(stack);
        error_exit();
    }

    pos = 0;
    i = 1;
    while (argv[i])
    {
        split = ft_split(argv[i], ' ');
        if (!split)
        {
            free(stack->numbers);
            free(stack);
            error_exit();
        }
        for (int j = 0; split[j]; j++)
        {
            if (!is_valid_number(split[j]))
            {
                free(stack->numbers);
                free(stack);
                for (int k = 0; split[k]; k++)
                    free(split[k]);
                free(split);
                error_exit();
            }
            stack->numbers[pos++] = ft_atoi(split[j]);
        }
        for (int j = 0; split[j]; j++)
            free(split[j]);
        free(split);
        i++;
    }
    return (stack);
}

int main(int argc, char **argv)
{
    t_stack *stack;

    stack = parse_args(argc, argv);
    if (!stack)
        return (0);

    // Free memory before exit
    free(stack->numbers);
    free(stack);
    return (0);
}
