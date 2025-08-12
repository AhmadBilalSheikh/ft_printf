/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbilal <ahbilal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 16:57:20 by ahbilal           #+#    #+#             */
/*   Updated: 2025/08/12 18:20:03 by ahbilal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	putstr_base(char *s)
{
	int	count;
	int	temp;

	count = 0;
	while (*s)
	{
		temp = ft_putchar(*s);
		if (temp < 0)
			return (-1);
		count += temp;
		s++;
	}
	return (count);
}

static int	putstr_ptr_prefix(void)
{
	int	count;
	int	temp;

	count = 0;
	temp = ft_putchar('0');
	if (temp < 0)
		return (-1);
	count += temp;
	temp = ft_putchar('x');
	if (temp < 0)
		return (-1);
	count += temp;
	return (count);
}

static int	print_hex_no_lead(uintptr_t num)
{
	int	i;
	int	start_print;
	int	digit;
	int	count;
	int	temp;

	i = (sizeof(uintptr_t) * 2) - 1;
	start_print = 0;
	count = 0;
	while (i >= 0)
	{
		digit = (num >> (i * 4)) & 0xF;
		if (digit != 0 || start_print)
		{
			start_print = 1;
			temp = ft_putchar("0123456789abcdef"[digit]);
			if (temp < 0)
				return (-1);
			count += temp;
		}
		i--;
	}
	return (count);
}

static int	putstr_ptr(uintptr_t num)
{
	int	count;
	int	temp;

	count = putstr_ptr_prefix();
	if (count < 0)
		return (-1);
	if (num == 0)
	{
		temp = ft_putchar('0');
		if (temp < 0)
			return (-1);
		return (count + temp);
	}
	temp = print_hex_no_lead(num);
	if (temp < 0)
		return (-1);
	return (count + temp);
}

int	ft_putstr(void *data, int type)
{
	if (type == STRING_TYPE)
	{
		if (!data)
			return (putstr_base("(null)"));
		return (putstr_base((char *)data));
	}
	else if (type == PTR_TYPE)
		return (putstr_ptr((uintptr_t)data));
	return (0);
}
