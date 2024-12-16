/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvigara- <mvigara-@student.42school.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 15:46:17 by mvigara-          #+#    #+#             */
/*   Updated: 2024/12/16 08:18:20 by mvigara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	free_split(char **split)
{
	int	i;

	if (!split)
		return ;
	i = 0;
	while (split[i])
		free(split[i++]);
	free(split);
}


static int	check_duplicate(t_stack *stack, int num)
{
	t_node	*curr;

	curr = stack->top;
	while (curr)
	{
		if (curr->value == num)
			return (1);
		curr = curr->next;
	}
	return (0);
}

static int	add_number(t_stack *stack, char *str)
{
	t_node		*new;
	long long	num;

	if (!is_valid_number(str))
		return (0);
	num = ft_atoll(str);
	if (check_duplicate(stack, (int)num))
		return (0);
	new = create_node((int)num);
	if (!new)
		return (0);
	if (!stack->top)
	{
		stack->top = new;
		stack->bottom = new;
	}
	else
	{
		new->prev = stack->bottom;
		stack->bottom->next = new;
		stack->bottom = new;
	}
	stack->size++;
	return (1);
}

t_stack	*parse_args(int argc, char **argv)
{
	t_stack	*stack;
	char	**split;
	int		i;
	int		j;

	if (argc < 2)
		return (NULL);
	stack = init_stack();
	if (!stack)
		return (NULL);
	i = 0;
	while (++i < argc)
	{
		if (!argv[i] || is_empty_or_spaces(argv[i]))
			return (free_stack(stack), NULL);
		split = ft_split(argv[i], ' ');
		if (!split)
			return (free_stack(stack), NULL);
		j = -1;
		while (split[++j])
			if (!add_number(stack, split[j]))
				return (free_split(split), free_stack(stack), NULL);
		free_split(split);
	}
	return (stack);
}
