/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_number.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdulba <sabdulba@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 22:14:23 by sabdulba          #+#    #+#             */
/*   Updated: 2024/11/09 01:52:58 by sabdulba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void ft_putnbr(int n, int *count)
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
	if (nbr == 0)
	{
		write(1, "0", 1);
		(*count)++;
	}
	if (nbr > 9)
		ft_putnbr(nbr / 10, count++);
	digit = (nbr % 10) + 48;
	write(1, &digit, 1);
}
