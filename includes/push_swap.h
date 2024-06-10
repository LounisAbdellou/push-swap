/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labdello <labdello@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 19:18:26 by labdello          #+#    #+#             */
/*   Updated: 2024/06/14 12:57:50 by labdello         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <limits.h>

typedef struct s_stack
{
	int				index;
	int				value;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

t_stack	*stk_new(int value);
void	stk_clear(t_stack **stack);
void	stkadd_top(t_stack **stack, t_stack *new);

#endif
