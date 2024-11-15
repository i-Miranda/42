/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 14:02:34 by ivmirand          #+#    #+#             */
/*   Updated: 2024/11/13 17:36:05 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

static size_t	ft_process_char(char c, va_list ap, size_t result)
{
	if (c == 'c')
		result = ft_print_char(va_arg(ap, int));
	else if (c == 's')
		result = ft_print_string(va_arg(ap, char *));
	else if (c == 'p')
		result = ft_print_address(va_arg(ap, void *), FALSE);
	else if (c == 'd' || c == 'i')
		result = ft_print_int(va_arg(ap, int));
	else if (c == 'u')
		result = ft_print_udec(va_arg(ap, double));
	else if (c == 'x')
		result = ft_print_hex(va_arg(ap, unsigned int), FALSE);
	else if (c == 'X')
		result = ft_print_hex(va_arg(ap, unsigned int), TRUE);
	else if (c == '%')
		result = ft_print_percent();
	else
	{
		result = ft_check_flags(va_arg(ap, int));
		if (result != 0)
			result = ft_process_char(c, ap, result);
	}
	return (result);
}

int	ft_printf(char const *str, ...)
{
	va_list	ap;
	size_t	i;
	size_t	j;
	size_t	arglen;
	char	*substr;

	va_start(ap, str);
	i = 0;
	arglen = 0;
	while (str[i] != '\0')
	{
		j = 0;
		if (str[i] == '%')
		{
			arglen += ft_process_char(str[++i], ap, 0);
			j++;
		}
		else
		{
			while (str[i + j] != '%')
				j++;
			substr = ft_substr(str, i, j);
			arglen += ft_print_string(substr);
			free(substr);
		}
		i += j;
	}
	va_end(ap);
	return ((int)arglen);
}
