/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ******** <marvin@d42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/26 17:17:05 by ********          #+#    #+#             */
/*   Updated: 2026/10/27 18:06:43 by ********         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	is_a_param(char c, char *arr)
{
	int	i;

	i = 0;
	while (arr[i] != '\0')
		if (arr[i++] == c)
			return (1);
	return (0);
}

int	ft_putnbr_unsigned(unsigned int nb)
{
	int	count;

	count = 0;
	if (nb >= 10)
		count += ft_putnbr_unsigned(nb / 10);
	count += ft_putchar((nb % 10) + '0');
	return (count);
}

int	ft_printf_helper(const char format, va_list args)
{
	if (format == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (format == 's')
		return (ft_putstr((va_arg(args, char *))));
	else if (format == 'p')
		return (ft_print_pointer(va_arg(args, void *)));
	else if (format == 'd' || format == 'i')
		return (ft_putnbr(va_arg(args, int), 0));
	else if (format == 'u')
		return (ft_putnbr_unsigned(va_arg(args, unsigned int)));
	else if (format == 'x')
		return (ft_putnbr_hexa(va_arg(args, unsigned int), 0));
	else if (format == 'X')
		return (ft_putnbr_hexa(va_arg(args, unsigned int), 1));
	else if (format == '%')
		return (ft_putchar('%'));
	else
		return (ft_putchar(va_arg(args, int)));
}

int	ft_printf(const char *str, ...)
{
	int		length;
	va_list	args;
	char	*arr;
	int		i;

	length = 0;
	i = 0;
	arr = "cspdiuxX%";
	if (!str)
		return (-1);
	va_start(args, str);
	while (str[i] != '\0')
	{
		if (i < ft_strlen(str) - 1 && str[i] == '%' && is_a_param(str[i + 1],
				arr))
		{
			length += ft_printf_helper(str[i + 1], args);
			i += 2;
		}
		else
			length += ft_putchar(str[i++]);
	}
	va_end(args);
	return (length);
}
