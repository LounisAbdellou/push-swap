/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labdello <labdello@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 15:24:55 by labdello          #+#    #+#             */
/*   Updated: 2024/06/20 14:59:04 by labdello         ###   ########.fr       */
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

char	*parse_args(char **args, t_stack *stack, int is_splited)
{
	size_t	i;
	t_stack	*new;
	char	*validation_msg;

	i = 0;
	validation_msg = args_validation(args);
	if (ft_strcmp(validation_msg, "OK") != 0)
		return (validation_msg);
	while (args[i] != NULL)
	{
		new = stk_new(ft_atoi(args[i]));
		if (!new)
		{
			stk_clear(&stack);
			return ("Arguments could not be parsed\n");
		}
		stk_add(&stack, new);
		i++;
	}
	if (is_splited)
		free(args);
	return ("OK");
}

int	main(int ac, char **av)
{
	char	*parse_msg;
	t_stack	*a_stack;

	a_stack = NULL;
	if (ac < 2)
	{
		ft_putstr_fd("Wrong number of arguments\n", 1);
		return (1);
	}
	if (ac == 2)
		parse_msg = parse_args(ft_split(av[1], ' '), a_stack, 1);
	else
		parse_msg = parse_args(av + 1, a_stack, 0);
	if (ft_strcmp(parse_msg, "OK") != 0)
	{
		ft_putstr_fd(parse_msg, 1);
		return (1);
	}
	return (0);
}
