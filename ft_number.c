/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_number.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdulba <sabdulba@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 22:14:23 by sabdulba          #+#    #+#             */
/*   Updated: 2024/11/09 16:53:05 by sabdulba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(int n, int *count)
{
	long	nbr;
	char	digit;

	nbr = n;
	if (nbr < 0)
	{
		write(1, "-", 1);
		nbr = -nbr;
		(*count)++;
	}
	if (nbr > 9)
		ft_putnbr(nbr / 10, count);
	digit = (nbr % 10) + 48;
	ft_putchar(digit, count);
}

void	ft_unsigned(unsigned int n, int *count)
{
	if (n > 9)
		ft_unsigned(n / 10, count);
	ft_putchar((n % 10) + 48, count);
}

//Used unsigned long to reuse for pointer
void	ft_hex(unsigned long n, int *count, char up_low)
{
	char	convert[25];
	char	*base;
	int		i;

	if (up_low == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	i = 0;
	while (n != 0)
	{
		convert[i] = base[n % 16];
		n /= 16;
		i++;
	}
	while (i--)
		ft_putchar(convert[i], count);
}

void	ft_pointer(size_t point, int *count)
{
	write(1, "0x", 2);
	(*count) += 2;
	ft_hex(point, count, 'x');
}
