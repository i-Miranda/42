/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 14:02:07 by ivmirand          #+#    #+#             */
/*   Updated: 2024/11/16 00:38:12 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"
#include <stdio.h>

int	main(int argc, char *argv[])
{
	int pfreturn;

	pfreturn = printf("rl_printf: %c ", '0');
	printf("%d\n", pfreturn);
	pfreturn = ft_printf("ft_printf: %c ", '0');
	ft_printf("%d", pfreturn);
	printf("\n\n");

	pfreturn = printf("rl_printf: %c ", '\0');
	printf("%d\n", pfreturn);
	pfreturn = ft_printf("ft_printf: %c ", '\0');
	ft_printf("%d", pfreturn);
	printf("\n\n");

	pfreturn = printf("rl_printf: %s %% ", argv[1]);
	printf("%d\n", pfreturn);
	pfreturn = ft_printf("ft_printf: %s %% ", argv[1]);
	ft_printf("%d", pfreturn);
	printf("\n\n");

	pfreturn = printf("rl_printf: %");
	printf("%d\n", pfreturn);
	pfreturn = ft_printf("ft_printf: %");
	ft_printf("%d", pfreturn);
	printf("\n\n");

	pfreturn = printf("rl_printf: %s ", "");
	printf("%d\n", pfreturn);
	pfreturn = ft_printf("ft_printf: %s ", "");
	ft_printf("%d", pfreturn);
	printf("\n\n");

	pfreturn = printf("rl_printf: %s ", (char *)NULL);
	printf("%d\n", pfreturn);
	pfreturn = ft_printf("ft_printf: %s ", (char *)NULL);
	ft_printf("%d", pfreturn);
	printf("\n\n");

	pfreturn = printf("rl_printf: %p ", &pfreturn);
	printf("%d\n", pfreturn);
	pfreturn = ft_printf("ft_printf: %p ", &pfreturn); 
	ft_printf("%d", pfreturn);
	printf("\n\n");

	pfreturn = -14;
	pfreturn = printf("rl_printf: %0d %u ", pfreturn, pfreturn);
	printf("%d\n", pfreturn);
	pfreturn = -14;
	pfreturn = ft_printf("ft_printf: %0d %u ", pfreturn, pfreturn); 
	ft_printf("%d", pfreturn);
	printf("\n\n");

	return (0);
}
