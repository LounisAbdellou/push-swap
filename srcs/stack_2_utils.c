/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_2_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labdello <labdello@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 15:40:16 by labdello          #+#    #+#             */
/*   Updated: 2024/07/24 15:40:16 by labdello         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_stksize(t_stack *stack)
{
	t_stack	*head;
	t_stack	*current;
	int		i;

	head = ft_stk_gethead(stack);
	if (!head)
		return (0);
	current = head->next;
	i = 1;
	while (current->index != 0)
	{
		i++;
		current = current->next;
	}
	return (i);
}

int	is_stack_sorted(t_stack *stack, int len)
{
	t_stack	*head;
	t_stack	*current;

	if (ft_stksize(stack) != len)
		return (0);
	head = ft_stk_gethead(stack);
	current = head->next;
	while (current->index != 0)
	{
		if (current->value > current->prev->value)
			return (0);
		current = current->next;
	}
	return (1);
}

void	push_from_to(t_stack **stack_from, t_stack **stack_to)
{
	t_stack	*to_move;

	to_move = ft_stkdel_top(stack_from);
	if (!to_move)
		return ;
	ft_stkadd_top(stack_to, to_move);
	return ;
}

void	swap_top_of(t_stack **stack)
{
	t_stack	*arr[3];
	t_stack	*next;
	int		index;

	arr[0] = ft_stk_gethead(*stack);
	if (!arr[0] || ft_stksize(*stack) < 2)
		return ;
	arr[1] = (arr[0])->prev;
	arr[0] = (arr[1])->prev;
	arr[2] = (arr[0])->prev;
	(arr[2])->next = arr[1];
	(arr[2])->prev = arr[0];
	index = (arr[1])->index;
	next = (arr[1])->next;
	(arr[1])->next = arr[0];
	(arr[1])->prev = (arr[0])->prev;
	(arr[1])->index = (arr[0])->index;
	(arr[0])->next = next;
	(arr[0])->prev = arr[1];
	(arr[0])->index = index;
}

void	rotate_stack(t_stack **stack, int direction)
{
	t_stack	*head;
	t_stack	*current;

	head = ft_stk_gethead(*stack);
	if (!head || ft_stksize(*stack) < 2)
		return ;
	current = head->next;
	while (current->index != 0)
	{
		if (direction == 1)
			current->index += 1;
		else
			current->index -= 1;
		current = current->next;
	}
	current = current->prev;
	if (direction == 1)
	{
		head->index += direction;
		current->index = 0;
	}
	else
		head->index = current->index + 1;
	*stack = ft_stk_gethead(*stack);
	return ;
}
