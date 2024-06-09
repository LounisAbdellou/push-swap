/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_to_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labdello <labdello@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 15:08:42 by labdello          #+#    #+#             */
/*   Updated: 2024/07/24 15:08:45 by labdello         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*get_node_grp(t_stack *node, int grp, int len)
{
	t_stack	*current;
	int		i;

	current = node;
	i = len;
	while (i-- > 0)
	{
		if (current->grp == grp)
			return (current);
		current = current->next;
	}
	if (grp > 1)
		return (get_node_grp(node, grp - 1, len));
	return (node);
}

static int	get_grp_len(t_stack *stack, int grp)
{
	t_stack	*current;
	int		res;
	int		len;

	current = stack;
	res = 0;
	len = ft_stksize(stack);
	while (len-- > 0)
	{
		if (current->grp == grp)
			res++;
		current = current->next;
	}
	return (res);
}

static t_stack	*get_cheaper_node(t_stack *current, t_stack *stack_a, int grp)
{
	t_stack	*cheaper;
	int		score;
	int		eval;
	int		len;

	len = ft_stksize(current);
	cheaper = get_node_grp(current, grp, len);
	score = eval_move(cheaper, stack_a);
	while (len-- > 0)
	{
		if (current->grp == grp)
		{
			eval = eval_move(current, stack_a);
			if (eval < score)
			{
				score = eval;
				cheaper = current;
			}
		}
		current = current->next;
	}
	return (cheaper);
}

void	bring_back_sb(t_stack **stack_a, t_stack **stack_b, int grp)
{
	t_stack	*current;
	int		len;
	int		grp_len;

	current = ft_stk_gethead(*stack_b);
	current = get_cheaper_node(*stack_b, *stack_a, grp);
	len = ft_stksize(*stack_b);
	grp_len = get_grp_len(*stack_b, grp);
	while (len-- > 0)
	{
		execute_move(current, stack_a, stack_b);
		push_a(stack_a, stack_b);
		grp_len--;
		if (grp_len == 0)
		{
			grp--;
			grp_len = get_grp_len(*stack_b, grp);
		}
		current = get_cheaper_node(*stack_b, *stack_a, grp);
	}
}
