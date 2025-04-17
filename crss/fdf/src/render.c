/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 09:01:16 by ivmirand          #+#    #+#             */
/*   Updated: 2025/04/17 12:51:02 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_rgba(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

int	rgb_to_rgba(int rgb, int a)
{
	return (rgb << 8 | a);
}

int	lerp(int start, int current, int end)
{
	int	full;
	int	partial;
	int	percent;

	if (start == end)
		return (start);
	full = start - end;
	partial = current - end;
	percent = (partial / full) * 100;
	return (percent);
}

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
		get_bounding_box((*fdf)->zero_coord->world, (*fdf)->zero_coord->next_x->world, &bb);
		if (!(bb.u < 0 || bb.x >= SCRN_WDTH || bb.v < 0 || bb.y >= SCRN_HGHT))
			bresenham((*fdf)->zero_coord, (*fdf)->zero_coord->next_x, (*fdf)->img);
	}
	if ((*fdf)->zero_coord->next_y != NULL)
	{
		get_bounding_box((*fdf)->zero_coord->world, (*fdf)->zero_coord->next_y->world, &bb);
		if (!(bb.u < 0 || bb.x >= SCRN_WDTH || bb.v < 0 || bb.y >= SCRN_HGHT))
			bresenham((*fdf)->zero_coord, (*fdf)->zero_coord->next_y, (*fdf)->img);
	}
}
