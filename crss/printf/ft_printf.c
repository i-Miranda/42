/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 14:02:34 by ivmirand          #+#    #+#             */
/*   Updated: 2024/11/10 14:02:38 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	ft_process_char(char arg, va_list ap)
{
	int result;

	result = -1;
	if (arg == 'c')
		result = ft_print_char(*ap);
	else if (arg == 's')
		result = ft_print_string(*ap);
	else if (arg == 'p')
		result = ft_print_address(*ap);
	else if (arg == 'd' || arg == 'i')
		result = ft_print_int(*ap);
	else if (arg == 'x')
		result = ft_print_hex(*ap, FALSE);
	else if (arg == 'X')
		result = ft_print_hex(*ap, TRUE);
	return (result);
}
int	ft_printf(char const *str, ...)
{
	size_t	i;
	size_t	j;
	va_list	ap;
	char	*substr;

	va_start(ap, str);
	va_copy(ap2, ap);
	i = 0;	
	while (str[i] != '\0')
	{
		va_arg(ap, char const *);
		if (str[i] == '%')
		{
			j = 0;
			while (str[i + j] == '%')
				j++;
			ft_process_char(str[i + j]);			
		}
		else
		{
			j = 0;
			while (str[i + j] != '%')
				j++;
			substr = ft_substr(str, i, j);
			ft_print_string(substr);
		}
		i += j;
	}
	va_end(ap);
	return (ft_strlen(str));
}
