/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labdello <labdello@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 15:09:29 by labdello          #+#    #+#             */
/*   Updated: 2024/07/24 15:09:30 by labdello         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	execute_rotate(int *rot, int dir, t_stack **stack, int is_a)
{
	while (*rot > 0)
	{
		if (dir && is_a)
			rotate_a(stack);
		if (dir && !is_a)
			rotate_b(stack);
		if (!dir && is_a)
			reverse_rotate_a(stack);
		if (!dir && !is_a)
			reverse_rotate_b(stack);
		*rot -= 1;
	}
}

static void	execute_rotate_r(int rot, int dir, t_stack **sa, t_stack **sb)
{
	while (rot > 0)
	{
		if (dir)
			rotate_r(sa, sb);
		else
			reverse_rotate_r(sa, sb);
		rot--;
	}
}

static void	transform_rotate(int *rot_a, int *rot_b)
{
	if (*rot_a > *rot_b)
	{
		*rot_a -= *rot_b;
		*rot_b = 0;
	}
	else if (*rot_a < *rot_b)
	{
		*rot_b -= *rot_a;
		*rot_a = 0;
	}
	else if (*rot_a == *rot_b)
	{
		*rot_a = 0;
		*rot_b = 0;
	}
}

void	execute_move(t_stack *to_mv, t_stack **stack_a, t_stack **stack_b)
{
	int		rot_a;
	int		rot_b;
	int		dir_a;
	int		dir_b;

	rot_b = number_of_rotate(to_mv->index, to_mv);
	rot_a = number_of_rotate(get_place_of(to_mv->value, *stack_a), *stack_a);
	dir_b = direction_of_rotate(to_mv->index, to_mv);
	dir_a = direction_of_rotate(get_place_of(to_mv->value, *stack_a), *stack_a);
	if (!dir_b)
		rot_b += 1;
	else
		rot_b -= 1;
	if (dir_a == dir_b && (rot_a && rot_b))
	{
		if (rot_a > rot_b)
			execute_rotate_r(rot_b, dir_a, stack_a, stack_b);
		if (rot_a <= rot_b)
			execute_rotate_r(rot_a, dir_a, stack_a, stack_b);
		transform_rotate(&rot_a, &rot_b);
	}
	execute_rotate(&rot_a, dir_a, stack_a, 1);
	execute_rotate(&rot_b, dir_b, stack_b, 0);
}
