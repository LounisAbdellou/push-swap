/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labdello <labdello@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 17:42:50 by labdello          #+#    #+#             */
/*   Updated: 2024/06/20 12:49:36 by labdello         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	stk_indexing(t_stack *stack)
{
	int	i;

	i = 0;
	while (stack != NULL)
	{
		if (stack->index == 0 && i > 0)
			break ;
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
	{
		if (stack->next->index == 0)
			break ;
		stack = stack->next;
	}
	return (stack);
}

void	stk_add(t_stack **stack, t_stack *new)
{
	t_stack	*last_node;

	if (*stack == NULL)
	{
		*stack = new;
		return ;
	}
	last_node = stk_last(*(stack));
	last_node->next = new;
	new->index = last_node->index + 1;
	new->prev = last_node;
	new->next = *stack;
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
