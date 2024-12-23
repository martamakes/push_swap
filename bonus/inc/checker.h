/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvigara- <mvigara-@student.42school.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 08:26:16 by mvigara-          #+#    #+#             */
/*   Updated: 2024/12/21 21:23:04 by mvigara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../../inc/push_swap.h"
# include "../../lib/libft/inc/libft.h"

typedef struct s_log
{
	int		total_ops;
	int		valid_ops;
	int		invalid_ops;
	char	*last_op;
	int		debug_mode;
}			t_log;
// Main checker functions
int			execute_instruction(char *line, t_stack **a, t_stack **b,
				t_log *log);
void		free_and_exit(t_stack **a, t_stack **b, int status);

// Operations
void		checker_sa(t_stack **a, t_log *log);
void		checker_sb(t_stack **b, t_log *log);
void		checker_ss(t_stack **a, t_stack **b, t_log *log);
void		checker_pa(t_stack **a, t_stack **b, t_log *log);
void		checker_pb(t_stack **a, t_stack **b, t_log *log);
void		checker_ra(t_stack **a, t_log *log);
void		checker_rb(t_stack **b, t_log *log);
void		checker_rr(t_stack **a, t_stack **b, t_log *log);
void		checker_rra(t_stack **a, t_log *log);
void		checker_rrb(t_stack **b, t_log *log);
void		checker_rrr(t_stack **a, t_stack **b, t_log *log);

// Utils
int			check_number(char *str);
int			is_valid_number_str(char *str);
void		print_stack(t_stack *stack, char stack_name);

// Debug functions
void		init_log(t_log *log);
void		log_operation(t_log *log, const char *op);
void		print_debug_info(t_stack *a, t_stack *b, t_log *log);

#endif
