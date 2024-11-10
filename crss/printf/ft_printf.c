/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 14:02:34 by ivmirand          #+#    #+#             */
/*   Updated: 2024/11/10 14:02:38 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(char const *str, ...)
{
	int		arg_i;
	int		pct_i;
	size_t	len;
	size_t	i;
	va_list	arglist;

	va_start(arglist, str);
	arg_i = 0;
	while (arglist)
	{
		va_arg(arglist, char const *);
		arg_i++;
	}
	va_end(arglist);
	return (ft_strlen(str));
}
