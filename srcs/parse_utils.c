/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labdello <labdello@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 15:39:29 by labdello          #+#    #+#             */
/*   Updated: 2024/07/24 15:39:31 by labdello         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*join_input(char **input)
{
	char	*str;
	char	*tmp;
	int		i;

	i = 0;
	str = ft_calloc(1, sizeof(char));
	if (!str)
		return (NULL);
	while (input[i])
	{
		tmp = ft_strjoin(str, " ");
		free(str);
		str = ft_strjoin(tmp, input[i]);
		free(tmp);
		i++;
	}
	return (str);
}

int	check_tab(char **tab)
{
	int	i;
	int	j;

	i = 0;
	if (!tab[0])
		return (0);
	while (tab[i])
	{
		if (ft_strlen(tab[i]) > 11)
			return (0);
		j = 0;
		if (tab[i][j] == '+' || tab[i][j] == '-')
			j++;
		if (tab[i][j] == '\0')
			return (0);
		while (tab[i][j])
		{
			if (!ft_isdigit(tab[i][j]) || tab[i][j] == ' ')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static long	ft_atol(char *nptr)
{
	long	nb;
	int		signe;
	int		i;

	i = 0;
	signe = 1;
	nb = 0;
	while (nptr[i] != '\0'
		&& ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32))
		i++;
	if (nptr[i] != '\0' && (nptr[i] == '-' || nptr[i] == '+'))
	{
		if (nptr[i] == '-')
			signe *= -1;
		i++;
	}
	while (nptr[i] != '\0' && ft_isdigit(nptr[i]) == 1)
	{
		nb = nb * 10 + (nptr[i] - 48);
		i++;
	}
	return (nb * signe);
}

static int	convert_to_int(char *str, int *res, t_stack *stack)
{
	long	nb;

	nb = ft_atol(str);
	if (nb > INT_MAX || nb < INT_MIN)
		return (0);
	*res = (int)nb;
	if (get_index_of(*res, stack) != -1)
		return (0);
	return (1);
}

int	fill_stack(char **tab, t_stack **stack)
{
	int		i;
	int		to_stack;
	t_stack	*new;

	i = ft_tablen(tab) - 1;
	to_stack = 0;
	*stack = NULL;
	while (i >= 0)
	{
		if (!convert_to_int(tab[i], &to_stack, *stack))
		{
			free_stack(stack);
			return (0);
		}
		new = ft_stknew(to_stack);
		if (!new)
		{
			free_stack(stack);
			return (0);
		}
		ft_stkadd_top(stack, new);
		i--;
	}
	return (1);
}
