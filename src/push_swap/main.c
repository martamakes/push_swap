/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marta <marta@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 11:39:36 by marta             #+#    #+#             */
/*   Updated: 2024/09/20 14:38:02 by marta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
    t_stack *a;
    t_stack *b;
    int *numbers;

    if (argc < 2)
        return (0);
    numbers = parse_args(&argc, argv);
    if (!numbers)
    {
        ft_putstr_fd("Error\n", 2);
        return (1);
    }
    //TODO: Comprobar si el vector está ya ordenado
    // TODO: init_stacks con numbers y count
    // TODO: sort
    free(numbers);
    free_stacks(&a, &b);
    return (0);
}
