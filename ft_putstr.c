/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbilal <ahbilal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 16:57:20 by ahbilal           #+#    #+#             */
/*   Updated: 2025/09/03 19:26:38 by ahbilal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *s)
{
	int	i;
	int	count;
	int	temp;

	if (!s)
		return (write(1, "(null)", 6));
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
// #include "ft_printf.h"

// static int	putstr_base(char *s)
// {
// 	int	count;
// 	int	temp;

// 	count = 0;
// 	while (*s)
// 	{
// 		temp = ft_putchar(*s);
// 		if (temp < 0)
// 			return (-1);
// 		count += temp;
// 		s++;
// 	}
// 	return (count);
// }

// int	ft_putstr(void *data, int type)
// {
// 	if (type == STRING_TYPE)
// 	{
// 		if (!data)
// 			return (putstr_base("(null)"));
// 		return (putstr_base((char *)data));
// 	}
// 	return (0);
// }
