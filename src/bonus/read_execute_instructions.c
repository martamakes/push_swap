/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_execute_instructions.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvigara- <mvigara-@student.42school.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 11:34:12 by mvigara-          #+#    #+#             */
/*   Updated: 2025/01/19 17:40:05 by mvigara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static void	free_instructions(char **instructions, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		free(instructions[i]);
		i++;
	}
	free(instructions);
}

static char	**alloc_instructions_array(int *capacity)
{
	char	**instructions;

	*capacity = 10;
	instructions = malloc(sizeof(char *) * (*capacity));
	if (!instructions)
		return (NULL);
	return (instructions);
}

static char	**realloc_instructions(char **instructions, int *capacity)
{
	char	**new_instructions;

	*capacity *= 2;
	new_instructions = malloc(sizeof(char *) * (*capacity));
	if (!new_instructions)
		return (NULL);
	ft_memcpy(new_instructions, instructions, sizeof(char *) * (*capacity / 2));
	free(instructions);
	return (new_instructions);
}

static int	execute_buffered_instructions(t_stack **stack_a, t_stack **stack_b,
		char **instructions, int instruction_count)
{
	int	i;

	i = 0;
	while (i < instruction_count)
	{
		if (!process_instruction(stack_a, stack_b, instructions[i]))
		{
			free_instructions(instructions, instruction_count);
			return (0);
		}
		i++;
	}
	free_instructions(instructions, instruction_count);
	return (is_sorted(*stack_a) && !*stack_b);
}

int	read_and_execute_instructions(t_stack **stack_a, t_stack **stack_b)
{
	char	*line;
	char	**instructions;
	int		instruction_count;
	int		instructions_capacity;

	instructions = alloc_instructions_array(&instructions_capacity);
	if (!instructions)
		error_exit(stack_a, stack_b);
	instruction_count = 0;
	while (1)
	{
		line = get_next_line(0);
		if (!line)
			break ;
		if (instruction_count >= instructions_capacity)
		{
			instructions = realloc_instructions(instructions,
					&instructions_capacity);
			if (!instructions)
			{
				free(line);
				error_exit(stack_a, stack_b);
			}
		}
		instructions[instruction_count] = line;
		instruction_count++;
	}
	return (execute_buffered_instructions(stack_a, stack_b, instructions,
			instruction_count));
}
