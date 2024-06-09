/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unbrlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labdello <labdello@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 16:44:02 by labdello          #+#    #+#             */
/*   Updated: 2024/05/31 16:51:20 by labdello         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_unbrlen(unsigned int nbr)
{
	size_t			count;

	count = 1;
	while (nbr / 10 >= 1)
	{
		nbr = nbr / 10;
		count++;
	}
	return (count);
}
