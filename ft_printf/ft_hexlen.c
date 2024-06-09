/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labdello <labdello@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 19:16:06 by labdello          #+#    #+#             */
/*   Updated: 2024/06/04 19:44:13 by labdello         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_hexlen(unsigned int hex)
{
	size_t			count;

	count = 1;
	while (hex / 16 >= 1)
	{
		hex = hex / 16;
		count++;
	}
	return (count);
}
