/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labdello <labdello@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 15:10:06 by labdello          #+#    #+#             */
/*   Updated: 2024/07/24 15:10:09 by labdello         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_tablen(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	free_stack(t_stack **stack)
{
	t_stack	*head;
	t_stack	*current;
	t_stack	*tmp;

	head = ft_stk_gethead(*stack);
	if (!head)
		return ;
	current = head->next;
	while (current->index != 0)
	{
		tmp = current->next;
		free(current);
		current = tmp;
	}
	free(current);
	return ;
}

int	return_error(char *message)
{
	ft_putstr_fd(message, 2);
	return (1);
}
