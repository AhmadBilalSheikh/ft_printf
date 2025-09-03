/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbilal <ahbilal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 17:06:47 by ahbilal           #+#    #+#             */
/*   Updated: 2025/09/03 19:11:17 by ahbilal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(unsigned int n, int uppercase)
{
	char	*base;
	int		count;
	int		temp;

	if (uppercase)
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	count = 0;
	if (n >= 16)
	{
		temp = ft_puthex(n / 16, uppercase);
		if (temp < 0)
			return (-1);
		count += temp;
	}
	temp = ft_putchar(base[n % 16]);
	if (temp < 0)
		return (-1);
	count += temp;
	return (count);
}
