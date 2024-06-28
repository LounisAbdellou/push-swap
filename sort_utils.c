/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labdello <labdello@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 14:47:22 by labdello          #+#    #+#             */
/*   Updated: 2024/06/16 14:43:00 by labdello         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	tiny_sort(t_stack **stack)
{
	t_stack	*biggest_node;

	biggest_node = stk_biggest(*(stack));
	if (*stack == biggest_node)
		rotate(stack);
	else if ((*stack)->next == biggest_node)
		reverse_rotate(stack);
	if ((*stack)->value > (*stack)->next->value)
		swap(stack);
}

void	sort(t_stack **a_stack, t_stack **b_stack)
{
	t_stack	*smallest;
	size_t	a_size;

	a_size = stk_size(*(a_stack));
	while (a_size > 3)
	{
		push(a_stack, b_stack);
		a_size--;
	}
	tiny_sort(a_stack);
}

void	push_swap(t_stack **a_stack, t_stack **b_stack)
{
	if (!is_stk_sorted(*(a_stack)))
	{
		if (stk_size(*(a_stack)) == 2)
			swap(a_stack);
		else if (stk_size(*(a_stack)) == 3)
			tiny_sort(a_stack);
		else
			sort(a_stack, b_stack);
	}
}
