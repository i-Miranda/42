/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 22:25:46 by ivmirand          #+#    #+#             */
/*   Updated: 2025/04/17 12:51:10 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	loading_fdf(int tick)
{
	if (tick % 4 == 0)
		ft_printf("Loading            \r");
	else if (tick % 4 == 1)
		ft_printf("Loading.           \r");
	else if (tick % 4 == 2)
		ft_printf("Loading..          \r");
	else if (tick % 4 == 3)
		ft_printf("Loading...         \r");
}
