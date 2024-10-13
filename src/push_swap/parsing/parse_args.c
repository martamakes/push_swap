/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marta <marta@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 12:41:10 by marta             #+#    #+#             */
/*   Updated: 2024/10/13 16:16:51 by marta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*parse_args(int *argc, char **argv)
{
	char	***tokens;
	int		*numbers;
	int		count;

	tokens = tokenize_args(*argc, argv);
	if (!tokens)
	{
		ft_putstr_fd("Error\n", 2);
		return (NULL);
	}
	count = validate_and_count_numbers(tokens, argc);
	if (count <= 0)
	{
		free_tokens(tokens, *argc);
		return (NULL);
	}
	numbers = convert_to_numbers(tokens, count);
	free_tokens(tokens, *argc);
	if (!numbers || !check_duplicates(numbers, count))
	{
		free(numbers);
		ft_putstr_fd("Error\n", 2);
		return (NULL);
	}
	*argc = count;
	return (numbers);
}