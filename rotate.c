/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labdello <labdello@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 14:27:08 by labdello          #+#    #+#             */
/*   Updated: 2024/06/25 19:14:07 by labdello         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack **stack)
{
	stk_indexing(*(stack));
}

void	rotate_r(t_stack **a_stack, t_stack **b_stack)
{
	rotate(a_stack);
	rotate(b_stack);
}

void	reverse_rotate(t_stack **stack)
{
	stk_indexing(*(stack));
}

void	reverse_rotate_r(t_stack **a_stack, t_stack **b_stack)
{
	reverse_rotate(a_stack);
	reverse_rotate(b_stack);
}
