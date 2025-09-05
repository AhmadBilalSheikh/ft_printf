/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbilal <ahbilal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 17:00:49 by ahbilal           #+#    #+#             */
/*   Updated: 2025/09/05 19:03:02 by ahbilal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	add_char_count(int c, int *count)
{
	int	temp;

	temp = ft_putchar(c);
	if (temp < 0)
		return (-1);
	*count += temp;
	return (0);
}

int	ft_putnbr(int n)
{
	int		count;
	long	nb;
	int		temp;

	count = 0;
	nb = n;
	if (nb < 0)
	{
		if (add_char_count('-', &count) < 0)
			return (-1);
		nb = -nb;
	}
	if (nb >= 10)
	{
		temp = ft_putnbr(nb / 10);
		if (temp < 0)
			return (-1);
		count += temp;
	}
	if (add_char_count(nb % 10 + '0', &count) < 0)
		return (-1);
	return (count);
}
