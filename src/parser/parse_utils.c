/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvigara- <mvigara-@student.42school.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 15:45:18 by mvigara-          #+#    #+#             */
/*   Updated: 2024/12/17 12:04:36 by mvigara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// src/parser/parse_utils.c

#include "push_swap.h"

void    ft_split_free(char **split)
{
    int i;

    if (!split)
        return;
    i = 0;
    while (split[i])
    {
        free(split[i]);
        i++;
    }
    free(split);
}

/*
** Checks if a string contains only valid number characters
** Returns 1 if valid, 0 if invalid
*/
int    is_valid_input(char *str)
{
    int i;

    i = 0;
    if (!str || !*str)
        return (0);
    // Skip leading spaces
    while (ft_iswhitespace(str[i]))
        i++;
    // Handle sign if present
    if (str[i] == '-' || str[i] == '+')
        i++;
    // Must have at least one digit after sign
    if (!str[i])
        return (0);
    // Check all remaining characters are digits
    while (str[i])
    {
        if (!ft_isdigit(str[i]) && !ft_iswhitespace(str[i]))
            return (0);
        i++;
    }
    return (1);
}

/*
** Process a single argument string that might contain multiple numbers
** Returns 1 if successful, 0 if error
*/
static int process_arg_string(char *str, t_stack **stack_a)
{
    char    **numbers;
    char    *trimmed;
    int     i;
    long    num;

    trimmed = ft_strtrim(str, " \t\n\v\f\r");
    if (!trimmed)
        return (0);
    numbers = ft_split(trimmed, ' ');
    free(trimmed);
    if (!numbers)
        return (0);
    i = 0;
    while (numbers[i])
    {
        if (!is_valid_input(numbers[i]))
        {
            ft_split_free(numbers);
            return (0);
        }
        num = ft_atoll(numbers[i]);
        if (num > INT_MAX || num < INT_MIN)
        {
            ft_split_free(numbers);
            return (0);
        }
        stack_add_back(stack_a, stack_new((int)num));
        i++;
    }
    ft_split_free(numbers);
    return (1);
}

/*
** Process all input arguments
** Returns 1 if successful, 0 if error
*/
int    process_input(int ac, char **av, t_stack **stack_a)
{
    int i;

    i = 1;
    while (i < ac)
    {
        if (!process_arg_string(av[i], stack_a))
            return (0);
        i++;
    }
    return (!check_duplicates(*stack_a));
}
