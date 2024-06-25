/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labdello <labdello@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 14:27:01 by labdello          #+#    #+#             */
/*   Updated: 2024/06/25 19:19:59 by labdello         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack **stack)
{
	stk_indexing(*(stack));
}

void	swap_s(t_stack **a_stack, t_stack **b_stack)
{
	swap(a_stack);
	swap(b_stack);
}
