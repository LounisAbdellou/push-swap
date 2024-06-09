/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_3_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labdello <labdello@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 15:40:38 by labdello          #+#    #+#             */
/*   Updated: 2024/07/24 15:40:39 by labdello         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*get_this_node(int index, t_stack *stack)
{
	t_stack	*current;

	current = ft_stk_gethead(stack);
	while (current->index != index)
		current = current->next;
	return (current);
}

t_stack	*get_limit_node(t_stack *stack, int limit)
{
	t_stack	*current;
	t_stack	*limit_node;
	int		stack_len;

	current = ft_stk_gethead(stack);
	limit_node = current;
	stack_len = ft_stksize(stack);
	while (stack_len-- > 0)
	{
		if (limit_node->value > current->value && !limit)
			limit_node = current;
		if (limit_node->value < current->value && limit)
			limit_node = current;
		current = current->next;
	}
	return (limit_node);
}

static t_stack	*get_next_node(t_stack *node)
{
	t_stack	*current;
	t_stack	*next;
	int		is_max;

	current = node;
	next = get_limit_node(node, 1);
	is_max = 1;
	while (current->next->index != node->index)
	{
		if (node->value < current->value)
			is_max = 0;
		if (node->value < current->value && next->value > current->value)
			next = current;
		current = current->next;
	}
	if (node->value < current->value && next->value > current->value)
		next = current;
	if (is_max)
		return (get_limit_node(node, 1));
	return (next);
}

static void	attribute_grp(t_stack **stack_a, int len)
{
	t_stack	*current;
	int		nb_grp;
	int		grp;
	int		i;

	current = get_limit_node(*stack_a, 0);
	i = len;
	nb_grp = 3;
	grp = 1;
	if (len > 300)
		nb_grp = 6;
	while (i-- > 0)
	{
		if (current->order > grp * (len / nb_grp) && grp < nb_grp)
			grp++;
		current->grp = grp;
		current = get_next_node(current);
	}
}

void	init_push_swap(t_stack **stack_a)
{
	t_stack	*current;
	int		stack_len;
	int		i;
	int		order;

	current = get_limit_node(*stack_a, 0);
	stack_len = ft_stksize(*stack_a);
	i = stack_len;
	order = 0;
	while (i-- > 0)
	{
		current->order = order;
		order++;
		current = get_next_node(current);
	}
	attribute_grp(stack_a, stack_len);
	return ;
}
