/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labdello <labdello@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 15:40:01 by labdello          #+#    #+#             */
/*   Updated: 2024/07/24 15:40:02 by labdello         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stack(t_stack **stack)
{
	int	index;
	int	rotate;
	int	direction;

	index = get_place_of(INT_MAX, *stack);
	rotate = number_of_rotate(index, *stack);
	direction = direction_of_rotate(index, *stack);
	if (rotate == 0)
		return ;
	while (rotate > 0)
	{
		if (direction)
			rotate_a(stack);
		else
			reverse_rotate_a(stack);
		rotate--;
	}
	return ;
}

void	sort_three(t_stack **stack_a)
{
	t_stack	*current;
	int		len;

	current = ft_stk_gethead(*stack_a);
	len = ft_stksize(*stack_a);
	if (is_stack_sorted(*stack_a, len))
		return ;
	while (current->index != get_place_of(INT_MAX, *stack_a))
		current = current->next;
	if (current->index == 0)
	{
		swap_a(stack_a);
		return ;
	}
	if (current->index + 1 != len)
		reverse_rotate_a(stack_a);
	else
		rotate_a(stack_a);
	if (current->next->value < current->prev->value)
		swap_a(stack_a);
	return ;
}

void	sort_four(t_stack **stack_a, t_stack **stack_b)
{
	int	position;
	int	rotate;
	int	direction;

	push_b(stack_a, stack_b);
	sort_three(stack_a);
	position = get_place_of((*stack_b)->value, *stack_a);
	rotate = number_of_rotate(position, *stack_a);
	direction = direction_of_rotate(position, *stack_a);
	if (rotate == 0)
	{
		push_a(stack_a, stack_b);
		sort_stack(stack_a);
		return ;
	}
	while (rotate > 0)
	{
		if (direction)
			rotate_a(stack_a);
		else
			reverse_rotate_a(stack_a);
		rotate--;
	}
	push_a(stack_a, stack_b);
	sort_stack(stack_a);
}

void	bring_back_small(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*current;
	int		len;
	int		position;
	int		rotate;
	int		direction;

	current = ft_stk_gethead(*stack_b);
	current = current->prev;
	len = ft_stksize(*stack_b);
	while (len-- > 0)
	{
		position = get_place_of(current->value, *stack_a);
		rotate = number_of_rotate(position, *stack_a);
		direction = direction_of_rotate(position, *stack_a);
		current = current->prev;
		while (rotate-- > 0)
		{
			if (direction)
				rotate_a(stack_a);
			else
				reverse_rotate_a(stack_a);
		}
		push_a(stack_a, stack_b);
	}
}

void	handle_small(t_stack **stack_a, t_stack **stack_b)
{
	int	stack_len;

	stack_len = ft_stksize(*stack_a);
	if (stack_len == 2)
		swap_a(stack_a);
	if (stack_len == 3)
		sort_three(stack_a);
	if (stack_len == 4)
		sort_four(stack_a, stack_b);
	if (stack_len == 5)
	{
		push_b(stack_a, stack_b);
		push_b(stack_a, stack_b);
		sort_three(stack_a);
		bring_back_small(stack_a, stack_b);
		sort_stack(stack_a);
	}
	return ;
}
