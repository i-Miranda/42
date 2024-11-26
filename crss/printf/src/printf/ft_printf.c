/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 14:02:34 by ivmirand          #+#    #+#             */
/*   Updated: 2024/11/20 20:16:55 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

static size_t	ft_process_char(char *c, va_list ap, char *flags)
{
	size_t result;

	result = 0;
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
		result = ft_print_hex(va_arg(ap, void *), FALSE, flags, 3);
	else if (*c == 'X')
		result = ft_print_hex(va_arg(ap, void *), TRUE, flags, 3);
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
	while (c[i] != 'c' && c[i] != 's' && c[i] != 'p' && c[i] != 'd'
		&& c[i] != 'i' && c[i] != 'u' && c[i] != 'x' && c[i] != 'X'
		&& c[i] != '%' && c[i] != '\0')
		i++;
	if (i <= 0)
		return (flags);
	flags = ft_calloc(i + 1, sizeof(char));
	if (!flags)
		return (flags);
	while (i-- > 0)
	{
		flags[i] = c[i];
	}
	return (flags);
}

static char	*ft_remove_flags(char *c)
{
	char	*flags;
	size_t	len;
	size_t	new_len;

	len = ft_strlen(c);
	new_len = len;
	if (ft_strchr(c, '-') && ft_strchr(c, '0'))
		new_len--;
	if (ft_strchr(c, '+') && ft_strchr(c, ' '))
		new_len--;
	if (new_len == len)
		return (c);
	flags = ft_calloc(len + 1, sizeof(char));
	while (len >= 0)
	{
		if (c[len] != ' ' || c[len] != '0')
			c[len] = flags[new_len--];
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
			arglen += ft_process_char((char *)&str[i++], ap, flags);
		}
		else
			arglen += ft_print_char(str[i++]);
	}
	va_end(ap);
	return ((int)arglen);
}
