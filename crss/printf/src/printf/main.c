/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 14:02:07 by ivmirand          #+#    #+#             */
/*   Updated: 2024/11/20 20:00:18 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"
#include <stdio.h>
#include <limits.h>

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

	pfreturn = printf("rl_printf p and p: %p %p ", INT_MAX, INT_MIN);
	printf("%d\n", pfreturn);
	pfreturn = ft_printf("ft_printf p and p: %p %p ", INT_MAX, INT_MIN); 
	ft_printf("%d\n\n", pfreturn);

	pfreturn = printf("rl_printf p and p: %p %p ", LONG_MAX, LONG_MIN);
	printf("%d\n", pfreturn);
	pfreturn = ft_printf("ft_printf p and p: %p %p ", LONG_MAX, LONG_MIN); 
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

	pfreturn = printf("rl_printf x: %x ", -1);
	printf("%d\n", pfreturn);
	pfreturn = ft_printf("ft_printf x: %x ", -1); 
	ft_printf("%d\n\n", pfreturn);

	pfreturn = printf("rl_printf x: %x ", -15);
	printf("%d\n", pfreturn);
	pfreturn = ft_printf("ft_printf x: %x ", -15); 
	ft_printf("%d\n\n", pfreturn);

	pfreturn = printf("rl_printf x: %x %x ", LONG_MIN, LONG_MAX);
	printf("%d\n", pfreturn);
	pfreturn = ft_printf("ft_printf x: %x %x ", LONG_MIN, LONG_MAX); 
	ft_printf("%d\n\n", pfreturn);

	pfreturn = printf("rl_printf x: %x %x ", INT_MIN, INT_MAX);
	printf("%d\n", pfreturn);
	pfreturn = ft_printf("ft_printf x: %x %x ", INT_MIN, INT_MAX); 
	ft_printf("%d\n\n", pfreturn);

	pfreturn = printf("rl_printf x: %x ", ULONG_MAX);
	printf("%d\n", pfreturn);
	pfreturn = ft_printf("ft_printf x: %x ", ULONG_MAX); 
	ft_printf("%d\n\n", pfreturn);

	pfreturn = printf("rl_printf x and #x: %x %#x ", 127, 127);
	printf("%d\n", pfreturn);
	pfreturn = ft_printf("ft_printf x and #x: %x %#x ", 127, 127); 
	ft_printf("%d\n\n", pfreturn);

	pfreturn = printf("rl_printf X and #X: %X %#X ", 127, 127);
	printf("%d\n", pfreturn);
	pfreturn = ft_printf("ft_printf X and #X: %X %#X ", 127, 127); 
	ft_printf("%d\n\n", pfreturn);

	pfreturn = printf("rl_printf x: %x ", 0);
	printf("%d\n", pfreturn);
	pfreturn = ft_printf("ft_printf x: %x ", 0); 
	ft_printf("%d\n\n", pfreturn);

	return (0);
}
