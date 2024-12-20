/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_push_ops.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvigara- <mvigara-@student.42school.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 08:43:01 by mvigara-          #+#    #+#             */
/*   Updated: 2024/12/20 08:44:14 by mvigara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../bonus/inc/checker.h"

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
