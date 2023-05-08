/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojamal <ojamal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 00:41:59 by ojamal            #+#    #+#             */
/*   Updated: 2023/05/08 15:31:22 by ojamal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>

void ft_putchar(char c, int *len)
{
	write(1, &c, 1);
	*len = *len + 1;
}

void	ft_putstr(char *str, int *len)
{
	int i = 0;
	if(!str)
		str = "(null)";
	while(str[i])
	{
		ft_putchar(str[i], len);
		i++;
	}
}

void ft_putnbr(int n, int *len)
{
	if (n == -2147483648)
	{
		ft_putstr("-2147483648", len);
		return ;
	}
	if (n < 0)
	{
		n *= -1;
		ft_putchar('-', len);
	}
	if (n <= 9)
	{
		n += '0';
		ft_putchar(n, len);
	}
	else
	{
		ft_putnbr(n / 10, len);
		ft_putnbr(n % 10, len);
	}
}

void ft_puthex(unsigned int n, int *len)
{
	char str[] = "0123456789abcdef";
	if (n <= 16)
	{
		n += '0';
		ft_putchar(str[n % 16], len);
	}
	else
	{
		ft_puthex(n / 16, len);
		ft_puthex(n % 16, len);
	}
}

int ft_printf(const char *str, ...)
{
	va_list ap;
	int len = 0;
	int i = 0;
	va_start(ap, str);
	while(str[i])
	{
		if(str[i] == '%' && str[i + 1])
		{
			i++;
			if (str[i] == 's')
				ft_putstr(va_arg(ap, char *), &len);
			else if (str[i] == 'd')
				ft_putnbr((long long int)va_arg(ap, int), &len);
			else if (str[i] == 'x')
				ft_puthex((long long int)va_arg(ap, unsigned int), &len);
		}
		else
			ft_putchar(str[i], &len);
			i++;
	}
	va_end(ap);
	return len;
}
