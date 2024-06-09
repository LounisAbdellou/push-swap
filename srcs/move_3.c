/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labdello <labdello@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 15:39:04 by labdello          #+#    #+#             */
/*   Updated: 2024/07/24 15:39:06 by labdello         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate_r(t_stack **stack_a, t_stack **stack_b)
{
	rotate_stack(stack_a, -1);
	rotate_stack(stack_b, -1);
	ft_printf("rrr\n");
}

void	rotate_r(t_stack **stack_a, t_stack **stack_b)
{
	rotate_stack(stack_a, 1);
	rotate_stack(stack_b, 1);
	ft_printf("rr\n");
}
