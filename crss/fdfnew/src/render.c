/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 09:01:16 by ivmirand          #+#    #+#             */
/*   Updated: 2025/04/20 00:16:27 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	render_bg(t_fdf *fdf, int color)
{
	unsigned int	x;
	unsigned int	y;

	y = 0;
	while (y < fdf->img->height)
	{
		x = 0;
		while (x < fdf->img->width)
		{
			mlx_put_pixel(fdf->img, x, y, color);
			x++;
		}
		y++;
	}
}

void	render_fdf(void *fdf_param, t_coord *current)
{
	t_fdf		**fdf;
	vertex_t	bb;
	t_coord		*next_coord;
	int			x;	
	int			y;	

	fdf = (t_fdf **)fdf_param;
	x = (int)current->local.x;
	y = (int)current->local.y;
	if (current->local.x < (*fdf)->width - 1)
	{
		next_coord = &(*fdf)->coords[y * (*fdf)->width + (x + 1)];
		get_bounding_box(&current->world, &next_coord->world, &bb);
		if (!(bb.u < 0 || bb.x >= SCRN_WDTH || bb.v < 0 || bb.y >= SCRN_HGHT))
			bresenham(current, next_coord, (*fdf)->img);
	}
	if (current->local.y < (*fdf)->height - 1)
	{
		next_coord = &(*fdf)->coords[(y + 1) * (*fdf)->width + x];
		get_bounding_box(&current->world, &next_coord->world, &bb);
		if (!(bb.u < 0 || bb.x >= SCRN_WDTH || bb.v < 0 || bb.y >= SCRN_HGHT))
			bresenham(current, next_coord, (*fdf)->img);
	}
}

void	fdf_draw_call(t_fdf *fdf)
{
	mlx_image_t	*tmp;

	mlx_resize_image(fdf->img, SCRN_WDTH / fdf->res, SCRN_HGHT / fdf->res);
	render_bg(fdf, BLACK);
	iterate_fdf(&fdf, render_fdf);
	mlx_resize_image(fdf->img, SCRN_WDTH, SCRN_HGHT);
	tmp = fdf->nxt_img;
	fdf->nxt_img = fdf->img;
	fdf->img = tmp;
	mlx_image_to_window(fdf->mlx, fdf->nxt_img, 0, 0);
	mlx_delete_image(fdf->mlx, fdf->img);
	fdf->img = mlx_new_image(fdf->mlx, SCRN_WDTH, SCRN_HGHT);
}
