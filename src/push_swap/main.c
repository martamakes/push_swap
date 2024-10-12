/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marta <marta@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 11:39:36 by marta             #+#    #+#             */
/*   Updated: 2024/10/13 00:54:00 by marta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_parsed_numbers(int *numbers, int count)
{
	int	i;

	if (!numbers || count <= 0)
	{
		ft_printf("No valid numbers parsed.\n");
		return ;
	}
	ft_printf("Parsed numbers: ");
	i = 0;
	while (i < count)
	{
		ft_printf("%d", numbers[i]);
		if (i < count - 1)
			ft_printf(" ");
		i++;
	}
	ft_printf("\n");
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	int		*numbers;

	if (argc < 2)
		return (0);
	numbers = parse_args(&argc, argv);
	if (!numbers)
		return (1);
	print_parsed_numbers(numbers, argc);
	// TODO: Comprobar si el vector está ya ordenado o es sólo un número
	// TODO: init_stacks con numbers y count
	// TODO: sort
	a = NULL;
	b = NULL;
	free(numbers);
	free_stacks(&a, &b);
	return (0);
}
