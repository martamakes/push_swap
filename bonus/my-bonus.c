/* ************************************************************************** */
/*                                                                            */
/*                            src//debug/                                           */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_debug.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvigara- <mvigara-@student.42school.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 08:27:56 by mvigara-          #+#    #+#             */
/*   Updated: 2024/12/20 09:07:03 by mvigara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	init_log(t_log *log)
{
	log->total_ops = 0;
	log->valid_ops = 0;
	log->invalid_ops = 0;
	log->last_op = NULL;
	log->debug_mode = getenv("DEBUG") != NULL;
}

void	log_operation(t_log *log, const char *op)
{
	if (!log || !op)
		return ;
	log->total_ops++;
	log->valid_ops++;
	log->last_op = (char *)op;
	if (log->debug_mode)
		ft_printf("DEBUG: Executed operation: %s\n", op);
}

void	print_stack(t_stack *stack, char stack_name)
{
	ft_printf("Stack %c: ", stack_name);
	while (stack)
	{
		ft_printf("%d ", stack->value);
		stack = stack->next;
	}
	ft_printf("\n");
}

void	print_debug_info(t_stack *a, t_stack *b, t_log *log)
{
	ft_printf("\n=== Debug Information ===\n");
	ft_printf("Total operations: %d\n", log->total_ops);
	ft_printf("Valid operations: %d\n", log->valid_ops);
	ft_printf("Invalid operations: %d\n", log->invalid_ops);
	if (log->last_op)
		ft_printf("Last operation: %s\n", log->last_op);
	else
		ft_printf("Last operation: none\n");
	ft_printf("\nFinal stack state:\n");
	print_stack(a, 'A');
	print_stack(b, 'B');
	ft_printf("======================\n");
}

/* ************************************************************************** */
/*                                                                            */
/*                            src//main/                                           */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvigara- <mvigara-@student.42school.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 08:26:42 by mvigara-          #+#    #+#             */
/*   Updated: 2024/12/20 09:06:50 by mvigara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int	process_instruction(char *line, t_stack **a, t_stack **b,
		t_log *log)
{
	if (!line)
		return (0);
	if (*line == '\0')
		return (0);
	return (execute_instruction(line, a, b, log));
}

static void	read_and_execute(t_stack **a, t_stack **b, t_log *log)
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
	t_stack	*a;
	t_stack	*b;
	t_log	log;

	if (!check_args(ac, av))
	{
		write(2, "Error\n", 6);
		return (1);
	}
	a = NULL;
	b = NULL;
	init_log(&log);
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

/* ************************************************************************** */
/*                                                                            */
/*                            src//operations/                                           */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_ops.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvigara- <mvigara-@student.42school.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 08:27:13 by mvigara-          #+#    #+#             */
/*   Updated: 2024/12/20 09:04:36 by mvigara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	execute_instruction(char *line, t_stack **a, t_stack **b, t_log *log)
{
	if (ft_strcmp(line, "sa\n") == 0)
		checker_sa(a, log);
	else if (ft_strcmp(line, "sb\n") == 0)
		checker_sb(b, log);
	else if (ft_strcmp(line, "ss\n") == 0)
		checker_ss(a, b, log);
	else if (ft_strcmp(line, "pa\n") == 0)
		checker_pa(a, b, log);
	else if (ft_strcmp(line, "pb\n") == 0)
		checker_pb(a, b, log);
	else if (ft_strcmp(line, "ra\n") == 0)
		checker_ra(a, log);
	else if (ft_strcmp(line, "rb\n") == 0)
		checker_rb(b, log);
	else if (ft_strcmp(line, "rr\n") == 0)
		checker_rr(a, b, log);
	else if (ft_strcmp(line, "rra\n") == 0)
		checker_rra(a, log);
	else if (ft_strcmp(line, "rrb\n") == 0)
		checker_rrb(b, log);
	else if (ft_strcmp(line, "rrr\n") == 0)
		checker_rrr(a, b, log);
	else
		return (0);
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_push_ops.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvigara- <mvigara-@student.42school.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 08:43:01 by mvigara-          #+#    #+#             */
/*   Updated: 2024/12/20 09:07:20 by mvigara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	push(t_stack **src, t_stack **dst)
{
	t_stack	*temp;

	if (!*src)
		return ;
	temp = (*src)->next;
	(*src)->next = *dst;
	*dst = *src;
	*src = temp;
}

void	checker_pa(t_stack **a, t_stack **b, t_log *log)
{
	push(b, a);
	log_operation(log, "pa");
}

void	checker_pb(t_stack **a, t_stack **b, t_log *log)
{
	push(a, b);
	log_operation(log, "pb");
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_rev_rot_ops.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvigara- <mvigara-@student.42school.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 08:45:03 by mvigara-          #+#    #+#             */
/*   Updated: 2024/12/20 09:07:39 by mvigara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	reverse_rotate(t_stack **stack)
{
	t_stack	*last;
	t_stack	*prev_last;

	if (!*stack || !(*stack)->next)
		return ;
	last = *stack;
	prev_last = NULL;
	while (last->next)
	{
		prev_last = last;
		last = last->next;
	}
	prev_last->next = NULL;
	last->next = *stack;
	*stack = last;
}

void	checker_rra(t_stack **a, t_log *log)
{
	reverse_rotate(a);
	log_operation(log, "rra");
}

void	checker_rrb(t_stack **b, t_log *log)
{
	reverse_rotate(b);
	log_operation(log, "rrb");
}

void	checker_rrr(t_stack **a, t_stack **b, t_log *log)
{
	reverse_rotate(a);
	reverse_rotate(b);
	log_operation(log, "rrr");
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_rotate_ops.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvigara- <mvigara-@student.42school.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 08:43:51 by mvigara-          #+#    #+#             */
/*   Updated: 2024/12/20 09:07:55 by mvigara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	rotate(t_stack **stack)
{
	t_stack	*first;
	t_stack	*last;

	if (!*stack || !(*stack)->next)
		return ;
	first = *stack;
	last = stack_last(*stack);
	*stack = first->next;
	first->next = NULL;
	last->next = first;
}

void	checker_ra(t_stack **a, t_log *log)
{
	rotate(a);
	log_operation(log, "ra");
}

void	checker_rb(t_stack **b, t_log *log)
{
	rotate(b);
	log_operation(log, "rb");
}

void	checker_rr(t_stack **a, t_stack **b, t_log *log)
{
	rotate(a);
	rotate(b);
	log_operation(log, "rr");
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_swap_ops.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvigara- <mvigara-@student.42school.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 08:41:44 by mvigara-          #+#    #+#             */
/*   Updated: 2024/12/20 09:08:10 by mvigara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	swap(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	second = (*stack)->next;
	first->next = second->next;
	second->next = first;
	*stack = second;
}

void	checker_sa(t_stack **a, t_log *log)
{
	swap(a);
	log_operation(log, "sa");
}

void	checker_sb(t_stack **b, t_log *log)
{
	swap(b);
	log_operation(log, "sb");
}

void	checker_ss(t_stack **a, t_stack **b, t_log *log)
{
	swap(a);
	swap(b);
	log_operation(log, "ss");
}

/* ************************************************************************** */
/*                                                                            */
/*                            src//utils/                                           */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvigara- <mvigara-@student.42school.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 08:33:49 by mvigara-          #+#    #+#             */
/*   Updated: 2024/12/20 08:34:05 by mvigara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	free_and_exit(t_stack **a, t_stack **b, int status)
{
	if (a)
		free_stack(a);
	if (b)
		free_stack(b);
	if (status)
		write(2, "Error\n", 6);
	exit(status);
}

int	check_number(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	is_valid_number_str(char *str)
{
	long	num;

	if (!check_number(str))
		return (0);
	num = ft_atoll(str);
	if (num > INT_MAX || num < INT_MIN)
		return (0);
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                            src//debug/                                           */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_debug.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvigara- <mvigara-@student.42school.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 08:27:56 by mvigara-          #+#    #+#             */
/*   Updated: 2024/12/20 09:07:03 by mvigara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	init_log(t_log *log)
{
	log->total_ops = 0;
	log->valid_ops = 0;
	log->invalid_ops = 0;
	log->last_op = NULL;
	log->debug_mode = getenv("DEBUG") != NULL;
}

void	log_operation(t_log *log, const char *op)
{
	if (!log || !op)
		return ;
	log->total_ops++;
	log->valid_ops++;
	log->last_op = (char *)op;
	if (log->debug_mode)
		ft_printf("DEBUG: Executed operation: %s\n", op);
}

void	print_stack(t_stack *stack, char stack_name)
{
	ft_printf("Stack %c: ", stack_name);
	while (stack)
	{
		ft_printf("%d ", stack->value);
		stack = stack->next;
	}
	ft_printf("\n");
}

void	print_debug_info(t_stack *a, t_stack *b, t_log *log)
{
	ft_printf("\n=== Debug Information ===\n");
	ft_printf("Total operations: %d\n", log->total_ops);
	ft_printf("Valid operations: %d\n", log->valid_ops);
	ft_printf("Invalid operations: %d\n", log->invalid_ops);
	if (log->last_op)
		ft_printf("Last operation: %s\n", log->last_op);
	else
		ft_printf("Last operation: none\n");
	ft_printf("\nFinal stack state:\n");
	print_stack(a, 'A');
	print_stack(b, 'B');
	ft_printf("======================\n");
}

/* ************************************************************************** */
/*                                                                            */
/*                            src//main/                                           */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvigara- <mvigara-@student.42school.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 08:26:42 by mvigara-          #+#    #+#             */
/*   Updated: 2024/12/20 09:06:50 by mvigara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int	process_instruction(char *line, t_stack **a, t_stack **b,
		t_log *log)
{
	if (!line)
		return (0);
	if (*line == '\0')
		return (0);
	return (execute_instruction(line, a, b, log));
}

static void	read_and_execute(t_stack **a, t_stack **b, t_log *log)
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
	t_stack	*a;
	t_stack	*b;
	t_log	log;

	if (!check_args(ac, av))
	{
		write(2, "Error\n", 6);
		return (1);
	}
	a = NULL;
	b = NULL;
	init_log(&log);
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

/* ************************************************************************** */
/*                                                                            */
/*                            src//operations/                                           */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_ops.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvigara- <mvigara-@student.42school.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 08:27:13 by mvigara-          #+#    #+#             */
/*   Updated: 2024/12/20 09:04:36 by mvigara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	execute_instruction(char *line, t_stack **a, t_stack **b, t_log *log)
{
	if (ft_strcmp(line, "sa\n") == 0)
		checker_sa(a, log);
	else if (ft_strcmp(line, "sb\n") == 0)
		checker_sb(b, log);
	else if (ft_strcmp(line, "ss\n") == 0)
		checker_ss(a, b, log);
	else if (ft_strcmp(line, "pa\n") == 0)
		checker_pa(a, b, log);
	else if (ft_strcmp(line, "pb\n") == 0)
		checker_pb(a, b, log);
	else if (ft_strcmp(line, "ra\n") == 0)
		checker_ra(a, log);
	else if (ft_strcmp(line, "rb\n") == 0)
		checker_rb(b, log);
	else if (ft_strcmp(line, "rr\n") == 0)
		checker_rr(a, b, log);
	else if (ft_strcmp(line, "rra\n") == 0)
		checker_rra(a, log);
	else if (ft_strcmp(line, "rrb\n") == 0)
		checker_rrb(b, log);
	else if (ft_strcmp(line, "rrr\n") == 0)
		checker_rrr(a, b, log);
	else
		return (0);
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_push_ops.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvigara- <mvigara-@student.42school.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 08:43:01 by mvigara-          #+#    #+#             */
/*   Updated: 2024/12/20 09:07:20 by mvigara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	push(t_stack **src, t_stack **dst)
{
	t_stack	*temp;

	if (!*src)
		return ;
	temp = (*src)->next;
	(*src)->next = *dst;
	*dst = *src;
	*src = temp;
}

void	checker_pa(t_stack **a, t_stack **b, t_log *log)
{
	push(b, a);
	log_operation(log, "pa");
}

void	checker_pb(t_stack **a, t_stack **b, t_log *log)
{
	push(a, b);
	log_operation(log, "pb");
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_rev_rot_ops.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvigara- <mvigara-@student.42school.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 08:45:03 by mvigara-          #+#    #+#             */
/*   Updated: 2024/12/20 09:07:39 by mvigara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	reverse_rotate(t_stack **stack)
{
	t_stack	*last;
	t_stack	*prev_last;

	if (!*stack || !(*stack)->next)
		return ;
	last = *stack;
	prev_last = NULL;
	while (last->next)
	{
		prev_last = last;
		last = last->next;
	}
	prev_last->next = NULL;
	last->next = *stack;
	*stack = last;
}

void	checker_rra(t_stack **a, t_log *log)
{
	reverse_rotate(a);
	log_operation(log, "rra");
}

void	checker_rrb(t_stack **b, t_log *log)
{
	reverse_rotate(b);
	log_operation(log, "rrb");
}

void	checker_rrr(t_stack **a, t_stack **b, t_log *log)
{
	reverse_rotate(a);
	reverse_rotate(b);
	log_operation(log, "rrr");
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_rotate_ops.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvigara- <mvigara-@student.42school.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 08:43:51 by mvigara-          #+#    #+#             */
/*   Updated: 2024/12/20 09:07:55 by mvigara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	rotate(t_stack **stack)
{
	t_stack	*first;
	t_stack	*last;

	if (!*stack || !(*stack)->next)
		return ;
	first = *stack;
	last = stack_last(*stack);
	*stack = first->next;
	first->next = NULL;
	last->next = first;
}

void	checker_ra(t_stack **a, t_log *log)
{
	rotate(a);
	log_operation(log, "ra");
}

void	checker_rb(t_stack **b, t_log *log)
{
	rotate(b);
	log_operation(log, "rb");
}

void	checker_rr(t_stack **a, t_stack **b, t_log *log)
{
	rotate(a);
	rotate(b);
	log_operation(log, "rr");
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_swap_ops.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvigara- <mvigara-@student.42school.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 08:41:44 by mvigara-          #+#    #+#             */
/*   Updated: 2024/12/20 09:08:10 by mvigara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	swap(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	second = (*stack)->next;
	first->next = second->next;
	second->next = first;
	*stack = second;
}

void	checker_sa(t_stack **a, t_log *log)
{
	swap(a);
	log_operation(log, "sa");
}

void	checker_sb(t_stack **b, t_log *log)
{
	swap(b);
	log_operation(log, "sb");
}

void	checker_ss(t_stack **a, t_stack **b, t_log *log)
{
	swap(a);
	swap(b);
	log_operation(log, "ss");
}

/* ************************************************************************** */
/*                                                                            */
/*                            src//utils/                                           */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvigara- <mvigara-@student.42school.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 08:33:49 by mvigara-          #+#    #+#             */
/*   Updated: 2024/12/20 08:34:05 by mvigara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	free_and_exit(t_stack **a, t_stack **b, int status)
{
	if (a)
		free_stack(a);
	if (b)
		free_stack(b);
	if (status)
		write(2, "Error\n", 6);
	exit(status);
}

int	check_number(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	is_valid_number_str(char *str)
{
	long	num;

	if (!check_number(str))
		return (0);
	num = ft_atoll(str);
	if (num > INT_MAX || num < INT_MIN)
		return (0);
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                            src//debug/                                           */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_debug.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvigara- <mvigara-@student.42school.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 08:27:56 by mvigara-          #+#    #+#             */
/*   Updated: 2024/12/20 09:07:03 by mvigara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	init_log(t_log *log)
{
	log->total_ops = 0;
	log->valid_ops = 0;
	log->invalid_ops = 0;
	log->last_op = NULL;
	log->debug_mode = getenv("DEBUG") != NULL;
}

void	log_operation(t_log *log, const char *op)
{
	if (!log || !op)
		return ;
	log->total_ops++;
	log->valid_ops++;
	log->last_op = (char *)op;
	if (log->debug_mode)
		ft_printf("DEBUG: Executed operation: %s\n", op);
}

void	print_stack(t_stack *stack, char stack_name)
{
	ft_printf("Stack %c: ", stack_name);
	while (stack)
	{
		ft_printf("%d ", stack->value);
		stack = stack->next;
	}
	ft_printf("\n");
}

void	print_debug_info(t_stack *a, t_stack *b, t_log *log)
{
	ft_printf("\n=== Debug Information ===\n");
	ft_printf("Total operations: %d\n", log->total_ops);
	ft_printf("Valid operations: %d\n", log->valid_ops);
	ft_printf("Invalid operations: %d\n", log->invalid_ops);
	if (log->last_op)
		ft_printf("Last operation: %s\n", log->last_op);
	else
		ft_printf("Last operation: none\n");
	ft_printf("\nFinal stack state:\n");
	print_stack(a, 'A');
	print_stack(b, 'B');
	ft_printf("======================\n");
}

/* ************************************************************************** */
/*                                                                            */
/*                            src//main/                                           */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvigara- <mvigara-@student.42school.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 08:26:42 by mvigara-          #+#    #+#             */
/*   Updated: 2024/12/20 09:06:50 by mvigara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int	process_instruction(char *line, t_stack **a, t_stack **b,
		t_log *log)
{
	if (!line)
		return (0);
	if (*line == '\0')
		return (0);
	return (execute_instruction(line, a, b, log));
}

static void	read_and_execute(t_stack **a, t_stack **b, t_log *log)
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
	t_stack	*a;
	t_stack	*b;
	t_log	log;

	if (!check_args(ac, av))
	{
		write(2, "Error\n", 6);
		return (1);
	}
	a = NULL;
	b = NULL;
	init_log(&log);
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

/* ************************************************************************** */
/*                                                                            */
/*                            src//operations/                                           */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_ops.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvigara- <mvigara-@student.42school.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 08:27:13 by mvigara-          #+#    #+#             */
/*   Updated: 2024/12/20 09:04:36 by mvigara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	execute_instruction(char *line, t_stack **a, t_stack **b, t_log *log)
{
	if (ft_strcmp(line, "sa\n") == 0)
		checker_sa(a, log);
	else if (ft_strcmp(line, "sb\n") == 0)
		checker_sb(b, log);
	else if (ft_strcmp(line, "ss\n") == 0)
		checker_ss(a, b, log);
	else if (ft_strcmp(line, "pa\n") == 0)
		checker_pa(a, b, log);
	else if (ft_strcmp(line, "pb\n") == 0)
		checker_pb(a, b, log);
	else if (ft_strcmp(line, "ra\n") == 0)
		checker_ra(a, log);
	else if (ft_strcmp(line, "rb\n") == 0)
		checker_rb(b, log);
	else if (ft_strcmp(line, "rr\n") == 0)
		checker_rr(a, b, log);
	else if (ft_strcmp(line, "rra\n") == 0)
		checker_rra(a, log);
	else if (ft_strcmp(line, "rrb\n") == 0)
		checker_rrb(b, log);
	else if (ft_strcmp(line, "rrr\n") == 0)
		checker_rrr(a, b, log);
	else
		return (0);
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_push_ops.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvigara- <mvigara-@student.42school.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 08:43:01 by mvigara-          #+#    #+#             */
/*   Updated: 2024/12/20 09:07:20 by mvigara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	push(t_stack **src, t_stack **dst)
{
	t_stack	*temp;

	if (!*src)
		return ;
	temp = (*src)->next;
	(*src)->next = *dst;
	*dst = *src;
	*src = temp;
}

void	checker_pa(t_stack **a, t_stack **b, t_log *log)
{
	push(b, a);
	log_operation(log, "pa");
}

void	checker_pb(t_stack **a, t_stack **b, t_log *log)
{
	push(a, b);
	log_operation(log, "pb");
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_rev_rot_ops.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvigara- <mvigara-@student.42school.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 08:45:03 by mvigara-          #+#    #+#             */
/*   Updated: 2024/12/20 09:07:39 by mvigara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	reverse_rotate(t_stack **stack)
{
	t_stack	*last;
	t_stack	*prev_last;

	if (!*stack || !(*stack)->next)
		return ;
	last = *stack;
	prev_last = NULL;
	while (last->next)
	{
		prev_last = last;
		last = last->next;
	}
	prev_last->next = NULL;
	last->next = *stack;
	*stack = last;
}

void	checker_rra(t_stack **a, t_log *log)
{
	reverse_rotate(a);
	log_operation(log, "rra");
}

void	checker_rrb(t_stack **b, t_log *log)
{
	reverse_rotate(b);
	log_operation(log, "rrb");
}

void	checker_rrr(t_stack **a, t_stack **b, t_log *log)
{
	reverse_rotate(a);
	reverse_rotate(b);
	log_operation(log, "rrr");
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_rotate_ops.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvigara- <mvigara-@student.42school.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 08:43:51 by mvigara-          #+#    #+#             */
/*   Updated: 2024/12/20 09:07:55 by mvigara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	rotate(t_stack **stack)
{
	t_stack	*first;
	t_stack	*last;

	if (!*stack || !(*stack)->next)
		return ;
	first = *stack;
	last = stack_last(*stack);
	*stack = first->next;
	first->next = NULL;
	last->next = first;
}

void	checker_ra(t_stack **a, t_log *log)
{
	rotate(a);
	log_operation(log, "ra");
}

void	checker_rb(t_stack **b, t_log *log)
{
	rotate(b);
	log_operation(log, "rb");
}

void	checker_rr(t_stack **a, t_stack **b, t_log *log)
{
	rotate(a);
	rotate(b);
	log_operation(log, "rr");
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_swap_ops.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvigara- <mvigara-@student.42school.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 08:41:44 by mvigara-          #+#    #+#             */
/*   Updated: 2024/12/20 09:08:10 by mvigara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	swap(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	second = (*stack)->next;
	first->next = second->next;
	second->next = first;
	*stack = second;
}

void	checker_sa(t_stack **a, t_log *log)
{
	swap(a);
	log_operation(log, "sa");
}

void	checker_sb(t_stack **b, t_log *log)
{
	swap(b);
	log_operation(log, "sb");
}

void	checker_ss(t_stack **a, t_stack **b, t_log *log)
{
	swap(a);
	swap(b);
	log_operation(log, "ss");
}

/* ************************************************************************** */
/*                                                                            */
/*                            src//utils/                                           */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvigara- <mvigara-@student.42school.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 08:33:49 by mvigara-          #+#    #+#             */
/*   Updated: 2024/12/20 08:34:05 by mvigara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	free_and_exit(t_stack **a, t_stack **b, int status)
{
	if (a)
		free_stack(a);
	if (b)
		free_stack(b);
	if (status)
		write(2, "Error\n", 6);
	exit(status);
}

int	check_number(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	is_valid_number_str(char *str)
{
	long	num;

	if (!check_number(str))
		return (0);
	num = ft_atoll(str);
	if (num > INT_MAX || num < INT_MIN)
		return (0);
	return (1);
}
