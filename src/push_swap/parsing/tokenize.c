/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marta <marta@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 14:20:45 by marta             #+#    #+#             */
/*   Updated: 2024/09/20 16:37:07 by marta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_quoted(char *str)
{
	return (str[0] == '"' && str[ft_strlen(str) - 1] == '"');
}

static char	**tokenize_arg(char *arg)
{
	char	**tokens;

	if (is_quoted(arg))
	{
		arg[ft_strlen(arg) - 1] = '\0';
		tokens = ft_split(arg + 1, ' ');
	}
	else
		tokens = ft_split(arg, ' ');
	tokens[ft_strlen(*tokens)] = NULL;
	return (tokens);
}

char	***tokenize_args(int argc, char **argv)
{
	char	***tokens;
	int		i;

	tokens = (char ***)ft_calloc(argc, sizeof(char **));
	if (!tokens)
		return (NULL);
	i = 1;
	while (i < argc)
	{
		tokens[i] = tokenize_arg(argv[i]);
		if (!tokens[i])
		{
			free_tokens(tokens, i);
			return (NULL);
		}
		i++;
	}
	tokens[argc - 1] = NULL;
	return (tokens);
}
