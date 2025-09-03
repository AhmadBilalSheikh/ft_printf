/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbilal <ahbilal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 16:40:58 by ahbilal           #+#    #+#             */
/*   Updated: 2025/09/03 19:26:07 by ahbilal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	handle_format(char spec_ltr, va_list args)
{
	if (spec_ltr == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (spec_ltr == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (spec_ltr == 'd' || spec_ltr == 'i')
		return (ft_putnbr(va_arg(args, int)));
	else if (spec_ltr == 'u')
		return (ft_putunbr(va_arg(args, unsigned int)));
	else if (spec_ltr == 'x')
		return (ft_puthex(va_arg(args, unsigned int), 0));
	else if (spec_ltr == 'X')
		return (ft_puthex(va_arg(args, unsigned int), 1));
	else if (spec_ltr == 'p')
		return (ft_putptr((unsigned long)va_arg(args, void *)));
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
// #include "ft_printf.h"
// #include <stdio.h>
// #include <limits.h>

// int main(void)
// {
//     int i = 42;
//     int *ptr = &i;
//     void *null_ptr = NULL;
//     char c = 'A';
//     char *str = "Hello, world!";
//     char *null_str = NULL;
//     int n_neg = -12345;
//     unsigned int u_max = UINT_MAX;
//     int n_zero = 0;

//     printf("===== TESTING %%c =====\n");
//     printf("printf:  [%c]\n", c);
//     ft_printf("ft_printf: [%c]\n\n", c);

//     printf("===== TESTING %%s =====\n");
//     printf("printf:  [%s]\n", str);
//     ft_printf("ft_printf: [%s]\n", str);

//     printf("printf with NULL string:\n");
//     printf("printf:  [%s]\n", null_str);
//     ft_printf("ft_printf: [%s]\n\n", null_str);

//     printf("===== TESTING %%p =====\n");
//     printf("printf pointer: %p\n", ptr);
//     ft_printf("ft_printf pointer: %p\n", ptr);

//     printf("printf NULL pointer:\n");
//     printf("printf: %p\n", null_ptr);
//     ft_printf("ft_printf: %p\n\n", null_ptr);

//     printf("===== TESTING %%d and %%i =====\n");
//     printf("printf: %d\n", n_neg);
//     ft_printf("ft_printf: %d\n", n_neg);

//     printf("printf zero: %d\n", n_zero);
//     ft_printf("ft_printf zero: %d\n\n", n_zero);

//     printf("printf INT_MAX: %d\n", INT_MAX);
//     ft_printf("ft_printf INT_MAX: %d\n", INT_MAX);

//     printf("printf INT_MIN: %d\n", INT_MIN);
//     ft_printf("ft_printf INT_MIN: %d\n\n", INT_MIN);

//     printf("===== TESTING %%u =====\n");
//     printf("printf: %u\n", u_max);
//     ft_printf("ft_printf: %u\n", u_max);

//     printf("printf zero: %u\n", n_zero);
//     ft_printf("ft_printf zero: %u\n\n", n_zero);

//     printf("===== TESTING %%x and %%X =====\n");
//     printf("printf: %x\n", u_max);
//     ft_printf("ft_printf: %x\n", u_max);

//     printf("printf: %X\n", u_max);
//     ft_printf("ft_printf: %X\n", u_max);

//     printf("printf zero: %x\n", n_zero);
//     ft_printf("ft_printf zero: %x\n", n_zero);

//     printf("printf zero: %X\n", n_zero);
//     ft_printf("ft_printf zero: %X\n\n", n_zero);

//     printf("===== TESTING %%%% =====\n");
//     printf("printf: %%\n");
//     ft_printf("ft_printf: %%\n");

//     return 0;
// }
