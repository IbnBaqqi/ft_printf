/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdulba <sabdulba@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 15:47:34 by sabdulba          #+#    #+#             */
/*   Updated: 2024/11/09 00:43:21 by sabdulba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void check_format(char c, va_list *ptr, int *count)
{
	if (c == 's')
		ft_putstr(va_arg(*ptr, char *), count);
}

// Base function
int ft_printf(const char *str, ...)
{
	va_list	ptr;
	int		i;
	int		count;
	
	i = 0;
	count = 0;
	va_start(ptr, str);
	while(str[i] != '\0')
	{
		if (str[i] == '%')
		{
			i++;
			check_format(str[i], &ptr, &count);
			i++;
		}
		else
		{
			ft_putchar((char)str[i], &count);
			i++;
		}
	}
	va_end(ptr);
	return (count);
}

int	main(void)
{
	int res;
	int res1;
	
	res = ft_printf("Hive %s\n", "Helsinki.");
	res1 = printf("Hive %s\n", "Helsinki.");
	printf("%d\n", res);
	printf("%d\n", res1);
	return (0);
}