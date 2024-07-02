/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labdello <labdello@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 18:25:20 by labdello          #+#    #+#             */
/*   Updated: 2024/07/02 15:23:53 by labdello         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack **sender, t_stack **receiver, char *action)
{
	t_stack	*tmp;

	if (stk_size(*(sender)) < 1)
		return ;
	tmp = *sender;
	*sender = (*sender)->next;
	tmp->next = NULL;
	tmp->prev = NULL;
	stk_add(receiver, tmp);
	if (action != NULL)
		ft_putstr_fd(action, 1);
}
