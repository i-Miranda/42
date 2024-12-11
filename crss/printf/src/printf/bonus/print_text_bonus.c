/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_text_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 14:00:35 by ivmirand          #+#    #+#             */
/*   Updated: 2024/12/11 03:09:37 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/ft_printf_bonus.h"

size_t	ft_print_char(int c)
{
	ft_putchar_fd(c, 1);
	return (1);
}

size_t	ft_print_string(char *str, char *flags)
{
	char	*atoi_flags;
	int		charcount;
	int		i;
	size_t	result;

	result = 0;
	charcount = -1;
	i = 0;
	if (flags && ft_strchr(flags, '.'))
	{
		atoi_flags = ft_strchr(flags, '.');	
		charcount = ft_atoi(++atoi_flags);
	}
	if (str == NULL)
	{
		ft_putstr_fd("(null)", 1);
		result += 6;
	}
	else if (charcount > 0)
	{
		while (i < charcount)
		{
			if (str[i])
				result += ft_print_char(str[i]);
			else
				result += ft_print_char(' ');
			i++;
		}
	}
	else
	{
		ft_putstr_fd(str, 1);
		result += ft_strlen(str);
	}
	return (result);
}

size_t	ft_print_address(void *addr, char *flags)
{
	size_t	result;

	if (addr == NULL)
		return (ft_print_string(NIL, NULL));
	result = 0;
	result += ft_print_string("0x", NULL);
	result += ft_print_hex(addr, FALSE, flags, 7);
	return (result);
}

size_t	ft_print_percent(void)
{
	ft_putchar_fd('%', 1);
	return (1);
}
