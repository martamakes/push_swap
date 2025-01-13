#include "push_swap.h"

int	is_sorted(t_stack *stack)
{
	t_stack	*current;

	if (!stack)
		return (1);
	current = stack;
	while (current->next)
	{
		if (current->index + 1 != current->next->index)
			return (0);
		current = current->next;
	}
	return (1);
}