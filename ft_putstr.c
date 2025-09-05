/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbilal <ahbilal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 16:57:20 by ahbilal           #+#    #+#             */
/*   Updated: 2025/09/05 13:40:52 by ahbilal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *s)
{
	int	i;
	int	count;
	int	temp;

	if (!s)
		s = "(null)";
	count = 0;
	i = 0;
	while (s[i])
	{
		temp = ft_putchar(s[i]);
		if (temp == -1)
			return (-1);
		count += temp;
		i++;
	}
	return (count);
}
