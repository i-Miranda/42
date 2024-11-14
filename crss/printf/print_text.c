/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_text.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 14:00:35 by ivmirand          #+#    #+#             */
/*   Updated: 2024/11/13 16:22:39 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

size_t	ft_print_char(int c)
{
	ft_putchar_fd(c, 1);
	return (1);
}

size_t	ft_print_string(char *str)
{
	ft_putstr_fd(str, 1);
	return (ft_strlen(str));
}

size_t	ft_print_address(void *addr, int is_big)
{
	int				j;
	unsigned char	*uchar_addr;
	char			*output;

	j = 7;
	output = malloc((j + 1) * sizeof(char));
	uchar_addr = (unsigned char *)&addr;
	while (j >= 0)
	{
		if (uchar_addr[j] != '\0')
			ft_print_hex(uchar_addr[j], is_big);
		else
			write(1, "00", 2);
		j--;
	}
	return (ft_print_string(output));
}

size_t	ft_print_percent(char *str)
{
	int	i;

	i = 0;
	while (str[i] == '%')
		i++;
	ft_putchar_fd('%', 1);
	return (1);
}
