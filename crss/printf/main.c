/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 14:02:07 by ivmirand          #+#    #+#             */
/*   Updated: 2024/11/13 15:55:54 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

int	main(int argc, char *argv[])
{
	int	nbr;

	nbr = ft_printf("ft_printf: %ls\n", argv[1]);
	ft_putnbr_fd(nbr, 1);
	printf("original printf: %s\n", argv[1]);
	return (0);
}
