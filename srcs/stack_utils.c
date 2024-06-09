/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labdello <labdello@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 15:40:54 by labdello          #+#    #+#             */
/*   Updated: 2024/07/24 15:40:55 by labdello         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_stknew(int value)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->value = value;
	new->next = NULL;
	new->prev = NULL;
	new->index = -1;
	new->order = -1;
	new->grp = 0;
	return (new);
}

t_stack	*ft_stk_gethead(t_stack *stk)
{
	t_stack	*tmp;

	tmp = stk;
	if (!stk)
		return (NULL);
	while (tmp->index != 0)
		tmp = tmp->next;
	return (tmp);
}

void	ft_stkadd_top(t_stack **stk, t_stack *new)
{
	t_stack	*head;
	t_stack	*last;

	head = ft_stk_gethead(*stk);
	if (!head)
	{
		new->index = 0;
		new->prev = new;
		new->next = new;
		*stk = new;
		return ;
	}
	last = head->prev;
	last->next = new;
	new->prev = last;
	head->prev = new;
	new->next = head;
	new->index = last->index + 1;
	return ;
}

t_stack	*ft_stkdel_top(t_stack **stk)
{
	t_stack	*head;
	t_stack	*last;
	t_stack	*del;

	head = ft_stk_gethead(*stk);
	if (!head)
		return (NULL);
	if (head->next == head || head->prev == head)
	{
		head->index = -1;
		head->next = NULL;
		head->prev = NULL;
		stk = NULL;
		return (head);
	}
	del = head->prev;
	last = del->prev;
	last->next = head;
	head->prev = last;
	del->next = NULL;
	del->prev = NULL;
	del->index = -1;
	return (del);
}

int	get_index_of(int value, t_stack *stack)
{
	t_stack	*head;
	t_stack	*current;

	if (!stack)
		return (-1);
	head = ft_stk_gethead(stack);
	if (head->value == value)
		return (head->index);
	current = head->next;
	while (current->index != 0)
	{
		if (current->value == value)
			return (current->index);
		current = current->next;
	}
	return (-1);
}
