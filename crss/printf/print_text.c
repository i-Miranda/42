/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_text.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 14:00:35 by ivmirand          #+#    #+#             */
/*   Updated: 2024/11/10 14:20:30 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_print_char(char c)
{
	ft_putchar_fd(c, 1);
	return (1);
}

int	ft_print_string(char *str)
{
	ft_putstr_fd(str, 1);
	return (ft_strlen(str));
}

int	ft_print_address(void *addr, int isbig)
{
	int				j;
	unsigned char	*uchar_addr;
	char			*output;

	j = 7;
	uchar_addr = (unsigned char *)&addr;
	while (j >= 0)
	{
		if (uchar_addr[j] != '\0')
			ft_print_hex(uchar_addr[j], isbig);
		else
			write(1, "00", 2);
		j--;
	}
	return (ft_print_string(output));
}

int	ft_print_percent(void)
{
	ft_putchar_fd('%', 1);
	return (1);
}
