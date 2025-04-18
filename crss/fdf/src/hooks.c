/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 16:48:29 by ivmirand          #+#    #+#             */
/*   Updated: 2025/04/19 00:38:10 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	iterate_fdf(t_fdf **fdf, void (*f)(void *))
{
	t_coord	*zero_coord;
	t_coord	*next_y;
	t_coord	*next_x;

	if (fdf == NULL)
		return ;
	zero_coord = (*fdf)->zero_coord;
	while ((*fdf)->zero_coord)
	{
		next_y = (*fdf)->zero_coord->next_y;
		while ((*fdf)->zero_coord)
		{
			next_x = (*fdf)->zero_coord->next_x;
			f((void *)fdf);
			(*fdf)->zero_coord = next_x;
		}
		(*fdf)->zero_coord = next_y;
	}
	(*fdf)->zero_coord = zero_coord;
}
