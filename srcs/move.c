/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labdello <labdello@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 15:10:31 by labdello          #+#    #+#             */
/*   Updated: 2024/07/24 15:10:33 by labdello         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a(t_stack **stack_a, t_stack **stack_b)
{
	push_from_to(stack_b, stack_a);
	ft_printf("pa\n");
	return ;
}

void	push_b(t_stack **stack_a, t_stack **stack_b)
{
	push_from_to(stack_a, stack_b);
	ft_printf("pb\n");
	return ;
}

void	swap_a(t_stack **stack_a)
{
	swap_top_of(stack_a);
	ft_printf("sa\n");
}

void	swap_b(t_stack **stack_b)
{
	swap_top_of(stack_b);
	ft_printf("sb\n");
}

void	swap_s(t_stack **stack_a, t_stack **stack_b)
{
	swap_top_of(stack_a);
	swap_top_of(stack_b);
	ft_printf("ss\n");
}
