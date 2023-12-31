/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soelalou <soelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 18:23:37 by soelalou          #+#    #+#             */
/*   Updated: 2023/11/28 00:30:16 by soelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	print_var(va_list ap, const char format)
{
	int	i;

	i = 0;
	if (format == 'c')
		i += ft_putchar_fd(va_arg(ap, int), 0);
	else if (format == 's')
		i += ft_putstr_fd(va_arg(ap, char *), 0);
	else if (format == 'p')
		i += ft_putaddr_fd(va_arg(ap, void *), 0);
	else if (format == 'd' || format == 'i')
		i += ft_putnbr_fd(va_arg(ap, int), 0);
	else if (format == 'u')
		i += ft_putunbr_fd(va_arg(ap, unsigned int), 0);
	else if (format == 'x')
		i += ft_puthex_fd(va_arg(ap, unsigned int), "0123456789abcdef", 0);
	else if (format == 'X')
		i += ft_puthex_fd(va_arg(ap, unsigned int), "0123456789ABCDEF", 0);
	else if (format == '%')
		i += ft_putchar_fd('%', 0);
	else
		i += ft_putstr_fd("%(INVALID_FLAG)", 0);
	return (i);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	va_list	ap;

	if (!format)
		return (-1);
	i = 0;
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			i += print_var(ap, *format);
		}
		else
			i += ft_putchar_fd(*format, 0);
		format++;
	}
	va_end(ap);
	return (i);
}
