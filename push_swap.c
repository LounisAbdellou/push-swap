/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labdello <labdello@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 15:24:55 by labdello          #+#    #+#             */
/*   Updated: 2024/06/26 17:45:23 by labdello         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	*free_tab(char **tab)
{
	size_t	i;

	i = 0;
	while (tab[i] != NULL)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (NULL);
}

static int	args_validation(char **args)
{
	long long	n;
	size_t		i;
	size_t		j;

	i = 0;
	if (!args[0])
		return (0);
	while (args[i] != NULL)
	{
		if (!ft_isnbr(args[i]))
			return (0);
		n = ft_atoll(args[i]);
		if (n > INT_MAX || n < INT_MIN)
			return (0);
		j = i + 1;
		while (args[j] != NULL)
		{
			if (n == ft_atoi(args[j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static void	ft_reverse_stab(char **tab)
{
	size_t	i;
	size_t	j;
	char	*tmp;

	i = 0;
	j = 0;
	while (tab[j] != NULL)
		j++;
	j -= 1;
	while (tab[i] != NULL && i < j)
	{
		tmp = tab[i];
		tab[i++] = tab[j];
		tab[j--] = tmp;
	}
}

static int	parse_args(char **args, t_stack **stack, int is_splited)
{
	size_t	i;
	t_stack	*new;

	i = 0;
	ft_reverse_stab(args);
	while (args[i] != NULL)
	{
		new = stk_new(ft_atoi(args[i]));
		if (!new)
		{
			stk_clear(stack);
			return (0);
		}
		stk_add(stack, new);
		i++;
	}
	stk_indexing(*(stack));
	if (is_splited)
		free_tab(args);
	return (1);
}

int	main(int ac, char **av)
{
	char	**args;
	t_stack	*a_stack;
	t_stack	*b_stack;

	a_stack = NULL;
	b_stack = NULL;
	if (ac < 2)
	{
		ft_putstr_fd("Error\n", 1);
		return (1);
	}
	args = av + 1;
	if (ac == 2)
		args = ft_split(av[1], ' ');
	if (!args_validation(args) || !parse_args(args, &a_stack, ac == 2))
	{
		ft_putstr_fd("Error\n", 1);
		return (1);
	}
	stk_clear(&a_stack);
	return (0);
}
