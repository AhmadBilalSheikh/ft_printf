/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbilal <ahbilal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 16:40:58 by ahbilal           #+#    #+#             */
/*   Updated: 2025/08/12 17:58:19 by ahbilal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	handle_format(char spec_ltr, va_list args)
{
	if (spec_ltr == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (spec_ltr == 's')
		return (ft_putstr(va_arg(args, char *), STRING_TYPE));
	else if (spec_ltr == 'd' || spec_ltr == 'i')
		return (ft_putnbr(va_arg(args, int)));
	else if (spec_ltr == 'u')
		return (ft_putunbr(va_arg(args, unsigned int)));
	else if (spec_ltr == 'x')
		return (ft_puthex(va_arg(args, unsigned int), 0));
	else if (spec_ltr == 'X')
		return (ft_puthex(va_arg(args, unsigned int), 1));
	else if (spec_ltr == 'p')
		return (ft_putstr((void *)va_arg(args, void *), PTR_TYPE));
	else if (spec_ltr == '%')
		return (ft_putchar('%'));
	return (0);
}

static int	process_format(const char *format, int *i, va_list args)
{
	int	temp;

	(*i)++;
	temp = handle_format(format[*i], args);
	if (temp < 0)
		return (-1);
	return (temp);
}

static int	process_char(char c)
{
	int	temp;

	temp = ft_putchar(c);
	if (temp < 0)
		return (-1);
	return (temp);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		printed;
	int		temp;

	va_start(args, format);
	i = 0;
	printed = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
			temp = process_format(format, &i, args);
		else
			temp = process_char(format[i]);
		if (temp < 0)
			return (va_end(args), -1);
		printed += temp;
		i++;
	}
	va_end(args);
	return (printed);
}
