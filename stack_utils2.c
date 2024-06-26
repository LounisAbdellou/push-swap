/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labdello <labdello@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 14:53:17 by labdello          #+#    #+#             */
/*   Updated: 2024/06/26 17:30:25 by labdello         ###   ########.fr       */
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

void	stk_display(t_stack *stack)
{
	while (stack != NULL)
	{
		ft_putnbr_fd(stack->index, 1);
		ft_putstr_fd(" => ", 1);
		ft_putnbr_fd(stack->value, 1);
		ft_putstr_fd("\n", 1);
		stack = stack->next;
	}
}
