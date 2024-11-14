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

#include "ft_printf.h"
#include <stdio.h>

int	main(int argc, char *argv[])
{
	int pfreturn;

	pfreturn = printf("printf: %s %% %c", argv[1], argv[1][2]);
	printf("%d", pfreturn);
	ft_printf("ft_printf: %s %% %c %d", argv[1], argv[1][2], pfreturn);
	return (0);
}
