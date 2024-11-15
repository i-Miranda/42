/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 14:02:34 by ivmirand          #+#    #+#             */
/*   Updated: 2024/11/16 00:57:01 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

static char	*ft_check_padding(char *str)
{
	char	*padding;
	padding = ft_strdup("");
	if (*str >= '0' && *str <= '9')
	{
		if (*str == '0')
		{
			// ZERO PAD VALUE ON LEFT
		}
		//else
		// fld_bnds = *arg - '0';
	}
	if (*str == '-')
	{
		// PADDING ON RIGHT INSTEAD OF LEFT
		// pad with spaces ' '
		// overrides '0' flag
	}
	else if (*str == '.')
	{
		// print how many decimals?
	}
	return (NULL);
}

static char	*ft_check_flags(char *str)
{
	char	*flags;

	if (*str == '#')
	{
		// if hex being printed (x or X)
		// print 0x for !is_big 0X for is_big
	}
	else if (*str == ' ')
	{
		// (a  space)  A blank should be left before a positive
		// number (or empty string) produced by a signed conversion.
	}
	else if (*str == '+')
	{
		// always sign a signed conversion (+ or -)
		// overrides ' ' flag
	}
	return (NULL);
}

static size_t	ft_process_char(char c, va_list ap, char *flags, size_t result)
{
	if (c == 'c')
		result = ft_print_char(va_arg(ap, int), flags);
	else if (c == 's')
		result = ft_print_string(va_arg(ap, char *));
	else if (c == 'p')
		result = ft_print_address(va_arg(ap, void *), FALSE, flags);
	else if (c == 'd' || c == 'i')
		result = ft_print_int(va_arg(ap, int), flags);
	else if (c == 'u')
		result = ft_print_uint(va_arg(ap, int), flags);
	else if (c == 'x')
		result = ft_print_hex(va_arg(ap, unsigned int), FALSE, flags);
	else if (c == 'X')
		result = ft_print_hex(va_arg(ap, unsigned int), TRUE, flags);
	else if (c == '%')
		result = ft_print_percent();
	return (result);
}

int	ft_printf(char const *str, ...)
{
	va_list	ap;
	size_t	i;
	size_t	arglen;
	char	*flags;

	va_start(ap, str);
	i = 0;
	arglen = 0;
	while (str[i] != '\0')
	{
		flags = ft_strdup("");
		if (str[i] == '%')
		{
			flags = ft_strjoin((char const *)flags, 
					(char const *)ft_check_flags((char *)&str[++i]));
			i += ft_strlen(flags);
			flags = ft_strjoin((char const *)flags,
					(char const *)ft_check_padding((char *)&str[++i]));
			i += ft_strlen(flags);
			if (!flags || flags[0] == '\0')
				arglen += ft_process_char(str[++i], ap, NULL, 0);
			else
				arglen += ft_process_char(str[++i], ap, flags, 0);
		}
		else
			arglen += ft_print_char(str[i], NULL);
		i++;
		free(flags);
	}
	va_end(ap);
	return ((int)arglen);
}
