/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 14:02:34 by ivmirand          #+#    #+#             */
/*   Updated: 2024/12/12 20:56:39 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/ft_printf_bonus.h"

static int	ft_process_char(char *c, va_list ap, char *flags)
{
	int	result;

	result = 0;
	if (*c == 'c')
		result = ft_print_char_bonus(va_arg(ap, int), flags);
	else if (*c == 's')
		result = ft_print_string_bonus(va_arg(ap, char *), flags);
	else if (*c == 'p')
		result = ft_print_address(va_arg(ap, void *));
	else if (*c == 'd' || *c == 'i')
		result = ft_print_int_bonus(va_arg(ap, int), flags);
	else if (*c == 'u')
		result = ft_print_uint_bonus(va_arg(ap, unsigned int), flags);
	else if (*c == 'x')
		result = ft_print_hex_bonus(va_arg(ap, void *), FALSE, 3, flags);
	else if (*c == 'X')
		result = ft_print_hex_bonus(va_arg(ap, void *), TRUE, 3, flags);
	else if (*c == '%')
		result = ft_print_char('%');
	else
		result = -1;
	if (flags)
		free(flags);
	return (result);
}

int	ft_printf(char const *str, ...)
{
	va_list	ap;
	int		pcnt_check;
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
			i += ft_remove_flags((char *)&str[i], flags);
			pcnt_check = ft_process_char((char *)&str[i++], ap, flags);
			if (pcnt_check == -1)
				return (-1);
			arglen += pcnt_check;
		}
		else
			arglen += ft_print_char(str[i++]);
	}
	va_end(ap);
	return ((int)arglen);
}
