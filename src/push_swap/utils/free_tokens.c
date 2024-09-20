/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_tokens.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marta <marta@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 14:32:37 by marta             #+#    #+#             */
/*   Updated: 2024/09/20 16:19:25 by marta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void free_tokens(char ***tokens, int argc)
{
    int i;
    int j;

    i = 1;
    while (i < argc)
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
