/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_text.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 14:00:35 by ivmirand          #+#    #+#             */
/*   Updated: 2025/01/09 11:19:58 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

size_t	ft_print_char(int c)
{
	ft_putchar_fd(c, 1);
	return (1);
}

size_t	ft_print_string(char *str)
{
	size_t	result;

	if (str == NULL)
	{
		ft_putstr_fd("(null)", 1);
		result = 6;
	}
	else if (str[0] == '\0')
	{
		ft_putstr_fd("", 1);
		result = 0;
	}
	else
	{
		ft_putstr_fd(str, 1);
		result = ft_strlen(str);
	}
	return (result);
}

size_t	ft_print_address(void *addr)
{
	size_t	result;

	if (addr == NULL)
		return (ft_print_string(NIL));
	result = ft_print_string("0x");
	result += ft_print_hex(addr, FALSE, 7);
	return (result);
}
