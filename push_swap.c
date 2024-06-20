/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labdello <labdello@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 15:24:55 by labdello          #+#    #+#             */
/*   Updated: 2024/06/20 16:22:36 by labdello         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

int	args_validation(char **args)
{
	int		n;
	size_t	i;

	i = 0;
	if (!args[0])
		return (0);
	while (args[i] != NULL)
	{
		if (!ft_isnbr(args[i]))
			return (0);
		n = ft_atoi(args[i]);
		if (n > INT_MAX || n < INT_MIN)
			return (0);
		i++;
	}
	return (1);
}

int	parse_args(char **args, t_stack *stack, int is_splited)
{
	size_t	i;
	t_stack	*new;

	i = 0;
	while (args[i] != NULL)
	{
		new = stk_new(ft_atoi(args[i]));
		if (!new)
		{
			stk_clear(&stack);
			return (0);
		}
		stk_add(&stack, new);
		i++;
	}
	if (is_splited)
		free(args);
	return (1);
}

int	main(int ac, char **av)
{
	char	**args;
	t_stack	*a_stack;

	a_stack = NULL;
	if (ac < 2)
	{
		ft_putstr_fd("Error\n", 1);
		return (1);
	}
	args = av + 1;
	if (ac == 2)
		args = ft_split(av[1], ' ');
	if (!args_validation(args) || !parse_args(args, a_stack, 0))
	{
		ft_putstr_fd("Error\n", 1);
		return (1);
	}
	return (0);
}
