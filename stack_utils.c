/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labdello <labdello@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 17:42:50 by labdello          #+#    #+#             */
/*   Updated: 2024/06/26 14:26:08 by labdello         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	stk_indexing(t_stack *stack)
{
	size_t	i;

	i = 0;
	while (stack != NULL)
	{
		stack->index = i;
		stack = stack->next;
		i++;
	}
}

t_stack	*stk_new(int value)
{
	t_stack	*node;

	node = (t_stack *)malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->index = 0;
	node->value = value;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

t_stack	*stk_last(t_stack *stack)
{
	while (stack->next != NULL)
		stack = stack->next;
	return (stack);
}

void	stk_add(t_stack **stack, t_stack *new)
{
	if (*stack == NULL)
	{
		*stack = new;
		return ;
	}
	(*stack)->prev = new;
	new->next = *stack;
	*stack = new;
}

void	stk_clear(t_stack **stack)
{
	t_stack	*temp;

	while (*stack != NULL)
	{
		temp = (*stack)->next;
		free(*stack);
		*stack = temp;
	}
}
