/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvigara- <mvigara-@student.42school.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 15:28:20 by mvigara-          #+#    #+#             */
/*   Updated: 2024/12/01 15:28:33 by mvigara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// inc/push_swap.h

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

// Stack structure
typedef struct s_stack
{
    int             *numbers;
    int             size;
}               t_stack;

// Function prototypes
void    error_exit(void);
t_stack *parse_args(int argc, char **argv);

#endif