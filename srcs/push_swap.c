/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labdello <labdello@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 15:39:45 by labdello          #+#    #+#             */
/*   Updated: 2024/07/24 15:39:46 by labdello         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	parse_to_stack(char **input, t_stack **stack)
{
	char	*joined_input;
	char	**tab_input;

	joined_input = join_input(input);
	if (!joined_input)
		return (0);
	tab_input = ft_split(joined_input, ' ');
	free(joined_input);
	if (!tab_input)
		return (0);
	if (!check_tab(tab_input))
	{
		free_tab(tab_input);
		return (0);
	}
	if (!fill_stack(tab_input, stack))
	{
		free_tab(tab_input);
		return (0);
	}
	free_tab(tab_input);
	if (!stack)
		return (0);
	return (1);
}

static void	push_swap(t_stack **stack_a)
{
	t_stack	*stack_b;
	int		stack_len;
	int		grp_len;
	int		grp;

	stack_b = NULL;
	stack_len = ft_stksize(*stack_a);
	grp = 3;
	if (stack_len > 300)
		grp = 6;
	grp_len = stack_len / grp;
	if (is_stack_sorted(*stack_a, stack_len))
		return ;
	if (stack_len < 6)
	{
		handle_small(stack_a, &stack_b);
		return ;
	}
	push_by_grp(stack_a, &stack_b, stack_len, grp_len);
	sort_three(stack_a);
	bring_back_sb(stack_a, &stack_b, grp);
	sort_stack(stack_a);
}

int	main(int ac, char **av)
{
	t_stack	*stack;

	if (ac < 2)
		return (0);
	if (!(parse_to_stack(av + 1, &stack)))
		return (return_error("Error\n"));
	init_push_swap(&stack);
	push_swap(&stack);
	free_stack(&stack);
	return (0);
}
