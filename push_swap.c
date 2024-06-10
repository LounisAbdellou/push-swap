/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labdello <labdello@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 15:24:55 by labdello          #+#    #+#             */
/*   Updated: 2024/06/14 13:31:47 by labdello         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

char	*args_validation(char **args)
{
	int		n;
	size_t	i;

	i = 0;
	if (!args[0])
		return ("No arguments given\n");
	while (args[i] != NULL)
	{
		if (!ft_isnbr(args[i]))
			return ("Arguments must only be integers\n");
		n = ft_atoi(args[i]);
		if (n > INT_MAX || n < INT_MIN)
			return ("An int overflow was detected\n");
		i++;
	}
	return ("OK");
}

char	*parse_args(int args_count, char **args, t_stack *stack)
{
	size_t	i;
	t_stack	*new;
	char	**tab;
	char	*validation_msg;

	i = 0;
	tab = args;
	if (args_count == 1)
		tab = ft_split(args[0], ' ');
	validation_msg = args_validation(tab);
	if (ft_strcmp(validation_msg, "OK") != 0)
		return (validation_msg);
	while (tab[i] != NULL)
	{
		new = stk_new(ft_atoi(tab[i]));
		if (!new)
		{
			stk_clear(&stack);
			return ("Arguments could not be parsed\n");
		}
		stkadd_top(&stack, new);
		ft_putnbr_fd(ft_atoi(tab[i]), 1);
		ft_putchar_fd('\n', 1);
		i++;
	}
	free(tab);
	return ("OK");
}

int	main(int ac, char **av)
{
	char	*parse_msg;
	t_stack	*a_stack;
	/*t_stack	*b_stack;*/

	a_stack = NULL;
	/*b_stack = NULL;*/
	if (ac < 2)
	{
		ft_putstr_fd("Wrong number of arguments\n", 1);
		return (1);
	}
	parse_msg = parse_args(ac - 1, av + 1, a_stack);
	if (ft_strcmp(parse_msg, "OK") != 0)
	{
		ft_putstr_fd(parse_msg, 1);
		return (1);
	}
	return (0);
}
