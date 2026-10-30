/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ******** <marvin@d42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/26 17:24:57 by ********          #+#    #+#             */
/*   Updated: 2026/10/27 18:25:49 by ********         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int	ft_printf(const char *str, ...);
int	ft_strlen(const char *str);
int	ft_putnbr_hexa(unsigned long long nb, int maj);
int	ft_putnbr_unsigned(unsigned int nb);
int	ft_print_pointer(void *ptr);
int	ft_putchar(char c);
int	ft_putstr(char *str);
int	ft_putnbr(int nb, int is_unsigned);

#endif
