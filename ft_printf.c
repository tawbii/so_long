/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atawbi <atawbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 14:43:00 by atawbi            #+#    #+#             */
/*   Updated: 2024/12/25 15:10:32 by atawbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_bigdecimal(unsigned int n)
{
	char	*hex_digits;
	int		count;

	count = 0;
	hex_digits = "0123456789ABCDEF";
	if (n < 16)
	{
		write(1, &hex_digits[n], 1);
		return (1);
	}
	else
	{
		count += ft_bigdecimal(n / 16);
		write(1, &hex_digits[n % 16], 1);
	}
	return (count + 1);
}

static int	ft_ft_smalldecimal(unsigned long n)
{
	char	*hex_digits;
	int		count;

	count = 0;
	hex_digits = "0123456789abcdef";
	if (n < 16)
	{
		write(1, &hex_digits[n], 1);
		return (1);
	}
	else
	{	
		count += ft_ft_smalldecimal(n / 16);
		write(1, &hex_digits[n % 16], 1);
	}
	return (count + 1);
}

int	ft_p(void *p)
{
	unsigned long	n;
	int				c;

	n = (unsigned long)p;
	c = 0;
	if (!p)
	{
		return (write(1, "(nil)", 5));
	}
	c += write(1, "0x", 2);
	c += ft_ft_smalldecimal(n);
	return (c);
}

int	ft_format(va_list va, const char *str)
{
	int	c;

	c = 0;
	if (*str == 'c')
		c += ft_putchar(va_arg(va, int));
	else if (*str == 's')
		c += ft_putstr(va_arg(va, char *));
	else if (*str == 'd')
		c += ft_putnbr(va_arg(va, int));
	else if (*str == 'i')
		c += ft_putnbr(va_arg(va, int));
	else if (*str == 'u')
		c += ft_unputnbr(va_arg(va, unsigned int));
	else if (*str == 'x')
		c += ft_smalldecimal(va_arg(va, unsigned int));
	else if (*str == 'X')
		c += ft_bigdecimal(va_arg(va, unsigned int));
	else if (*str == '%')
		c += ft_putchar('%');
	else if (*str == 'p')
		c += ft_p(va_arg(va, void *));
	return (c);
}

int	ft_printf(const char *str, ...)
{
	size_t	count;
	int		i;
	va_list	va;

	count = 0;
	i = 0;
	if (!str)
		return (0);
	va_start(va, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			i++;
			count += ft_format(va, &str[i]);
		}
		else
		{
			count += ft_putchar(str[i]);
		}
		i++;
	}
	va_end(va);
	return (count);
}
