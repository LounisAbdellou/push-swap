/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labdello <labdello@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 15:09:09 by labdello          #+#    #+#             */
/*   Updated: 2024/07/24 15:09:13 by labdello         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	direction_of_rotate(int index, t_stack *stack)
{
	int	len;

	len = ft_stksize(stack);
	if (index <= len / 2)
		return (0);
	else
		return (1);
}

int	number_of_rotate(int index, t_stack *stack)
{
	int	len;

	len = ft_stksize(stack);
	if (index <= len / 2)
		return (index);
	else
		return (len - index);
}

int	get_place_of(int value, t_stack *stack)
{
	t_stack	*current;
	int		place_index;
	int		place_value;
	int		min;

	current = ft_stk_gethead(stack);
	place_index = -1;
	place_value = INT_MIN;
	min = 1;
	while (current->next->index != 0)
	{
		if (value > current->value)
			min = 0;
		if (value > current->value && current->value >= place_value)
		{
			place_value = current->value;
			place_index = current->index;
		}
		current = current->next;
	}
	if (value > current->value && current->value >= place_value)
		place_index = current->index;
	if (min && value < current->value)
		return (get_place_of(INT_MAX, stack));
	return (place_index);
}

int	eval_move(t_stack *current, t_stack *stack_a)
{
	int	rot_a;
	int	rot_b;
	int	dir_a;
	int	dir_b;

	rot_a = number_of_rotate(get_place_of(current->value, stack_a), stack_a);
	rot_b = number_of_rotate(current->index, current);
	dir_a = direction_of_rotate(get_place_of(current->value, stack_a), stack_a);
	dir_b = direction_of_rotate(current->index, current);
	if (!dir_b)
		rot_b += 1;
	else
		rot_b -= 1;
	if (dir_a == dir_b && rot_a >= rot_b)
		return (rot_a + 1);
	if (dir_a == dir_b && rot_a < rot_b)
		return (rot_b + 1);
	return (rot_a + rot_b + 1);
}

// t_stack	*find_best_move(t_stack *stack_a, t_stack *pushed, int grp)
// {
// 	t_stack	*current;
// 	t_stack	*cheaper;
// 	int		score;
// 	int		eval;
//
// 	current = pushed->next;
// 	if (current->index == pushed->index)
// 		return (current);
// 	score = eval_move(current, stack_a);
// 	cheaper = current;
// 	while (current->index != pushed->index)
// 	{
// 		if (current->grp == grp)
// 		{
// 			eval = eval_move(current, stack_a);
// 			if (eval < score)
// 			{
// 				score = eval;
// 				cheaper = current;
// 			}
// 		}
// 		current = current->next;
// 	}
// 	return (cheaper);
// }
//
