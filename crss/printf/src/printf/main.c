/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 14:02:07 by ivmirand          #+#    #+#             */
/*   Updated: 2024/12/11 01:59:27 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"
#include <stdio.h>
#include <limits.h>

static void normal_tests(int pfreturn, char *argv)
{
	pfreturn = printf("rl_printf c: %c ", '0');
	printf("%d\n", pfreturn);
	pfreturn = ft_printf("ft_printf c: %c ", '0');
	ft_printf("%d\n\n", pfreturn);

	pfreturn = printf("rl_printf c: %c ", '\0');
	printf("%d\n", pfreturn); 
	pfreturn = ft_printf("ft_printf c: %c ", '\0');
	ft_printf("%d\n\n", pfreturn);

	pfreturn = printf("rl_printf s and %%: %s %% ", argv);
	printf("%d\n", pfreturn);
	pfreturn = ft_printf("ft_printf s and %%: %s %% ", argv);
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

	pfreturn = printf("rl_printf p -> -32000 casted to void pointer: %p ", (void *)-32000);
	printf("%d\n", pfreturn);
	pfreturn = ft_printf("ft_printf p -> -32000 casted to void pointer: %p ", (void *)-32000); 
	ft_printf("%d\n\n", pfreturn);

	pfreturn = printf("rl_printf p: %p ", NULL);
	printf("%d\n", pfreturn);
	pfreturn = ft_printf("ft_printf p: %p ", NULL); 
	ft_printf("%d\n\n", pfreturn);

	pfreturn = printf("rl_printf p and p: %p %p ", INT_MAX, INT_MIN);
	printf("%d\n", pfreturn);
	pfreturn = ft_printf("ft_printf p and p: %p %p ", INT_MAX, INT_MIN); 
	ft_printf("%d\n\n", pfreturn);

	pfreturn = printf("rl_printf p and p: %p %p ", LONG_MAX, LONG_MIN);
	printf("%d\n", pfreturn);
	pfreturn = ft_printf("ft_printf p and p: %p %p ", LONG_MAX, LONG_MIN); 
	ft_printf("%d\n\n", pfreturn);

	pfreturn = printf("rl_printf d, i and u: %d %i %u ", -14, -14, -14);
	printf("%d\n", pfreturn);
	pfreturn = ft_printf("ft_printf d, i and u: %d %i %u ", -14, -14, -14); 
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

	pfreturn = printf("rl_printf x: %x ", 5873);
	printf("%d\n", pfreturn);
	pfreturn = ft_printf("ft_printf x: %x ", 5873); 
	ft_printf("%d\n\n", pfreturn);

	pfreturn = printf("rl_printf X: %X ", 5873);
	printf("%d\n", pfreturn);
	pfreturn = ft_printf("ft_printf X: %X ", 5873); 
	ft_printf("%d\n\n", pfreturn);
}

static void bonus_tests(int pfreturn)
{
	pfreturn = printf("rl_printf c: %-10c ", 'X');
	printf("%d\n", pfreturn);
	pfreturn = ft_printf("ft_printf c: %-10c ", 'X');
	ft_printf("%d\n\n", pfreturn);

	pfreturn = printf("rl_printf 5s: %5s ", "hola");
	printf("%d\n", pfreturn);
	pfreturn = ft_printf("ft_printf 5s: %5s ", "hola");
	ft_printf("%d\n\n", pfreturn);

	pfreturn = -14;
	pfreturn = printf("rl_printf .5d, .5i and .5u: %.5d %.5i %.50u ", pfreturn, pfreturn, pfreturn);
	printf("%d\n", pfreturn);
	pfreturn = -14;
	pfreturn = ft_printf("ft_printf .5d, .5i and .5u: %.5d %.5i %.50u ", pfreturn, pfreturn, pfreturn); 
	ft_printf("%d\n\n", pfreturn);

	pfreturn = 14;
	pfreturn = printf("rl_printf +d and +i: %+d %+i ", pfreturn, pfreturn);
	printf("%d\n", pfreturn);
	pfreturn = 14;
	pfreturn = ft_printf("ft_printf +d and +i: %+d %+i ", pfreturn, pfreturn); 
	ft_printf("%d\n\n", pfreturn);

	pfreturn = -14;
	pfreturn = printf("rl_printf +d and +i: %+d %+i ", pfreturn, pfreturn);
	printf("%d\n", pfreturn);
	pfreturn = -14;
	pfreturn = ft_printf("ft_printf +d and +i: %+d %+i ", pfreturn, pfreturn); 
	ft_printf("%d\n\n", pfreturn);

	pfreturn = 14;
	pfreturn = printf("rl_printf ' 'd and ' 'i: % d % i ", pfreturn, pfreturn);
	printf("%d\n", pfreturn);
	pfreturn = 14;
	pfreturn = ft_printf("ft_printf ' 'd and ' 'i: % d % i ", pfreturn, pfreturn); 
	ft_printf("%d\n\n", pfreturn);

	pfreturn = 14;
	pfreturn = printf("rl_printf +' 'd and +' 'i: %+ d %+ i ", pfreturn, pfreturn);
	printf("%d\n", pfreturn);
	pfreturn = 14;
	pfreturn = ft_printf("ft_printf +' 'd and +' 'i: %+ d %+ i ", pfreturn, pfreturn); 
	ft_printf("%d\n\n", pfreturn);

	pfreturn = 14;
	pfreturn = printf("rl_printf 5d 5i and 5u: %5d %5i %5u ", pfreturn, pfreturn, pfreturn);
	printf("%d\n", pfreturn);
	pfreturn = 14;
	pfreturn = ft_printf("ft_printf 5d 5i and 5u: %5d %5i %5u ", pfreturn, pfreturn, pfreturn); 
	ft_printf("%d\n\n", pfreturn);

	pfreturn = 14;
	pfreturn = printf("rl_printf 05d 05i and 05u: %05d %05i %05u ", pfreturn, pfreturn, pfreturn);
	printf("%d\n", pfreturn);
	pfreturn = 14;
	pfreturn = ft_printf("ft_printf 05d 05i and 05u: %05d %05i %05u ", pfreturn, pfreturn, pfreturn); 
	ft_printf("%d\n\n", pfreturn);

	pfreturn = 14;
	pfreturn = printf("rl_printf -05d -05i and -05u: %-05d %-05i %-05u ", pfreturn, pfreturn, pfreturn);
	printf("%d\n", pfreturn);
	pfreturn = 14;
	pfreturn = ft_printf("ft_printf -05d -05i and -05u: %-05d %-05i %-05u ", pfreturn, pfreturn, pfreturn); 
	ft_printf("%d\n\n", pfreturn);

	pfreturn = 14;
	pfreturn = printf("rl_printf 0-5d 0-5i and 0-5u: %0-5d %0-5i %0-5u ", pfreturn, pfreturn, pfreturn);
	printf("%d\n", pfreturn);
	pfreturn = 14;
	pfreturn = ft_printf("ft_printf 0-5d 0-5i and 0-5u: %0-5d %0-5i %0-5u ", pfreturn, pfreturn, pfreturn); 
	ft_printf("%d\n\n", pfreturn);

	pfreturn = 14;
	pfreturn = printf("rl_printf -10d -10i and -10u: %-10d %-10i %-10u ", pfreturn, pfreturn, pfreturn);
	printf("%d\n", pfreturn);
	pfreturn = 14;
	pfreturn = ft_printf("ft_printf -10d -10i and -10u: %-10d %-10i %-10u ", pfreturn, pfreturn, pfreturn); 
	ft_printf("%d\n\n", pfreturn);

	pfreturn = printf("rl_printf x and #x: %x %#x ", 127, 127);
	printf("%d\n", pfreturn);
	pfreturn = ft_printf("ft_printf x and #x: %x %#x ", 127, 127); 
	ft_printf("%d\n\n", pfreturn);

	pfreturn = printf("rl_printf X and #X: %X %#X ", 127, 127);
	printf("%d\n", pfreturn);
	pfreturn = ft_printf("ft_printf X and #X: %X %#X ", 127, 127); 
	ft_printf("%d\n\n", pfreturn);

}

int	main(int argc, char *argv[])
{
	int pfreturn;

	normal_tests(pfreturn, argv[1]);

	//bonus_tests(pfreturn);
	
	return (0);
}
