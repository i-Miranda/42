/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_text.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 14:00:35 by ivmirand          #+#    #+#             */
/*   Updated: 2024/11/16 02:34:05 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

size_t	ft_print_char(int c)
{
	ft_putchar_fd(c, 1);
	return (1);
}

size_t	ft_print_string(char *str)
{
	size_t result;

	if (str == NULL)
	{
		ft_putstr_fd("(null)", 1);
		result = 6;
	}
	else if (str[0] == '\0')
	{
		ft_putstr_fd("", 1);
		result = 0;
	}
	else
	{
		ft_putstr_fd(str, 1);
		result = ft_strlen(str);
	}
	return (result);
}

size_t	ft_print_address(void *addr, int is_big)
{
	int				j;
	unsigned char	*uchar_addr;
	char			*output;
	size_t			result;

	j = 7;
	output = ft_calloc((j + 1), sizeof(char));
	uchar_addr = (unsigned char *)&addr;
	while (j >= 0)
	{
		if (uchar_addr[j] != '\0')
			ft_print_hex(uchar_addr[j], is_big);
		else
			write(1, "00", 2);
		j--;
	}
	result = ft_print_string(output);
	free(output);
	return (result);
}

size_t	ft_print_percent(void)
{
	ft_putchar_fd('%', 1);
	return (1);
}
