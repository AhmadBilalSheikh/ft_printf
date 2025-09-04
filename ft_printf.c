/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbilal <ahbilal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 16:40:58 by ahbilal           #+#    #+#             */
/*   Updated: 2025/09/04 21:38:58 by ahbilal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	handle_format(char spec, va_list args)
{
	if (spec == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (spec == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (spec == 'd' || spec == 'i')
		return (ft_putnbr(va_arg(args, int)));
	else if (spec == 'u')
		return (ft_putunbr(va_arg(args, unsigned int)));
	else if (spec == 'x')
		return (ft_puthex(va_arg(args, unsigned int), 0));
	else if (spec == 'X')
		return (ft_puthex(va_arg(args, unsigned int), 1));
	else if (spec == 'p')
		return (ft_putptr(va_arg(args, void *)));
	else if (spec == '%')
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
//     int ret1, ret2;

//     // ----------------------
//     // Test %c
//     // ----------------------
//     printf("=== Test %%c ===\n");
//     ret1 = printf("Original: %c\n", 'A');
//     ret2 = ft_printf("Mine    : %c\n", 'A');
//     printf("Return values: original=%d mine=%d\n\n", ret1, ret2);

//     // ----------------------
//     // Test %s
//     // ----------------------
//     printf("=== Test %%s ===\n");
//     ret1 = printf("Original: %s\n", "Hello, world!");
//     ret2 = ft_printf("Mine    : %s\n", "Hello, world!");
//     printf("Return values: original=%d mine=%d\n", ret1, ret2);

//     // NULL string
//     ret1 = printf("Original NULL: %s\n", NULL);
//     ret2 = ft_printf("Mine NULL    : %s\n", NULL);
//     printf("Return values: original=%d mine=%d\n\n", ret1, ret2);

//     // ----------------------
//     // Test %d / %i
//     // ----------------------
//     printf("=== Test %%d / %%i ===\n");
//     ret1 = printf("Original: %d %i %d %i\n", 42, -42, INT_MAX, INT_MIN);
//     ret2 = ft_printf("Mine    : %d %i %d %i\n", 42, -42, INT_MAX, INT_MIN);
//     printf("Return values: original=%d mine=%d\n\n", ret1, ret2);

//     // ----------------------
//     // Test %u
//     // ----------------------
//     printf("=== Test %%u ===\n");
//     ret1 = printf("Original: %u %u\n", 0, UINT_MAX);
//     ret2 = ft_printf("Mine    : %u %u\n", 0, UINT_MAX);
//     printf("Return values: original=%d mine=%d\n\n", ret1, ret2);

//     // ----------------------
//     // Test %x / %X
//     // ----------------------
//     printf("=== Test %%x / %%X ===\n");
//     ret1 = printf("Original: %x %X %x %X\n", 255, 255, 0, UINT_MAX);
//     ret2 = ft_printf("Mine    : %x %X %x %X\n", 255, 255, 0, UINT_MAX);
//     printf("Return values: original=%d mine=%d\n\n", ret1, ret2);

//     // ----------------------
//     // Test %p
//     // ----------------------
//     printf("=== Test %%p ===\n");
//     int x = 42;
//     ret1 = printf("Original: %p %p %p\n", &x, NULL, (void *)ULONG_MAX);
//     ret2 = ft_printf("Mine    : %p %p %p\n", &x, NULL, (void *)ULONG_MAX);
//     printf("Return values: original=%d mine=%d\n\n", ret1, ret2);

//     // ----------------------
//     // Test %%
//     // ----------------------
//     printf("=== Test %% ===\n");
//     ret1 = printf("Original: %% %% %%\n");
//     ret2 = ft_printf("Mine    : %% %% %%\n");
//     printf("Return values: original=%d mine=%d\n\n", ret1, ret2);

//     return 0;
// }
