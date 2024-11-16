/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 14:02:34 by ivmirand          #+#    #+#             */
/*   Updated: 2024/11/16 02:36:24 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"


//static char	*ft_check_padding(char *str)
//{
//	char	*padding;
//	int		i;
//	padding = ft_strdup("");
//	i = 0;
//	while (str[i] == '-' || str[i] == '0' || str[i] == '.')
//	{
//		if (*str == '-')
//		{
//			// PADDING ON RIGHT INSTEAD OF LEFT
//			// pad with spaces ' '
//			// overrides '0' flag
//			ft_strjoin((char const *)padding, "-"); 
//		}
//		else if (*str == '0')
//		{
//			// ZERO PAD VALUE ON LEFT
//			ft_strjoin((char const *)padding, "0"); 
//		}
//		else if (*str == '.')
//		{
//			// print how many decimals?
//			ft_strjoin((char const *)padding, "."); 
//		}
//		i++;
//	}
//	return (NULL);
//}
//
//static char	*ft_check_flags(char *str)
//{
//	char	*flags;
//	int	i;
//
//	flags = NULL;
//	i = 0;
//	while (str[i] == '#' || str[i] == ' ' || str[i] == '+')
//	if (*str == '#')
//	{
//		// if hex being printed (x or X)
//		// print 0x for !is_big 0X for is_big
//		ft_strjoin((char const *)flags, "#"); 
//	}
//	else if (*str == ' ')
//	{
//		// (a  space)  A blank should be left before a positive
//		// number (or empty string) produced by a signed conversion.
//		ft_strjoin((char const *)flags, " "); 
//	}
//	else if (*str == '+')
//	{
//		// always sign a signed conversion (+ or -)
//		// overrides ' ' flag
//		ft_strjoin((char const *)flags, "+"); 
//	}
//	return (flags);
//}

static size_t	ft_process_char(char *c, va_list ap, char *flags, size_t result)
{
	if (*c == 'c')
		result = ft_print_char(va_arg(ap, int));
	else if (*c == 's')
		result = ft_print_string(va_arg(ap, char *));
	else if (*c == 'p')
		result = ft_print_address(va_arg(ap, void *), FALSE);
	else if (*c == 'd' || *c == 'i')
		result = ft_print_int(va_arg(ap, int));
	else if (*c == 'u')
		result = ft_print_uint(va_arg(ap, int));
	else if (*c == 'x')
		result = ft_print_hex(va_arg(ap, unsigned int), FALSE);
	else if (*c == 'X')
		result = ft_print_hex(va_arg(ap, unsigned int), TRUE);
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
	while (c[i] == '-' || c[i] == '0' || c[i] == '.' || c[i] == '#' ||
			c[i] == ' ' || c[i] == '+')
		i++;
	if (i > 0)
	{
		flags = ft_calloc(i + 1, sizeof(char));
		while (i >= 0)
			flags[i] = c[i];
	}
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
				i += ft_strlen(flags);
			arglen += ft_process_char((char *)&str[++i], ap, flags, 0);
		}
		else
			arglen += ft_print_char(str[i]);
		i++;
	}
	va_end(ap);
	return ((int)arglen);
}
