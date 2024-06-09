/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptrlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labdello <labdello@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 14:20:07 by labdello          #+#    #+#             */
/*   Updated: 2024/06/05 14:31:17 by labdello         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

size_t	ft_ptrlen(unsigned long long ptr)
{
	size_t			count;

	count = 1;
	while (ptr / 16 >= 1)
	{
		ptr = ptr / 16;
		count++;
	}
	return (count);
}
