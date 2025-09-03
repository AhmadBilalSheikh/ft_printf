/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbilal <ahbilal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 17:01:54 by ahbilal           #+#    #+#             */
/*   Updated: 2025/09/03 19:27:37 by ahbilal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_hex_no_lead(uintptr_t num)
{
	int	count;
	int	temp;
	int	digit;
	int	i;
	int	start_print;

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

static int	putstr_ptr_prefix(void)
{
	if (ft_putchar('0') < 0)
		return (-1);
	if (ft_putchar('x') < 0)
		return (-1);
	return (2);
}

int	ft_putptr(unsigned long ptr)
{
	int	count;
	int	temp;

	count = putstr_ptr_prefix();
	if (count < 0)
		return (-1);
	if (ptr == 0)
	{
		temp = ft_putchar('0');
		if (temp < 0)
			return (-1);
		return (count + temp);
	}
	temp = print_hex_no_lead(ptr);
	if (temp < 0)
		return (-1);
	return (count + temp);
}
