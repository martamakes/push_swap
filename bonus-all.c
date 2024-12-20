/* ************************************************************************** */
/*                                                                            */
/*                            src//debug/                                           */
/*                                                                            */
/* ************************************************************************** */


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stacks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvigara- <mvigara-@student.42school.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 07:25:00 by mvigara-          #+#    #+#             */
/*   Updated: 2024/12/18 08:35:50 by mvigara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_debug_str(char *str)
{
	if (!VISUALS)
		return ;
	write(1, "\033[0;90m", 7);
	write(1, str, ft_strlen(str));
	write(1, "\033[0m", 4);
}

void	print_debug_nbr(int n)
{
	if (!VISUALS)
		return ;
	write(1, "\033[0;90m", 7);
	ft_putnbr_fd(n, 1);
	write(1, "\033[0m", 4);
}

void	print_debug_char(char c)
{
	if (!VISUALS)
		return ;
	write(1, "\033[0;90m", 7);
	write(1, &c, 1);
	write(1, "\033[0m", 4);
}

void	print_stacks(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*temp_a;
	t_stack	*temp_b;

	if (!VISUALS)
		return ;
	temp_a = stack_a;
	temp_b = stack_b;
	print_debug_str("Stack A: ");
	while (temp_a)
	{
		print_debug_nbr(temp_a->value);
		temp_a = temp_a->next;
		if (temp_a)
			print_debug_char(' ');
	}
	print_debug_char('\n');
	print_debug_str("Stack B: ");
	while (temp_b)
	{
		print_debug_nbr(temp_b->value);
		temp_b = temp_b->next;
		if (temp_b)
			print_debug_char(' ');
	}
	print_debug_str("\n");
}

void	print_one(t_stack *stack, char stack_name)
{
	t_stack	*temp;

	if (!VISUALS)
		return ;
	temp = stack;
	print_debug_str("Stack ");
	print_debug_char(stack_name);
	print_debug_str(": ");
	while (temp)
	{
		print_debug_nbr(temp->value);
		temp = temp->next;
		if (temp)
			print_debug_char(' ');
	}
	print_debug_str("\n");
}

/* ************************************************************************** */
/*                                                                            */
/*                            src//error/                                           */
/*                                                                            */
/* ************************************************************************** */


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvigara- <mvigara-@student.42school.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 15:44:56 by mvigara-          #+#    #+#             */
/*   Updated: 2024/12/19 09:39:34 by mvigara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_exit(t_stack **stack_a, t_stack **stack_b)
{
	if (stack_a != NULL)
		free_stack(stack_a);
	if (stack_b != NULL)
		free_stack(stack_b);
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

void	ft_split_free(char **split)
{
	int	i;

	if (!split)
		return ;
	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

/* ************************************************************************** */
/*                                                                            */
/*                            src//main/                                           */
/*                                                                            */
/* ************************************************************************** */


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvigara- <mvigara-@student.42school.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 15:44:33 by mvigara-          #+#    #+#             */
/*   Updated: 2024/12/19 08:44:29 by mvigara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *stack)
{
	if (!stack)
		return (1);
	while (stack->next)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

static void	push_swap(t_stack **stack_a, t_stack **stack_b)
{
	if (is_sorted(*stack_a))
		return ;
	sort_stack(stack_a, stack_b);
}

static void	get_numbers(char *av, t_stack **stack_a)
{
	char	**numbers;
	long	num;
	int		i;

	numbers = ft_split(av, ' ');
	if (!numbers)
		error_exit(stack_a, NULL);
	i = 0;
	while (numbers[i])
	{
		if (!is_valid_input(numbers[i]))
		{
			ft_split_free(numbers);
			error_exit(stack_a, NULL);
		}
		num = ft_atoll(numbers[i]);
		if (num > INT_MAX || num < INT_MIN)
		{
			ft_split_free(numbers);
			error_exit(stack_a, NULL);
		}
		stack_add_back(stack_a, stack_new((int)num));
		free(numbers[i++]);
	}
	free(numbers);
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		i;

	if (ac < 2)
		return (0);
	stack_a = NULL;
	stack_b = NULL;
	i = 1;
	while (i < ac)
		get_numbers(av[i++], &stack_a);
	if (!stack_a || check_duplicates(stack_a))
		error_exit(&stack_a, NULL);
	if (VISUALS)
	{
		print_debug_str("Initial state:\n");
		print_stacks(stack_a, stack_b);
	}
	if (!is_sorted(stack_a))
		push_swap(&stack_a, &stack_b);
	free_stack(&stack_a);
	free_stack(&stack_b);
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
/*   push_ops.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvigara- <mvigara-@student.42school.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 08:20:20 by mvigara-          #+#    #+#             */
/*   Updated: 2024/12/18 08:36:05 by mvigara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Moves the first element from source stack to the top
** of destination stack. Does nothing if source is empty.
*/
static void	push(t_stack **src, t_stack **dst)
{
	t_stack	*tmp;

	if (!*src)
		return ;
	tmp = (*src)->next;
	(*src)->next = *dst;
	*dst = *src;
	*src = tmp;
}

/*
** pa (push a): Takes the first element of stack b
** and puts it at the top of stack a.
** Does nothing if b is empty.
*/
void	pa(t_stack **stack_a, t_stack **stack_b)
{
	push(stack_b, stack_a);
	ft_putstr_fd("pa\n", 1);
	if (VISUALS)
	{
		print_debug_str("After pa:\n");
		print_stacks(*stack_a, *stack_b);
	}
}

/*
** pb (push b): Takes the first element of stack a
** and puts it at the top of stack b.
** Does nothing if a is empty.
*/
void	pb(t_stack **stack_a, t_stack **stack_b)
{
	push(stack_a, stack_b);
	ft_putstr_fd("pb\n", 1);
	if (VISUALS)
	{
		print_debug_str("After pb:\n");
		print_stacks(*stack_a, *stack_b);
	}
}


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_ops.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvigara- <mvigara-@student.42school.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 08:36:43 by mvigara-          #+#    #+#             */
/*   Updated: 2024/12/18 08:36:21 by mvigara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Shifts down all elements of a stack by 1.
** The last element becomes the first one.
*/
static void	reverse_rotate(t_stack **stack)
{
	t_stack	*last;
	t_stack	*prelast;
	t_stack	*tmp;

	if (!*stack || !(*stack)->next)
		return ;
	tmp = *stack;
	prelast = *stack;
	while (prelast->next->next)
		prelast = prelast->next;
	last = prelast->next;
	prelast->next = NULL;
	last->next = tmp;
	*stack = last;
}

/*
** rra (reverse rotate a): Shifts down all elements of
** stack a by 1. The last element becomes the first one.
*/
void	rra(t_stack **stack_a)
{
	reverse_rotate(stack_a);
	ft_putstr_fd("rra\n", 1);
	if (VISUALS)
	{
		print_debug_str("After rra:\n");
		print_one(*stack_a, 'A');
	}
}

/*
** rrb (reverse rotate b): Shifts down all elements of
** stack b by 1. The last element becomes the first one.
*/
void	rrb(t_stack **stack_b)
{
	reverse_rotate(stack_b);
	ft_putstr_fd("rrb\n", 1);
	if (VISUALS)
	{
		print_debug_str("After rrb:\n");
		print_one(*stack_b, 'B');
	}
}

/*
** rrr: rra and rrb at the same time.
*/
void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	ft_putstr_fd("rrr\n", 1);
	if (VISUALS)
	{
		print_debug_str("After rrr:\n");
		print_stacks(*stack_a, *stack_b);
	}
}


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_ops.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvigara- <mvigara-@student.42school.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 08:33:49 by mvigara-          #+#    #+#             */
/*   Updated: 2024/12/18 08:36:37 by mvigara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Shifts up all elements of a stack by 1.
** The first element becomes the last one.
*/
static void	rotate(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*last;

	if (!*stack || !(*stack)->next)
		return ;
	tmp = *stack;
	*stack = (*stack)->next;
	last = stack_last(*stack);
	tmp->next = NULL;
	last->next = tmp;
}

/*
** ra (rotate a): Shifts up all elements of stack a by 1.
** The first element becomes the last one.
*/
void	ra(t_stack **stack_a)
{
	rotate(stack_a);
	ft_putstr_fd("ra\n", 1);
	if (VISUALS)
	{
		print_debug_str("After ra:\n");
		print_one(*stack_a, 'A');
	}
}

/*
** rb (rotate b): Shifts up all elements of stack b by 1.
** The first element becomes the last one.
*/
void	rb(t_stack **stack_b)
{
	rotate(stack_b);
	ft_putstr_fd("rb\n", 1);
	if (VISUALS)
	{
		print_debug_str("After rb:\n");
		print_one(*stack_b, 'B');
	}
}

/*
** rr: ra and rb at the same time.
*/
void	rr(t_stack **stack_a, t_stack **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	ft_putstr_fd("rr\n", 1);
	if (VISUALS)
	{
		print_debug_str("After pa:\n");
		print_stacks(*stack_a, *stack_b);
	}
}


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_ops.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvigara- <mvigara-@student.42school.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 08:09:17 by mvigara-          #+#    #+#             */
/*   Updated: 2024/12/18 08:36:59 by mvigara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Swaps the first two elements of a stack.
** Does nothing if there are less than 2 elements.
*/
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

/*
** sa (swap a): Swaps the top two elements of stack a.
** Does nothing if there's one or no elements.
*/
void	sa(t_stack **stack_a)
{
	swap(stack_a);
	ft_printf("sa\n");
	if (VISUALS)
	{
		print_debug_str("After sa:\n");
		print_one(*stack_a, 'A');
	}
}

/*
** sb (swap b): Swaps the top two elements of stack b.
** Does nothing if there's one or no elements.
*/
void	sb(t_stack **stack_b)
{
	swap(stack_b);
	ft_putstr_fd("sb\n", 1);
	if (VISUALS)
	{
		print_debug_str("After sb:\n");
		print_one(*stack_b, 'B');
	}
}

/*
** ss: sa and sb at the same time.
*/
void	ss(t_stack **stack_a, t_stack **stack_b)
{
	swap(stack_a);
	swap(stack_b);
	ft_putstr_fd("ss\n", 1);
	if (VISUALS)
	{
		print_debug_str("After ss:\n");
		print_stacks(*stack_a, *stack_b);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                            src//parser/                                           */
/*                                                                            */
/* ************************************************************************** */


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvigara- <mvigara-@student.42school.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 15:45:18 by mvigara-          #+#    #+#             */
/*   Updated: 2024/12/19 09:39:26 by mvigara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Checks if a string contains only valid number characters
** Returns 1 if valid, 0 if invalid
*/
int	is_valid_input(char *str)
{
	int	i;

	i = 0;
	if (!str || !*str)
		return (0);
	while (ft_iswhitespace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]) && !ft_iswhitespace(str[i]))
			return (0);
		i++;
	}
	return (1);
}

/*
** Process a single argument string that might contain multiple numbers
** Returns 1 if successful, 0 if error
*/
static int	validate_and_convert_number(char *str, t_stack **stack_a)
{
	long	num;

	if (!is_valid_input(str))
		return (0);
	num = ft_atoll(str);
	if (num > INT_MAX || num < INT_MIN)
		return (0);
	stack_add_back(stack_a, stack_new((int)num));
	return (1);
}

static int	process_numbers_array(char **numbers, t_stack **stack_a)
{
	int	i;

	i = 0;
	while (numbers[i])
	{
		if (!validate_and_convert_number(numbers[i], stack_a))
		{
			ft_split_free(numbers);
			return (0);
		}
		i++;
	}
	ft_split_free(numbers);
	return (1);
}

static int	process_arg_string(char *str, t_stack **stack_a)
{
	char	**numbers;
	char	*trimmed;

	trimmed = ft_strtrim(str, " \t\n\v\f\r");
	if (!trimmed)
		return (0);
	numbers = ft_split(trimmed, ' ');
	free(trimmed);
	if (!numbers)
		return (0);
	return (process_numbers_array(numbers, stack_a));
}

/*
** Process all input arguments
** Returns 1 if successful, 0 if error
*/
int	process_input(int ac, char **av, t_stack **stack_a)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (!process_arg_string(av[i], stack_a))
			return (0);
		i++;
	}
	return (!check_duplicates(*stack_a));
}

/* ************************************************************************** */
/*                                                                            */
/*                            src//sort/                                           */
/*                                                                            */
/* ************************************************************************** */


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_pos.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvigara- <mvigara-@student.42school.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 08:56:36 by mvigara-          #+#    #+#             */
/*   Updated: 2024/12/19 09:22:38 by mvigara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_pos(t_stack *stack, int value)
{
	int	pos;

	pos = 0;
	while (stack)
	{
		if (stack->value == value)
			return (pos);
		pos++;
		stack = stack->next;
	}
	return (0);
}

/*
** Finds the position where a number from stack b should be inserted in stack a
** while maintaining ascending order
** Returns the position in stack a where the value should be placed
*/
static int	find_target_position_b_to_a(t_stack *a, int value)
{
	t_stack	*current;
	int		closest_smaller;
	int		closest_bigger;
	int		target_pos;

	closest_smaller = INT_MIN;
	closest_bigger = INT_MAX;
	current = a;
	target_pos = 0;
	while (current)
	{
		if (current->value < value && current->value > closest_smaller)
		{
			closest_smaller = current->value;
			target_pos = current->pos + 1;
		}
		if (current->value > value && current->value < closest_bigger)
			closest_bigger = current->value;
		current = current->next;
	}
	if (closest_bigger == INT_MAX && closest_smaller == INT_MIN)
		return (0);
	if (closest_bigger == INT_MAX)
		return (target_pos);
	return (find_pos(a, closest_bigger));
}

/*
** Finds the position where a number from stack a should be inserted in stack b
** to maintain order and minimize future moves
** Returns the position in stack b where the value should be placed
*/
static int	find_target_position_a_to_b(t_stack *b, int value)
{
	t_stack	*current;
	int		closest_smaller;
	int		closest_bigger;

	if (!b)
		return (0);
	closest_smaller = INT_MIN;
	closest_bigger = INT_MAX;
	current = b;
	while (current)
	{
		if (current->value < value && current->value > closest_smaller)
			closest_smaller = current->value;
		if (current->value > value && current->value < closest_bigger)
			closest_bigger = current->value;
		current = current->next;
	}
	if (closest_bigger != INT_MAX)
		return (find_pos(b, closest_bigger));
	if (closest_smaller != INT_MIN)
		return ((find_pos(b, closest_smaller) + 1) % stack_size(b));
	return (0);
}

/*
** General function that finds target position based on direction
** direction = 1: moving from A to B
** direction = 0: moving from B to A
*/
int	find_target_position(t_stack *src, t_stack *dst, int value)
{
	static t_stack	*last_src = NULL;

	if (src != last_src)
	{
		last_src = src;
		if (src && last_src && src->value == last_src->value)
			return (find_target_position_b_to_a(dst, value));
	}
	return (find_target_position_a_to_b(dst, value));
}


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotations.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvigara- <mvigara-@student.42school.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 08:26:40 by mvigara-          #+#    #+#             */
/*   Updated: 2024/12/19 08:32:15 by mvigara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	do_same_rotations(t_stack **a, t_stack **b, int *cost_a,
		int *cost_b)
{
	while (*cost_a > 0 && *cost_b > 0)
	{
		rr(a, b);
		(*cost_a)--;
		(*cost_b)--;
	}
	while (*cost_a < 0 && *cost_b < 0)
	{
		rrr(a, b);
		(*cost_a)++;
		(*cost_b)++;
	}
}

static void	do_a_rotations(t_stack **a, int *cost_a)
{
	while (*cost_a > 0)
	{
		ra(a);
		(*cost_a)--;
	}
	while (*cost_a < 0)
	{
		rra(a);
		(*cost_a)++;
	}
}

static void	do_b_rotations(t_stack **b, int *cost_b)
{
	while (*cost_b > 0)
	{
		rb(b);
		(*cost_b)--;
	}
	while (*cost_b < 0)
	{
		rrb(b);
		(*cost_b)++;
	}
}

void	do_rotations(t_stack **a, t_stack **b, int cost_a, int cost_b)
{
	do_same_rotations(a, b, &cost_a, &cost_b);
	do_a_rotations(a, &cost_a);
	do_b_rotations(b, &cost_b);
}


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvigara- <mvigara-@student.42school.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 19:14:26 by mvigara-          #+#    #+#             */
/*   Updated: 2024/12/20 08:09:32 by mvigara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Main sorting function that chooses the appropriate algorithm
** based on the size of the stack
*/
void	sort_stack(t_stack **a, t_stack **b)
{
	int	size;

	if (!a || !*a || is_sorted(*a))
		return ;
	size = stack_size(*a);
	if (size == 2)
		sa(a);
	else if (size == 3)
		sort_three(a);
	else if (size < 150)
		sort_small(a, b, size);
	else
		turkish_sort(a, b);
}

/*
** Shifts the stack until the smallest number is at the top
** Uses the most efficient rotation direction based on position
*/
void	shift_stack(t_stack **stack)
{
	int	lowest_pos;
	int	size;

	if (!stack || !*stack)
		return ;
	size = stack_size(*stack);
	lowest_pos = get_min_pos(*stack);
	if (lowest_pos > size / 2)
	{
		while (lowest_pos < size)
		{
			rra(stack);
			lowest_pos++;
		}
	}
	else
	{
		while (lowest_pos > 0)
		{
			ra(stack);
			lowest_pos--;
		}
	}
}

/*
** Moves the cheapest number from stack a to stack b
*/
void	move_cheapest_to_b(t_stack **a, t_stack **b)
{
	t_stack	*cheapest;
	int		cost_a;
	int		cost_b;

	get_target_positions(*a, *b);
	get_cost(*a, *b);
	cheapest = get_cheapest(*a);
	cost_a = cheapest->cost_a;
	cost_b = cheapest->cost_b;
	do_rotations(a, b, cost_a, cost_b);
	pb(a, b);
}

/*
** Moves the cheapest number from stack b to stack a
*/
void	move_cheapest_to_a(t_stack **a, t_stack **b)
{
	t_stack	*cheapest;
	int		cost_a;
	int		cost_b;

	get_target_positions(*b, *a);
	get_cost(*b, *a);
	cheapest = get_cheapest(*b);
	cost_a = cheapest->cost_a;
	cost_b = cheapest->cost_b;
	do_rotations(a, b, cost_a, cost_b);
	pa(a, b);
}

/*
** Turkish sort algorithm implementation
*/
void	turkish_sort(t_stack **a, t_stack **b)
{
	// Inicialización: Push primeros dos números y ordenarlos
	pb(a, b);
	pb(a, b);
	if ((*b)->value < (*b)->next->value)
		sb(b);
	// Primera fase: Push al stack B manteniendo orden descendente
	while (stack_size(*a) > 3)
		move_cheapest_to_b(a, b);
	// Segunda fase: Ordenar los tres números restantes en A
	if (!is_sorted(*a))
		sort_three(a);
	// Tercera fase: Devolver números a A en orden
	while (*b)
		move_cheapest_to_a(a, b);
	// Fase final: Asegurar que el mínimo está arriba
	shift_stack(a);
}


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvigara- <mvigara-@student.42school.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 08:51:46 by mvigara-          #+#    #+#             */
/*   Updated: 2024/12/19 08:39:33 by mvigara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Finds the highest value in the stack
** Returns the highest value found
*/
static int	get_highest(t_stack *stack)
{
	int	highest;

	if (!stack)
		return (0);
	highest = stack->value;
	while (stack)
	{
		if (stack->value > highest)
			highest = stack->value;
		stack = stack->next;
	}
	return (highest);
}

/*
** Sorts a stack of three numbers using the minimum possible moves
** The algorithm checks the highest value's position and performs
** the necessary rotations and swaps to sort the stack
*/
void	sort_three(t_stack **stack)
{
	int	highest;

	if (!stack || !*stack || stack_size(*stack) < 2)
		return ;
	if (is_sorted(*stack))
		return ;
	highest = get_highest(*stack);
	if ((*stack)->value == highest)
	{
		ra(stack);
		if (!is_sorted(*stack))
			sa(stack);
	}
	else if ((*stack)->next->value == highest)
	{
		rra(stack);
		if (!is_sorted(*stack))
			sa(stack);
	}
	else if (!is_sorted(*stack))
		sa(stack);
}

static void	move_min_to_top(t_stack **a, int min_pos, int mid)
{
	while (min_pos > 0)
	{
		if (min_pos <= mid)
			ra(a);
		else
			rra(a);
		min_pos = get_min_pos(*a);
	}
}

void	sort_small(t_stack **a, t_stack **b, int size)
{
	int	mid;

	if (size == 2)
		sa(a);
	else if (size == 3)
		sort_three(a);
	else
	{
		while (size > 3)
		{
			mid = size / 2;
			move_min_to_top(a, get_min_pos(*a), mid);
			pb(a, b);
			size--;
		}
		sort_three(a);
		while (*b)
			pa(a, b);
	}
}


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvigara- <mvigara-@student.42school.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 08:58:45 by mvigara-          #+#    #+#             */
/*   Updated: 2024/12/19 09:43:22 by mvigara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Updates position values for all nodes in a stack
** This is crucial for cost calculations
*/
void	update_positions(t_stack *stack)
{
	int		i;
	t_stack	*current;

	i = 0;
	current = stack;
	while (current)
	{
		current->pos = i;
		i++;
		current = current->next;
	}
}

/*
** Gets total cost of moving elements to their target positions
** cost_a: moves needed in stack a
** cost_b: moves needed in stack b
*/
void	get_cost(t_stack *a, t_stack *b)
{
	int		size_a;
	int		size_b;
	t_stack	*current;

	size_a = stack_size(a);
	size_b = stack_size(b);
	current = a;
	while (current)
	{
		current->cost_a = current->pos;
		if (current->pos > size_a / 2)
			current->cost_a = -(size_a - current->pos);
		current->cost_b = current->target_pos;
		if (current->target_pos > size_b / 2)
			current->cost_b = -(size_b - current->target_pos);
		current = current->next;
	}
}

/*
** Gets target positions for each element in stack_a
** This helps determine where each element should go in stack_b
*/
void	get_target_positions(t_stack *a, t_stack *b)
{
	t_stack	*current;

	current = a;
	update_positions(a);
	update_positions(b);
	while (current)
	{
		current->target_pos = find_target_position(a, b, current->value);
		current = current->next;
	}
}

/*
** Finds the element with the cheapest cost to move
** Returns the node with the lowest absolute combined cost
*/
t_stack	*get_cheapest(t_stack *stack)
{
	t_stack	*cheapest;
	t_stack	*current;
	int		lowest_cost;
	int		cost;

	if (!stack)
		return (NULL);
	cheapest = stack;
	lowest_cost = ft_abs(stack->cost_a) + ft_abs(stack->cost_b);
	current = stack->next;
	while (current)
	{
		cost = ft_abs(current->cost_a) + ft_abs(current->cost_b);
		if (cost < lowest_cost)
		{
			lowest_cost = cost;
			cheapest = current;
		}
		current = current->next;
	}
	return (cheapest);
}

/*
** Finds the position of the minimum value in the stack
** Returns the position (0-based index) of the minimum value
*/
int	get_min_pos(t_stack *stack)
{
	int		min;
	int		pos;
	int		min_pos;
	t_stack	*current;

	if (!stack)
		return (0);
	min = INT_MAX;
	pos = 0;
	min_pos = 0;
	current = stack;
	while (current)
	{
		if (current->value < min)
		{
			min = current->value;
			min_pos = pos;
		}
		current = current->next;
		pos++;
	}
	return (min_pos);
}

/* ************************************************************************** */
/*                                                                            */
/*                            src//stack/                                           */
/*                                                                            */
/* ************************************************************************** */


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvigara- <mvigara-@student.42school.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 15:46:40 by mvigara-          #+#    #+#             */
/*   Updated: 2024/12/17 12:12:46 by mvigara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Checks for duplicate values in the stack
** Returns 1 if duplicates are found, 0 otherwise
*/
int	check_duplicates(t_stack *stack)
{
	t_stack	*current;
	t_stack	*check;

	current = stack;
	while (current)
	{
		check = current->next;
		while (check)
		{
			if (current->value == check->value)
				return (1);
			check = check->next;
		}
		current = current->next;
	}
	return (0);
}


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvigara- <mvigara-@student.42school.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 11:10:18 by mvigara-          #+#    #+#             */
/*   Updated: 2024/12/17 11:37:43 by mvigara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*stack_new(int value)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->value = value;
	new->index = 0;
	new->pos = -1;
	new->target_pos = -1;
	new->cost_a = -1;
	new->cost_b = -1;
	new->next = NULL;
	return (new);
}

t_stack	*stack_last(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next != NULL)
		stack = stack->next;
	return (stack);
}

void	stack_add_back(t_stack **stack, t_stack *new)
{
	t_stack	*last;

	if (!new)
		return ;
	if (!*stack)
	{
		*stack = new;
		return ;
	}
	last = stack_last(*stack);
	last->next = new;
}

int	stack_size(t_stack *stack)
{
	int	size;

	size = 0;
	while (stack)
	{
		size++;
		stack = stack->next;
	}
	return (size);
}

void	free_stack(t_stack **stack)
{
	t_stack	*tmp;

	if (!stack || !(*stack))
		return ;
	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
	*stack = NULL;
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

