#include "push_swap.h"

void    error_exit(t_stack **stack_a, t_stack **stack_b)
{
    if (stack_a != NULL)
        free_stack(stack_a);
    if (stack_b != NULL)
        free_stack(stack_b);
    ft_putstr_fd("Error\n", 2);
    exit(1);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvigara- <mvigara-@student.42school.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 15:44:33 by mvigara-          #+#    #+#             */
/*   Updated: 2024/12/17 21:46:28 by mvigara-         ###   ########.fr       */
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

static void    push_swap(t_stack **stack_a, t_stack **stack_b, int total_nodes)
{
    if (is_sorted(*stack_a))
        return ;
    if (total_nodes == 2)
        sa(stack_a);
    else if (total_nodes == 3)
        sort_three(stack_a);
    else if (total_nodes > 3)
        sort_stack(stack_a, stack_b);
}

static void	get_numbers(char *av, t_stack **stack_a)
{
	char		**numbers;
	long		num;
	int			i;

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
	int		total_nodes;
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
	total_nodes = stack_size(stack_a);
	if (!is_sorted(stack_a))
		push_swap(&stack_a, &stack_b, total_nodes);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_ops.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvigara- <mvigara-@student.42school.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 08:20:20 by mvigara-          #+#    #+#             */
/*   Updated: 2024/12/17 11:57:25 by mvigara-         ###   ########.fr       */
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
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_ops.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvigara- <mvigara-@student.42school.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 08:36:43 by mvigara-          #+#    #+#             */
/*   Updated: 2024/12/17 11:58:05 by mvigara-         ###   ########.fr       */
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
}

/*
** rrb (reverse rotate b): Shifts down all elements of
** stack b by 1. The last element becomes the first one.
*/
void	rrb(t_stack **stack_b)
{
	reverse_rotate(stack_b);
	ft_putstr_fd("rrb\n", 1);
}

/*
** rrr: rra and rrb at the same time.
*/
void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	ft_putstr_fd("rrr\n", 1);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_ops.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvigara- <mvigara-@student.42school.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 08:33:49 by mvigara-          #+#    #+#             */
/*   Updated: 2024/12/17 11:57:43 by mvigara-         ###   ########.fr       */
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
}

/*
** rb (rotate b): Shifts up all elements of stack b by 1.
** The first element becomes the last one.
*/
void	rb(t_stack **stack_b)
{
	rotate(stack_b);
	ft_putstr_fd("rb\n", 1);
}

/*
** rr: ra and rb at the same time.
*/
void	rr(t_stack **stack_a, t_stack **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	ft_putstr_fd("rr\n", 1);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_ops.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvigara- <mvigara-@student.42school.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 08:33:49 by mvigara-          #+#    #+#             */
/*   Updated: 2024/12/17 11:57:43 by mvigara-         ###   ########.fr       */
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
}

/*
** rb (rotate b): Shifts up all elements of stack b by 1.
** The first element becomes the last one.
*/
void	rb(t_stack **stack_b)
{
	rotate(stack_b);
	ft_putstr_fd("rb\n", 1);
}

/*
** rr: ra and rb at the same time.
*/
void	rr(t_stack **stack_a, t_stack **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	ft_putstr_fd("rr\n", 1);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvigara- <mvigara-@student.42school.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 15:45:18 by mvigara-          #+#    #+#             */
/*   Updated: 2024/12/17 12:04:36 by mvigara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// src/parser/parse_utils.c

#include "push_swap.h"

void    ft_split_free(char **split)
{
    int i;

    if (!split)
        return;
    i = 0;
    while (split[i])
    {
        free(split[i]);
        i++;
    }
    free(split);
}

/*
** Checks if a string contains only valid number characters
** Returns 1 if valid, 0 if invalid
*/
int    is_valid_input(char *str)
{
    int i;

    i = 0;
    if (!str || !*str)
        return (0);
    // Skip leading spaces
    while (ft_iswhitespace(str[i]))
        i++;
    // Handle sign if present
    if (str[i] == '-' || str[i] == '+')
        i++;
    // Must have at least one digit after sign
    if (!str[i])
        return (0);
    // Check all remaining characters are digits
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
static int process_arg_string(char *str, t_stack **stack_a)
{
    char    **numbers;
    char    *trimmed;
    int     i;
    long    num;

    trimmed = ft_strtrim(str, " \t\n\v\f\r");
    if (!trimmed)
        return (0);
    numbers = ft_split(trimmed, ' ');
    free(trimmed);
    if (!numbers)
        return (0);
    i = 0;
    while (numbers[i])
    {
        if (!is_valid_input(numbers[i]))
        {
            ft_split_free(numbers);
            return (0);
        }
        num = ft_atoll(numbers[i]);
        if (num > INT_MAX || num < INT_MIN)
        {
            ft_split_free(numbers);
            return (0);
        }
        stack_add_back(stack_a, stack_new((int)num));
        i++;
    }
    ft_split_free(numbers);
    return (1);
}

/*
** Process all input arguments
** Returns 1 if successful, 0 if error
*/
int    process_input(int ac, char **av, t_stack **stack_a)
{
    int i;

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
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvigara- <mvigara-@student.42school.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 15:45:18 by mvigara-          #+#    #+#             */
/*   Updated: 2024/12/17 12:04:36 by mvigara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// src/parser/parse_utils.c

#include "push_swap.h"

void    ft_split_free(char **split)
{
    int i;

    if (!split)
        return;
    i = 0;
    while (split[i])
    {
        free(split[i]);
        i++;
    }
    free(split);
}

/*
** Checks if a string contains only valid number characters
** Returns 1 if valid, 0 if invalid
*/
int    is_valid_input(char *str)
{
    int i;

    i = 0;
    if (!str || !*str)
        return (0);
    // Skip leading spaces
    while (ft_iswhitespace(str[i]))
        i++;
    // Handle sign if present
    if (str[i] == '-' || str[i] == '+')
        i++;
    // Must have at least one digit after sign
    if (!str[i])
        return (0);
    // Check all remaining characters are digits
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
static int process_arg_string(char *str, t_stack **stack_a)
{
    char    **numbers;
    char    *trimmed;
    int     i;
    long    num;

    trimmed = ft_strtrim(str, " \t\n\v\f\r");
    if (!trimmed)
        return (0);
    numbers = ft_split(trimmed, ' ');
    free(trimmed);
    if (!numbers)
        return (0);
    i = 0;
    while (numbers[i])
    {
        if (!is_valid_input(numbers[i]))
        {
            ft_split_free(numbers);
            return (0);
        }
        num = ft_atoll(numbers[i]);
        if (num > INT_MAX || num < INT_MIN)
        {
            ft_split_free(numbers);
            return (0);
        }
        stack_add_back(stack_a, stack_new((int)num));
        i++;
    }
    ft_split_free(numbers);
    return (1);
}

/*
** Process all input arguments
** Returns 1 if successful, 0 if error
*/
int    process_input(int ac, char **av, t_stack **stack_a)
{
    int i;

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
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvigara- <mvigara-@student.42school.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 08:51:46 by mvigara-          #+#    #+#             */
/*   Updated: 2024/12/17 21:35:21 by mvigara-         ###   ########.fr       */
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
void    sort_three(t_stack **stack)
{
    int    highest;

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
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvigara- <mvigara-@student.42school.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 08:51:46 by mvigara-          #+#    #+#             */
/*   Updated: 2024/12/17 21:35:21 by mvigara-         ###   ########.fr       */
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
void    sort_three(t_stack **stack)
{
    int    highest;

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
