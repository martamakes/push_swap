
#include "push_swap.h"

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
	else if (size < 10)
		sort_small(a, b, size);
	else
	{
		index_stack(*a);
		turkish_sort(a, b);
	}
}
