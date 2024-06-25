/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labdello <labdello@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 18:25:20 by labdello          #+#    #+#             */
/*   Updated: 2024/06/26 14:44:01 by labdello         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack **sender, t_stack **receiver)
{
	t_stack	*tmp;

	tmp = (*sender)->next;
	(*sender)->next = NULL;
	(*sender)->prev = NULL;
	stk_add(receiver, *sender);
	if (tmp != NULL)
	{
		tmp->prev = NULL;
		*sender = tmp;
	}
	stk_indexing(*(sender));
	stk_indexing(*(receiver));
}
