/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labdello <labdello@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 14:53:17 by labdello          #+#    #+#             */
/*   Updated: 2024/06/26 15:03:56 by labdello         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stk_size(t_stack *stack)
{
	size_t	count;

	count = 0;
	while (stack != NULL)
	{
		stack = stack->next;
		count++;
	}
	return (count);
}
