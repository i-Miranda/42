/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 16:48:29 by ivmirand          #+#    #+#             */
/*   Updated: 2025/04/09 18:45:53 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FDF.h"

void	update_hook(void *fdf_param)
{
	t_fdf **fdf;

	fdf = (t_fdf **)fdf_param;
	iterate_fdf(fdf, update_fdf);
	render_bg(*fdf);
	iterate_fdf(fdf, render_fdf);
	ft_printf("Position FDF: %d,%d\n", (int)(*fdf)->position->x, (int)(*fdf)->position->y);
}

void	render_hook(void *fdf_param)
{
	t_fdf **fdf;

	fdf = (t_fdf **)fdf_param;
	render_bg(*fdf);
	iterate_fdf(fdf, render_fdf);
}

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
