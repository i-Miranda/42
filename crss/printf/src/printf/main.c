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

#include "../../includes/ft_printf.h"
#include <stdio.h>

int	main(int argc, char *argv[])
{
	int pfreturn;

	pfreturn = printf("printf: %s %% ", argv[1]);
	printf("%d\n", pfreturn);
	pfreturn = ft_printf("ft_printf: %s %% ", argv[1]);
	ft_printf("%d", pfreturn);
	printf("\n\n");

	pfreturn = printf("printf: %s ", "");
	printf("%d\n", pfreturn);
	pfreturn = ft_printf("ft_printf: %s ", "");
	ft_printf("%d", pfreturn);
	printf("\n\n");

	pfreturn = printf("printf: %c ", '0');
	printf("%d\n", pfreturn);
	pfreturn = ft_printf("ft_printf: %c ", '0');
	ft_printf("%d", pfreturn);
	printf("\n\n");

	return (0);
}
