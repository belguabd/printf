/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belguabd <belguabd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 16:46:29 by belguabd          #+#    #+#             */
/*   Updated: 2023/11/23 09:50:34 by belguabd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(int n, int *count)
{
	if (n == -2147483648)
	{
		ft_putchar ('-', count);
		ft_putchar ('2', count);
		ft_putnbr (147483648, count);
	}
	else if (n < 0)
	{
		n *= -1;
		ft_putchar ('-', count);
		ft_putnbr (n, count);
	}
	else if (n > 9)
	{
		ft_putnbr (n / 10, count);
		ft_putnbr (n % 10, count);
	}
	else
		ft_putchar (n + 48, count);
}

void	ft_putunsigned(unsigned int n, int *count)
{
	if (n >= 10)
	{
		ft_putunsigned(n / 10, count);
		ft_putunsigned(n % 10, count);
	}
	else
	{
		ft_putchar(n + '0', count);
	}
}
