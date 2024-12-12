/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 14:02:34 by ivmirand          #+#    #+#             */
/*   Updated: 2024/12/12 11:21:42 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

static size_t	ft_process_char(char *c, va_list ap)
{
	size_t	result;

	result = 0;
	if (*c == 'c')
		result = ft_print_char(va_arg(ap, int));
	else if (*c == 's')
		result = ft_print_string(va_arg(ap, char *));
	else if (*c == 'p')
		result = ft_print_address(va_arg(ap, void *));
	else if (*c == 'd' || *c == 'i')
		result = ft_print_int(va_arg(ap, int));
	else if (*c == 'u')
		result = ft_print_uint(va_arg(ap, unsigned int));
	else if (*c == 'x')
		result = ft_print_hex(va_arg(ap, void *), FALSE, 3);
	else if (*c == 'X')
		result = ft_print_hex(va_arg(ap, void *), TRUE, 3);
	else if (*c == '%')
		result = ft_print_char('%');
	return (result);
}

int	ft_printf(char const *str, ...)
{
	va_list	ap;
	int		i;
	size_t	arglen;

	va_start(ap, str);
	i = 0;
	arglen = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%')
			arglen += ft_process_char((char *)&str[++i], ap);
		else
			arglen += ft_print_char(str[i]);
		i++;
	}
	va_end(ap);
	return ((int)arglen);
}
