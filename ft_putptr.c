/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbilal <ahbilal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 17:01:54 by ahbilal           #+#    #+#             */
/*   Updated: 2025/08/12 17:01:56 by ahbilal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr(unsigned long ptr)
{
	char	*base;
	int		count;

	base = "0123456789abcdef";
	count = 0;
	if (ptr >= 16)
		count += ft_putptr(ptr / 16);
	count += ft_putchar(base[ptr % 16]);
	return (count);
}
