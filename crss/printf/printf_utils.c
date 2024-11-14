/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 18:33:09 by ivmirand          #+#    #+#             */
/*   Updated: 2024/11/12 21:58:08 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

size_t	ft_check_flags(int c)
{
	size_t	result;
	//size_t	fld_bnds;
	
	result = 0;
	//fld_bnds = 0;
	if (c >= '0' && c <= '9')
	{
		if (c == '0')
		{
			// ZERO PAD VALUE ON LEFT
		}
		//else
		//	fld_bnds = *arg - '0';
	}
	if (c == '-')
	{
		// PADDING ON RIGHT INSTEAD OF LEFT
		// pad with spaces ' '
		// overrides '0' flag
	}
	else if (c == '.')
	{
		// print how many decimals?
	}
	if (c == '#')
	{
		// if hex being printed (x or X)
		// print 0x for !is_big 0X for is_big
	}
	else if (c == ' ')
	{
		// (a  space)  A blank should be left before a positive
		// number (or empty string) produced by a signed conversion.
	}
	else if (c == '+')
	{
		// always sign a signed conversion (+ or -)
		// overrides ' ' flag' ' flag
	}
	return (result);
}
