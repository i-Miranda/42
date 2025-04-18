/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 20:29:18 by ivmirand          #+#    #+#             */
/*   Updated: 2025/04/18 01:06:14 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	calc_distance(int *d_x, int *d_y, vertex_t start, vertex_t end)
{
	*d_x = end.x - start.x;
	*d_y = end.y - start.y;
	return (1);
}

static void	paint_low(t_coord start, t_coord end, mlx_image_t **img)
{
	int			distance_x;
	int			distance_y;
	int			yi;
	int			bresenham;
	vertex_t	vtx;

	yi = calc_distance(&distance_x, &distance_y, *start.world, *end.world);
	vtx = *start.world;
	if (distance_y < 0)
	{
		yi = -1;
		distance_y *= -1;
	}
	bresenham = (2 * distance_y) - distance_x;
	vtx.v = fabsf(end.world->x - start.world->x);
	while (vtx.x != end.world->x)
	{
		vtx.u = fabsf(vtx.x++ - start.world->x) / vtx.v;
		safe_put_pixel(vtx, img, start.color_hex, end.color_hex);
		if (bresenham > 0)
		{
			vtx.y += yi;
			bresenham += 2 * (distance_y - distance_x);
		}
		else
			bresenham += 2 * distance_y;
	}
}

static void	paint_high(t_coord start, t_coord end, mlx_image_t **img)
{
	int			distance_x;
	int			distance_y;
	int			xi;
	int			bresenham;
	vertex_t	vtx;

	xi = calc_distance(&distance_x, &distance_y, *start.world, *end.world);
	vtx = *start.world;
	if (distance_x < 0)
	{
		xi = -1;
		distance_x *= -1;
	}
	bresenham = (2 * distance_x) - distance_y;
	vtx.v = fabsf(end.world->y - start.world->y);
	while (vtx.y != end.world->y)
	{
		vtx.u = fabsf(vtx.y++ - start.world->y) / vtx.v;
		safe_put_pixel(vtx, img, start.color_hex, end.color_hex);
		if (bresenham > 0)
		{
			vtx.x += xi;
			bresenham += 2 * (distance_x - distance_y);
		}
		else
			bresenham += 2 * distance_x;
	}
}

void	bresenham(t_coord *start, t_coord *end, mlx_image_t **img)
{
	if (end == NULL)
		safe_put_pixel(*start->world, img, start->color_hex, start->color_hex);
	else
	{
		if (fabsf(end->world->y - start->world->y)
			< fabsf(end->world->x - start->world->x))
		{
			if (start->world->x > end->world->x)
				paint_low(*end, *start, img);
			else
				paint_low(*start, *end, img);
		}
		else
		{
			if (start->world->y > end->world->y)
				paint_high(*end, *start, img);
			else
				paint_high(*start, *end, img);
		}
	}
}
