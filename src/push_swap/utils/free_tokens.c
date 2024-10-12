/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_tokens.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marta <marta@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 14:32:37 by marta             #+#    #+#             */
/*   Updated: 2024/10/13 00:46:32 by marta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_tokens(char ***tokens, int argc)
{
	int	i;
	int	j;

	if (!tokens)
		return ;
	i = 0;
	while (i < argc - 1)
	{
		if (tokens[i])
		{
			j = 0;
			while (tokens[i][j])
			{
				free(tokens[i][j]);
				j++;
			}
			free(tokens[i]);
		}
		i++;
	}
	free(tokens);
}
