/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 14:02:34 by ivmirand          #+#    #+#             */
/*   Updated: 2024/11/20 13:34:48 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

static size_t	ft_process_char(char *c, va_list ap, char *flags, size_t result)
{
	if (*c == 'c')
		result = ft_print_char(va_arg(ap, int));
	else if (*c == 's')
		result = ft_print_string(va_arg(ap, char *));
	else if (*c == 'p')
		result = ft_print_address(va_arg(ap, void *), flags);
	else if (*c == 'd' || *c == 'i')
		result = ft_print_int(va_arg(ap, int));
	else if (*c == 'u')
		result = ft_print_uint(va_arg(ap, unsigned int));
	else if (*c == 'x')
		result = ft_print_hex(va_arg(ap, unsigned long long), FALSE, flags);
	else if (*c == 'X')
		result = ft_print_hex(va_arg(ap, unsigned long long), TRUE, flags);
	else if (*c == '%')
		result = ft_print_percent();
	if (flags)
		free(flags);
	return (result);
}

static char	*ft_find_flags(char *c)
{
	char	*flags;
	int		i;

	flags = NULL;
	i = 0;
	while (c[i] == '-' || c[i] == '0' || c[i] == '.' || c[i] == '#'
		|| c[i] == ' ' || c[i] == '+')
		i++;
	if (i > 0)
	{
		flags = ft_calloc(i + 1, sizeof(char));
		if (flags)
			while (i >= 0)
				flags[i] = c[i];
	}
	return (flags);
}

static char	*ft_remove_flags(char *c)
{
	char	*flags;
	size_t	len;
	size_t	i;

	len = ft_strlen(c);
	if (ft_strchr(c, '-') && ft_strchr(c, ' '))
		len--;
	if (ft_strchr(c, '+') && ft_strchr(c, '0'))
		len--;
	flags = ft_calloc(len + 1, sizeof(char));
	i = len;
	while (len >= 0)
	{
		if ((ft_strchr(c, '-') && c[len] != ' ')
			|| (ft_strchr(c, '+') && c[len] != '0'))
			c[len] = flags[i--];
		len--;
	}
	free(c);
	return (flags);
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
		if (str[i] == '%')
		{
			flags = ft_find_flags((char *)&str[++i]);
			if (flags != NULL)
			{
				i += ft_strlen(flags);
				flags = ft_remove_flags(flags);
			}
			arglen += ft_process_char((char *)&str[i], ap, flags, 0);
		}
		else
			arglen += ft_print_char(str[i]);
		i++;
	}
	va_end(ap);
	return ((int)arglen);
}
