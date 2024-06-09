/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labdello <labdello@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 14:21:36 by labdello          #+#    #+#             */
/*   Updated: 2024/06/05 14:31:28 by labdello         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

void	ft_putptr(unsigned long long ptr, int fd)
{
	if (ptr >= 16)
	{
		ft_putptr(ptr / 16, fd);
		ft_putptr(ptr % 16, fd);
	}
	else
	{
		if (ptr <= 9)
			ft_putchar_fd(ptr + 48, fd);
		else
			ft_putchar_fd((ptr - 10) + 97, fd);
	}
}
