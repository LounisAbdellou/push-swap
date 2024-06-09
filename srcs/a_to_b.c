/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_to_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labdello <labdello@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 15:07:52 by labdello          #+#    #+#             */
/*   Updated: 2024/07/24 15:08:03 by labdello         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	transform_grp(int *grp, int *cgrp, int glen)
{
	*grp += 1;
	if (*grp == glen)
	{
		*grp = 0;
		*cgrp += 2;
	}
}

static int	push_next_grp(t_stack **sa, t_stack **sb, int cgrp1, int cgrp2)
{
	t_stack	*current;

	current = ft_stk_gethead(*sa);
	current = current->prev;
	while (current->grp != cgrp1 && current->grp != cgrp2)
	{
		current = current->prev;
		rotate_a(sa);
	}
	if (current->grp % 2)
	{
		push_b(sa, sb);
		return (0);
	}
	push_b(sa, sb);
	rotate_b(sb);
	return (1);
}

void	push_by_grp(t_stack **sa, t_stack **sb, int len, int glen)
{
	int	cgrp1;
	int	cgrp2;
	int	grp1;
	int	grp2;

	cgrp1 = 1;
	cgrp2 = 2;
	grp1 = 0;
	grp2 = 0;
	while (len-- > 3)
	{
		if (!push_next_grp(sa, sb, cgrp1, cgrp2))
			transform_grp(&grp1, &cgrp1, glen);
		else
			transform_grp(&grp2, &cgrp2, glen);
	}
}
