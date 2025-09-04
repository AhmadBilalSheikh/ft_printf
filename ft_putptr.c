/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbilal <ahbilal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 17:01:54 by ahbilal           #+#    #+#             */
/*   Updated: 2025/09/04 21:35:45 by ahbilal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putptr_rec(unsigned long n)
{
	int		count;
	int		temp;
	char	*base;

	base = "0123456789abcdef";
	if (n >= 16)
	{
		count = ft_putptr_rec(n / 16);
		if (count < 0)
			return (-1);
		temp = ft_putchar(base[n % 16]);
		if (temp < 0)
			return (-1);
		return (count + temp);
	}
	return (ft_putchar(base[n % 16]));
}

int	ft_putptr(void *ptr)
{
	unsigned long	addr;
	int				count;
	int				temp;

	if (ptr == NULL)
		return (ft_putstr(NULL_PTR));
	addr = (unsigned long)ptr;
	count = write(1, "0x", 2);
	if (count < 0)
		return (-1);
	temp = ft_putptr_rec(addr);
	if (temp < 0)
		return (-1);
	return (count + temp);
}
