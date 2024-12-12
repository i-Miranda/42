/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 14:02:34 by ivmirand          #+#    #+#             */
/*   Updated: 2024/12/12 11:21:55 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/ft_printf_bonus.h"

static size_t	ft_process_char(char *c, va_list ap, char *flags)
{
	size_t	result;

	result = 0;
	if (*c == 'c')
		result = ft_print_char(va_arg(ap, int));
	else if (*c == 's')
		result = ft_print_string(va_arg(ap, char *), flags);
	else if (*c == 'p')
		result = ft_print_address(va_arg(ap, void *), flags);
	else if (*c == 'd' || *c == 'i')
		result = ft_print_int(va_arg(ap, int), flags);
	else if (*c == 'u')
		result = ft_print_uint(va_arg(ap, unsigned int), flags);
	else if (*c == 'x')
		result = ft_print_hex(va_arg(ap, void *), FALSE, flags, 3);
	else if (*c == 'X')
		result = ft_print_hex(va_arg(ap, void *), TRUE, flags, 3);
	else if (*c == '%')
		result = ft_print_char('%');
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
		flags[i] = c[i];
	return (flags);
}

static char	*ft_remove_flags(char *c)
{
	char	*flags;
	size_t	len;
	size_t	i;
	size_t	j;
	int		minus_zero;
	int		plus_space;

	len = ft_strlen(c);
	minus_zero = FALSE;
	plus_space = FALSE;
	i = 0;
	j = 0;
	if (ft_strchr(c, '-') && ft_strchr(c, '0'))
		minus_zero = TRUE;
	if (ft_strchr(c, '+') && ft_strchr(c, ' '))
		plus_space = TRUE;
	flags = ft_calloc(len, sizeof(char));
	while (i < len)
	{
		if (minus_zero == TRUE && c[i + j] == '0')
			j++;
		if (plus_space == TRUE && c[i + j] == ' ')
			j++;
		flags[i] = c[i + j];
		i++;
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
