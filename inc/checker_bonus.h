#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include "push_swap.h"

/* Process Instructions */
int		process_instruction(t_stack **a, t_stack **b, const char *inst);
int     read_and_execute_instructions(t_stack **stack_a, t_stack **stack_b);


#endif