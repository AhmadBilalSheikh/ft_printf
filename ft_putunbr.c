/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbilal <ahbilal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 17:17:55 by ahbilal           #+#    #+#             */
/*   Updated: 2025/09/03 19:10:55 by ahbilal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunbr(unsigned int n)
{
	int	count;
	int	temp;

	count = 0;
	if (n >= 10)
	{
		temp = ft_putunbr(n / 10);
		if (temp < 0)
			return (-1);
		count += temp;
	}
	temp = ft_putchar((n % 10) + '0');
	if (temp < 0)
		return (-1);
	count += temp;
	return (count);
}
