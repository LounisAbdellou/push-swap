/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labdello <labdello@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 15:38:42 by labdello          #+#    #+#             */
/*   Updated: 2024/07/24 15:38:43 by labdello         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate_a(t_stack **stack_a)
{
	rotate_stack(stack_a, -1);
	ft_printf("rra\n");
}

void	reverse_rotate_b(t_stack **stack_b)
{
	rotate_stack(stack_b, -1);
	ft_printf("rrb\n");
}

void	rotate_a(t_stack **stack_a)
{
	rotate_stack(stack_a, 1);
	ft_printf("ra\n");
}

void	rotate_b(t_stack **stack_b)
{
	rotate_stack(stack_b, 1);
	ft_printf("rb\n");
}
