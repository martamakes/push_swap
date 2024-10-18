/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvigara- <mvigara-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 12:41:10 by marta             #+#    #+#             */
/*   Updated: 2024/10/18 18:17:54 by mvigara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*handle_conversion(char ***tokens, int *argc, int count)
{
	int	*numbers;

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

int	*parse_args(int *argc, char **argv)
{
	char	***tokens;
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
	return (handle_conversion(tokens, argc, count));
}
