/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvigara- <mvigara-@student.42school.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 08:26:42 by mvigara-          #+#    #+#             */
/*   Updated: 2024/12/20 08:31:57 by mvigara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../bonus/inc/checker.h"

static int	process_instruction(char *line, t_stack **a, t_stack **b,
		t_logger *log)
{
	if (!line)
		return (0);
	if (*line == '\0')
		return (0);
	return (execute_instruction(line, a, b, log));
}

static void	read_and_execute(t_stack **a, t_stack **b, t_logger *log)
{
	char	*line;

	while (1)
	{
		line = get_next_line(0);
		if (!line)
			break ;
		if (!process_instruction(line, a, b, log))
		{
			free(line);
			free_and_exit(a, b, 1);
		}
		free(line);
	}
}

static int	check_args(int ac, char **av)
{
	int	i;
	int	j;

	if (ac < 2)
		return (0);
	i = 1;
	while (i < ac)
	{
		j = 0;
		while (av[i][j])
		{
			if (!ft_isdigit(av[i][j]) && av[i][j] != '-' && av[i][j] != '+'
				&& !ft_iswhitespace(av[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static void	print_result(t_stack *a, t_stack *b)
{
	if (is_sorted(a) && !b)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}

int	main(int ac, char **av)
{
	t_stack		*a;
	t_stack		*b;
	t_logger	log;

	if (!check_args(ac, av))
	{
		write(2, "Error\n", 6);
		return (1);
	}
	a = NULL;
	b = NULL;
	init_logger(&log);
	if (!process_input(ac, av, &a))
	{
		free_stack(&a);
		write(2, "Error\n", 6);
		return (1);
	}
	read_and_execute(&a, &b, &log);
	print_result(a, b);
	if (log.debug_mode)
		print_debug_info(a, b, &log);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
