/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvigara- <mvigara-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 12:41:10 by marta             #+#    #+#             */
/*   Updated: 2024/09/23 20:07:54 by mvigara-         ###   ########.fr       */
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
		return (NULL);
	count = validate_and_count_numbers(tokens, argc);
	if (count == -1)
	{
		free_tokens(tokens, *argc);
		return (NULL);
	}
	numbers = convert_to_numbers(tokens, count);
	free_tokens(tokens, *argc);
	if (!numbers || !check_duplicates(numbers, count))
	{
		free(numbers);
		return (NULL);
	}
    numbers[count] = 0;
	return (numbers);
}
