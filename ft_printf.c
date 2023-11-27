/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belguabd <belguabd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 01:27:41 by belguabd          #+#    #+#             */
/*   Updated: 2023/11/23 11:17:55 by belguabd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putaddress(unsigned long ptr, int *count)
{
	if (ptr >= 16)
	{
		ft_putaddress(ptr / 16, count);
		ft_putaddress(ptr % 16, count);
	}
	else
	{
		if (ptr < 10)
			ft_putchar(ptr + '0', count);
		else
			ft_putchar(ptr + 'a' - 10, count);
	}
}

void	handle_format_specifier(const char *format, va_list list,
	int *count, int i)
{
	if (format[i] == 'c')
		ft_putchar(va_arg(list, int), count);
	else if (format[i] == 'd' || format[i] == 'i')
		ft_putnbr(va_arg(list, int), count);
	else if (format[i] == 's')
		*count += ft_putstr(va_arg(list, char *));
	else if (format[i] == 'X')
		print_hexadecimal(va_arg(list, unsigned int), count);
	else if (format[i] == 'x')
		print_hexadecimal_lowercase(va_arg(list, unsigned int), count);
	else if (format[i] == 'p')
	{
		*count += ft_putstr("0x");
		ft_putaddress(va_arg(list, unsigned long), count);
	}
	else if (format[i] == 'u')
		ft_putunsigned(va_arg(list, unsigned int), count);
	else
		ft_putchar(format[i], count);
}

int	ft_printf(const char *format, ...)
{
	va_list	list;
	int		i;
	int		count;

	if (write(1, "", 0) == -1)
		return (-1);
	va_start(list, format);
	i = 0;
	count = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			i++;
			handle_format_specifier(format, list, &count, i);
		}
		else if (format[i] != '%')
			ft_putchar(format[i], &count);
		i++;
	}
	va_end(list);
	return (count);
}
