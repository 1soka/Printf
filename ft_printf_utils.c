/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ******** <marvin@d42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/26 17:31:28 by ********          #+#    #+#             */
/*   Updated: 2026/10/27 18:06:15 by ********         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_pointer(void *ptr)
{
	char	*buffer;
	int		i;
	int		count;

	count = 0;
	buffer = "0123456789abcdef";
	if (!ptr)
		return (ft_putstr("(nil)"));
	count += ft_putstr("0x");
	i = 0;
	count += ft_putnbr_hexa((unsigned long)ptr, 0);
	return (count);
}

int	ft_putnbr_hexa(unsigned long long nb, int maj)
{
	char	*buffer;
	int		count;

	count = 0;
	buffer = "0123456789abcdef";
	if (maj)
		buffer = "0123456789ABCDEF";
	if (nb == 0)
		return (ft_putchar('0'));
	if (nb >= 16)
		count += ft_putnbr_hexa(nb / 16, maj);
	count += ft_putchar(buffer[nb % 16]);
	return (count);
}

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	write(1, str, ft_strlen(str));
	return (ft_strlen(str));
}

int	ft_putnbr(int nb, int is_unsigned)
{
	char	c;
	int		count;

	count = 0;
	if (!is_unsigned)
	{
		if (nb == -2147483648)
		{
			count += ft_putstr("-2147483648");
			return (count);
		}
		else if (nb < 0)
		{
			count += ft_putchar('-');
			nb = -nb;
		}
	}
	if (nb > 9)
		count += ft_putnbr(nb / 10, is_unsigned);
	c = (nb % 10) + '0';
	count += ft_putchar(c);
	return (count);
}
