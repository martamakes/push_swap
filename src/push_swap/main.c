/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marta <marta@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 11:39:36 by marta             #+#    #+#             */
/*   Updated: 2024/09/16 12:25:06 by marta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
    t_stack *a;
    t_stack *b;

    if (argc < 2)
        return (0);
    //TODO parse_args
    //TODO validate_args
    //TODO init_stacks
    //TODO sort
    a = NULL;
    b = NULL;
    while(argv && *argv)
    {
        ft_printf("%s\n", *argv);
        argv++;
    }
    free_stacks(&a, &b);
    return (0);
}
