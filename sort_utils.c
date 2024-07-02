/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labdello <labdello@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 14:47:22 by labdello          #+#    #+#             */
/*   Updated: 2024/07/02 23:30:18 by labdello         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	rotate_both(t_stack **a, t_stack **b, t_stack *cheapest)
{
	while (*a != cheapest->target && *b != cheapest)
		rotate_r(a, b);
	update_indexes(*a);
	update_indexes(*b);
}

void	reverse_rotate_both(t_stack **a, t_stack **b, t_stack *cheapest)
{
	while (*a != cheapest->target && *b != cheapest)
		reverse_rotate_r(a, b);
	update_indexes(*a);
	update_indexes(*b);
}

void	tiny_sort(t_stack **a_stack)
{
	t_stack	*biggest_node;

	biggest_node = stk_biggest(*a_stack);
	if (*a_stack == biggest_node)
		rotate(a_stack, "ra\n");
	else if ((*a_stack)->next == biggest_node)
		reverse_rotate(a_stack, "rra\n");
	if ((*a_stack)->value > (*a_stack)->next->value)
		swap(a_stack, "sa\n");
}

void	finish_moves(t_stack **stack, t_stack *top_node, char stack_name)
{
	while (*stack != top_node)
	{
		if (stack_name == 'a')
		{
			if (is_above_median(top_node))
				rotate(stack, "ra\n");
			else
				reverse_rotate(stack, "rra\n");
		}
		else if (stack_name == 'b')
		{
			if (is_above_median(top_node))
				rotate(stack, "rb\n");
			else
				reverse_rotate(stack, "rrb\n");
		}
	}
}

void	make_moves(t_stack **a_stack, t_stack **b_stack)
{
	t_stack	*cheapest;

	cheapest = get_cheapest_node(*b_stack);
	if (is_above_median(cheapest) && is_above_median(cheapest->target))
		rotate_both(a_stack, b_stack, cheapest);
	else if (!is_above_median(cheapest) && !is_above_median(cheapest->target))
		reverse_rotate_both(a_stack, b_stack, cheapest);
	finish_moves(b_stack, cheapest, 'b');
	finish_moves(a_stack, cheapest->target, 'a');
	push(b_stack, a_stack, "pa\n");
}

void	turk_sort(t_stack **a_stack, t_stack **b_stack)
{
	t_stack	*smallest;
	size_t	a_size;

	a_size = stk_size(*a_stack);
	while (a_size > 3)
	{
		push(a_stack, b_stack, "pb\n");
		a_size--;
	}
	tiny_sort(a_stack);
	while (*b_stack != NULL)
	{
		update_nodes(*a_stack, *b_stack);
		make_moves(a_stack, b_stack);
	}
	update_indexes(*a_stack);
	smallest = stk_smallest(*a_stack);
	if (is_above_median(smallest))
		while (*a_stack != smallest)
			rotate(a_stack, "ra\n");
	else
		while (*a_stack != smallest)
			reverse_rotate(a_stack, "rra\n");
}

void	push_swap(t_stack **a_stack, t_stack **b_stack)
{
	if (!is_stk_sorted(*(a_stack)))
	{
		if (stk_size(*(a_stack)) == 2)
			swap(a_stack, "sa\n");
		else if (stk_size(*(a_stack)) == 3)
			tiny_sort(a_stack);
		else
			turk_sort(a_stack, b_stack);
	}
}
