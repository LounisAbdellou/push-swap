/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labdello <labdello@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 22:16:35 by labdello          #+#    #+#             */
/*   Updated: 2024/06/05 14:27:53 by labdello         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <stdarg.h>

void	ft_putunbr_fd(unsigned int nbr, int fd);
void	ft_putptr(unsigned long long ptr, int fd);
void	ft_puthex_fd(unsigned int hex, int capitilize, int fd);
size_t	ft_unbrlen(unsigned int nbr);
size_t	ft_hexlen(unsigned int hex);
size_t	ft_ptrlen(unsigned long long ptr);
int		ft_printf(const char *format, ...);
int		ft_handle_str(char *str);
int		ft_handle_digit(int nbr);
int		ft_handle_unsigned(unsigned int nbr);
int		ft_handle_hex(unsigned int hex, char convertion);
int		ft_handle_ptr(unsigned long long ptr);

#endif
