/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belguabd <belguabd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 09:37:46 by belguabd          #+#    #+#             */
/*   Updated: 2023/11/27 20:25:47 by belguabd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

void	ft_putchar(char c, int *count);
void	ft_putnbr(int n, int *count);
int		ft_putstr(char *str);
void	print_hexadecimal(unsigned long n, int *count);
void	print_hexadecimal_lowercase(unsigned long n, int *count);
int		ft_printf(const char *format, ...);
void	ft_putunsigned(unsigned int n, int *count);

#endif