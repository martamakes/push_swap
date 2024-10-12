/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marta <marta@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 14:20:45 by marta             #+#    #+#             */
/*   Updated: 2024/10/13 00:41:28 by marta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_quoted(const char *str)
{
	return ((str[0] == '"' && str[ft_strlen(str) - 1] == '"') ||
			(str[0] == '\'' && str[ft_strlen(str) - 1] == '\''));
}

static char	**tokenize_arg(char *arg)
{
	char	**tokens;
	int		token_count;

	if (is_quoted(arg))
	{
		arg[ft_strlen(arg) - 1] = '\0';
		arg++;
	}
	tokens = ft_split(arg, ' ');
	if (!tokens)
		return (NULL);
	token_count = 0;
	while (tokens[token_count])
		token_count++;
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
		tokens[i - 1] = tokenize_arg(argv[i]);
		if (!tokens[i - 1])
		{
			free_tokens(tokens, i - 1);
			return (NULL);
		}
		i++;
	}
	tokens[argc - 1] = NULL;
	return (tokens);
}
