/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hexadecimal.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belguabd <belguabd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 16:46:29 by belguabd          #+#    #+#             */
/*   Updated: 2023/11/23 11:40:25 by belguabd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_hexadecimal(unsigned long n, int *count)
{
	if (n >= 16)
	{
		print_hexadecimal(n / 16, count);
		print_hexadecimal(n % 16, count);
	}
	else
	{
		if (n < 10)
			ft_putchar(n + '0', count);
		else
			ft_putchar(n - 10 + 'A', count);
	}
}

void	print_hexadecimal_lowercase(unsigned long n, int *count)
{
	if (n >= 16)
	{
		print_hexadecimal_lowercase(n / 16, count);
		print_hexadecimal_lowercase(n % 16, count);
	}
	else
	{
		if (n < 10)
			ft_putchar(n + '0', count);
		else
			ft_putchar(n - 10 + 'a', count);
	}
}
