/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 09:01:16 by ivmirand          #+#    #+#             */
/*   Updated: 2025/04/19 01:12:00 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	render_bg(t_fdf *fdf, int color)
{
	unsigned int	x;
	unsigned int	y;

	y = 0;
	while (y < (*fdf->img)->height)
	{
		x = 0;
		while (x < (*fdf->img)->width)
		{
			mlx_put_pixel(*fdf->img, x, y, color);
			x++;
		}
		y++;
	}
}

void	render_fdf(void *fdf_param)
{
	t_fdf		**fdf;
	vertex_t	bb;

	fdf = (t_fdf **)fdf_param;
	if ((*fdf)->zero_coord->next_x != NULL)
	{
		get_bounding_box((*fdf)->zero_coord->world,
			(*fdf)->zero_coord->next_x->world, &bb);
		if (!(bb.u < 0 || bb.x >= SCRN_WDTH || bb.v < 0 || bb.y >= SCRN_HGHT))
			bresenham((*fdf)->zero_coord, (*fdf)->zero_coord->next_x,
				(*fdf)->img);
	}
	if ((*fdf)->zero_coord->next_y != NULL)
	{
		get_bounding_box((*fdf)->zero_coord->world,
			(*fdf)->zero_coord->next_y->world, &bb);
		if (!(bb.u < 0 || bb.x >= SCRN_WDTH || bb.v < 0 || bb.y >= SCRN_HGHT))
			bresenham((*fdf)->zero_coord, (*fdf)->zero_coord->next_y,
				(*fdf)->img);
	}
}

void	fdf_draw_call(t_fdf *fdf)
{
	mlx_image_t	*tmp;

	mlx_resize_image(*fdf->img, SCRN_WDTH / fdf->res, SCRN_HGHT / fdf->res);
	render_bg(fdf, 0x000000FF);
	iterate_fdf(&fdf, render_fdf);
	mlx_resize_image(*fdf->img, SCRN_WDTH, SCRN_HGHT);
	tmp = *fdf->nxt_img;
	*fdf->nxt_img = *fdf->img;
	*fdf->img = tmp;
	mlx_image_to_window(*fdf->mlx, *fdf->nxt_img, 0, 0);
}
