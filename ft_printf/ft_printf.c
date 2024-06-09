/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labdello <labdello@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 19:57:23 by labdello          #+#    #+#             */
/*   Updated: 2024/06/05 15:26:38 by labdello         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static void	ft_display(va_list args, size_t *count, char convertion)
{
	if (convertion == '%')
	{
		ft_putchar_fd('%', 1);
		*count += 1;
	}
	else if (convertion == 'c')
	{
		ft_putchar_fd(va_arg(args, int), 1);
		*count += 1;
	}
	else if (convertion == 'd' || convertion == 'i')
		*count += ft_handle_digit(va_arg(args, int));
	else if (convertion == 'u')
		*count += ft_handle_unsigned(va_arg(args, unsigned int));
	else if (convertion == 's')
		*count += ft_handle_str(va_arg(args, char *));
	else if (convertion == 'p')
		*count += ft_handle_ptr(va_arg(args, unsigned long long));
	else if (convertion == 'x' || convertion == 'X' || convertion == 'p')
		*count += ft_handle_hex(va_arg(args, unsigned int), convertion);
}

int	ft_printf(const char *format, ...)
{
	size_t	i;
	size_t	count;
	va_list	args;

	if (!format)
		return (-1);
	i = 0;
	count = 0;
	va_start(args, format);
	while (format[i] != '\0')
	{
		if (format[i] != '%')
		{
			ft_putchar_fd(format[i], 1);
			i++;
			count++;
			continue ;
		}
		ft_display(args, &count, format[++i]);
		i++;
	}
	va_end(args);
	return (count);
}
