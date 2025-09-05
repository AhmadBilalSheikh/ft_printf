/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbilal <ahbilal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 16:40:58 by ahbilal           #+#    #+#             */
/*   Updated: 2025/09/05 15:51:31 by ahbilal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	handle_spec(char spec, va_list args)
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

static int	process_spec(const char *input, int *i, va_list args)
{
	int	temp;

	(*i)++;
	temp = handle_spec(input[*i], args);
	if (temp < 0)
		return (-1);
	return (temp);
}

static int	print(char c)
{
	int	temp;

	temp = ft_putchar(c);
	if (temp < 0)
		return (-1);
	return (temp);
}

int	ft_printf(const char *input, ...)
{
	va_list	args;
	int		i;
	int		count;
	int		temp;

	va_start(args, input);
	i = 0;
	count = 0;
	while (input[i])
	{
		if (input[i] == '%' && input[i + 1])
			temp = process_spec(input, &i, args);
		else
			temp = print(input[i]);
		if (temp < 0)
			return (va_end(args), -1);
		count += temp;
		i++;
	}
	va_end(args);
	return (count);
}
// #include <stdio.h>
// #include <limits.h>
// #include <unistd.h>
// #include <stdlib.h>

// int main(void)
// {
//     int ret1, ret2;
//     void *null_ptr = NULL;
//     char *null_str = NULL;

//     printf("----- [CHAR] %%c -----\n");
//     ret1 = printf("printf   : [%c]\n", 'A');
//     ret2 = ft_printf("ft_printf: [%c]\n", 'A');
//     printf("Returns  : printf = %d, ft_printf = %d\n\n", ret1, ret2);

//     printf("----- [STRING] %%s -----\n");
//     ret1 = printf("printf   : [%s]\n", "Hello, world!");
//     ret2 = ft_printf("ft_printf: [%s]\n", "Hello, world!");
//     printf("Returns  : printf = %d, ft_printf = %d\n\n", ret1, ret2);

//     printf("----- [NULL STRING] %%s -----\n");
//     ret1 = printf("printf   : [%s]\n", null_str);
//     ret2 = ft_printf("ft_printf: [%s]\n", null_str);
//     printf("Returns  : printf = %d, ft_printf = %d\n\n", ret1, ret2);

//     printf("----- [EMPTY STRING] %%s -----\n");
//     ret1 = printf("printf   : [%s]\n", "");
//     ret2 = ft_printf("ft_printf: [%s]\n", "");
//     printf("Returns  : printf = %d, ft_printf = %d\n\n", ret1, ret2);

//     printf("----- [POINTER] %%p -----\n");
//     ret1 = printf("printf   : [%p]\n", (void*)&ret1);
//     ret2 = ft_printf("ft_printf: [%p]\n", (void*)&ret1);
//     printf("Returns  : printf = %d, ft_printf = %d\n\n", ret1, ret2);

//     printf("----- [NULL POINTER] %%p -----\n");
//     ret1 = printf("printf   : [%p]\n", null_ptr);
//     ret2 = ft_printf("ft_printf: [%p]\n", null_ptr);
//     printf("Returns  : printf = %d, ft_printf = %d\n\n", ret1, ret2);

//     printf("----- [DECIMAL] %%d -----\n");
//     ret1 = printf("printf   : [%d]\n", 12345);
//     ret2 = ft_printf("ft_printf: [%d]\n", 12345);
//     printf("Returns  : printf = %d, ft_printf = %d\n\n", ret1, ret2);

//     printf("----- [DECIMAL NEGATIVE] %%d -----\n");
//     ret1 = printf("printf   : [%d]\n", -12345);
//     ret2 = ft_printf("ft_printf: [%d]\n", -12345);
//     printf("Returns  : printf = %d, ft_printf = %d\n\n", ret1, ret2);

//     printf("----- [INT MIN/MAX] %%d -----\n");
//     ret1 = printf("printf   : [INT_MIN = %d | INT_MAX = %d]\n",
//     INT_MIN, INT_MAX);
//     ret2 = ft_printf("ft_printf: [INT_MIN = %d | INT_MAX = %d]\n",
//     INT_MIN, INT_MAX);
//     printf("Returns  : printf = %d, ft_printf = %d\n\n", ret1, ret2);

//     printf("----- [INTEGER] %%i -----\n");
//     ret1 = printf("printf   : [%i]\n", 42);
//     ret2 = ft_printf("ft_printf: [%i]\n", 42);
//     printf("Returns  : printf = %d, ft_printf = %d\n\n", ret1, ret2);

//     printf("----- [UNSIGNED] %%u -----\n");
//     ret1 = printf("printf   : [%u]\n", 1234567890);
//     ret2 = ft_printf("ft_printf: [%u]\n", 1234567890);
//     printf("Returns  : printf = %d, ft_printf = %d\n\n", ret1, ret2);

//     printf("----- [UNSIGNED MAX] %%u -----\n");
//     ret1 = printf("printf   : [%u]\n", UINT_MAX);
//     ret2 = ft_printf("ft_printf: [%u]\n", UINT_MAX);
//     printf("Returns  : printf = %d, ft_printf = %d\n\n", ret1, ret2);

//     printf("----- [HEXADECIMAL LOWERCASE] %%x -----\n");
//     ret1 = printf("printf   : [%x]\n", 3735928559U); // 0xDEADBEEF
//     ret2 = ft_printf("ft_printf: [%x]\n", 3735928559U);
//     printf("Returns  : printf = %d, ft_printf = %d\n\n", ret1, ret2);

//     printf("----- [HEXADECIMAL UPPERCASE] %%X -----\n");
//     ret1 = printf("printf   : [%X]\n", 3735928559U);
//     ret2 = ft_printf("ft_printf: [%X]\n", 3735928559U);
//     printf("Returns  : printf = %d, ft_printf = %d\n\n", ret1, ret2);

//     printf("----- [ZERO VALUE] %%d %%u %%x %%p -----\n");
//     ret1 = printf("printf   : %d | %u | %x | %p\n", 0, 0, 0, (void*)0);
//     ret2 = ft_printf("ft_printf: %d | %u | %x | %p\n", 0, 0, 0, (void*)0);
//     printf("Returns  : printf = %d, ft_printf = %d\n\n", ret1, ret2);

//     printf("----- [PERCENT SIGN] %% -----\n");
//     ret1 = printf("printf   : [%%]\n");
//     ret2 = ft_printf("ft_printf: [%%]\n");
//     printf("Returns  : printf = %d, ft_printf = %d\n\n", ret1, ret2);

//     printf("----- [MIXED FORMAT STRING] -----\n");
//     ret1 = printf("printf   : [%c] [%s] [%d] [%u] [%x] [%%]\n", 'Z', 
//     "abc", -42, 42, 255);
//     ret2 = ft_printf("ft_printf: [%c] [%s] [%d] [%u] [%x] [%%]\n", 'Z',
//     "abc", -42, 42, 255);
//     printf("Returns  : printf = %d, ft_printf = %d\n\n", ret1, ret2);

//     return 0;
// }
// #include <stdio.h>

// int main()
// {
//     const char *format = "Number: %d! Next char.\n";
//     int val = 42;
//     int std_ret, ft_ret;

//     std_ret = printf(format, val);
//     ft_ret = ft_printf(format, val);

//     printf("Standard printf returned: %d\n", std_ret);
//     printf("ft_printf returned      : %d\n", ft_ret);

//     if (std_ret != ft_ret)
//         printf("Return values differ! There might be a bug.\n");
//     else
//         printf("Return values match.\n");

//     return 0;
// }
