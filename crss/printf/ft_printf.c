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

#include "libftprintf.h"

static size_t	ft_process_char(va_list ap)
{
	size_t	result;
	char	*arg;

	result = -1;
	arg = va_arg(ap, char *);
	if (*arg == 'c')
		result = ft_print_char(*arg);
	else if (*arg == 's')
		result = ft_print_string(arg);
	else if (*arg == 'p')
		result = ft_print_address((void *)arg, 0);
	else if (*arg == 'd' || *arg == 'i')
		result = ft_print_int(*arg);
	else if (*arg == 'u')
		result = ft_print_udec(*arg);
	else if (*arg == 'x')
		result = ft_print_hex((int)*arg, FALSE);
	else if (*arg == 'X')
		result = ft_print_hex((int)*arg, TRUE);
	else if (*arg == '%')
		result = ft_print_percent(arg);
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
			arglen += ft_process_char(ap);			
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
