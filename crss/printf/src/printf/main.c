/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 14:02:07 by ivmirand          #+#    #+#             */
/*   Updated: 2024/11/16 18:27:00 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"
#include <stdio.h>

int	main(int argc, char *argv[])
{
	int pfreturn;

	pfreturn = printf("rl_printf c: %c ", '0');
	printf("%d\n", pfreturn);
	pfreturn = ft_printf("ft_printf c: %c ", '0');
	ft_printf("%d\n\n", pfreturn);

	pfreturn = printf("rl_printf c: %c ", '\0');
	printf("%d\n", pfreturn);
	pfreturn = ft_printf("ft_printf c: %c ", '\0');
	ft_printf("%d\n\n", pfreturn);

	pfreturn = printf("rl_printf s and %%: %s %% ", argv[1]);
	printf("%d\n", pfreturn);
	pfreturn = ft_printf("ft_printf s and %%: %s %% ", argv[1]);
	ft_printf("%d\n\n", pfreturn);

	pfreturn = printf("rl_printf s: %s ", "");
	printf("%d\n", pfreturn);
	pfreturn = ft_printf("ft_printf s: %s ", "");
	ft_printf("%d\n\n", pfreturn);

	pfreturn = printf("rl_printf s: %s ", (char *)NULL);
	printf("%d\n", pfreturn);
	pfreturn = ft_printf("ft_printf s: %s ", (char *)NULL);
	ft_printf("%d\n\n", pfreturn);

	pfreturn = printf("rl_printf p: %p ", &pfreturn);
	printf("%d\n", pfreturn);
	pfreturn = ft_printf("ft_printf p: %p ", &pfreturn); 
	ft_printf("%d\n\n", pfreturn);

	pfreturn = printf("rl_printf p: %p ", NULL);
	printf("%d\n", pfreturn);
	pfreturn = ft_printf("ft_printf p: %p ", NULL); 
	ft_printf("%d\n\n", pfreturn);

	pfreturn = printf("rl_printf p: %p ", &pfreturn);
	printf("%d\n", pfreturn);
	pfreturn = ft_printf("ft_printf p: %p ", &pfreturn); 
	ft_printf("%d\n\n", pfreturn);

	pfreturn = -14;
	pfreturn = printf("rl_printf d and u: %d %u ", pfreturn, pfreturn);
	printf("%d\n", pfreturn);
	pfreturn = -14;
	pfreturn = ft_printf("ft_printf d and u: %d %u ", pfreturn, pfreturn); 
	ft_printf("%d\n\n", pfreturn);

	pfreturn = printf("rl_printf x: %x ", 15);
	printf("%d\n", pfreturn);
	pfreturn = ft_printf("ft_printf x: %x ", 15); 
	ft_printf("%d\n\n", pfreturn);

	pfreturn = printf("rl_printf x: %x ", 16);
	printf("%d\n", pfreturn);
	pfreturn = ft_printf("ft_printf x: %x ", 16); 
	ft_printf("%d\n\n", pfreturn);

	pfreturn = printf("rl_printf x and #x: %x %#x ", 127, 127);
	printf("%d\n", pfreturn);
	pfreturn = ft_printf("ft_printf x and #x: %x %x ", 127, 127); 
	ft_printf("%d\n\n", pfreturn);

	pfreturn = printf("rl_printf X and #X: %X %#X ", 127, 127);
	printf("%d\n", pfreturn);
	pfreturn = ft_printf("ft_printf X and #X: %X %X ", 127, 127); 
	ft_printf("%d\n\n", pfreturn);

	return (0);
}
