/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 20:29:18 by ivmirand          #+#    #+#             */
/*   Updated: 2025/04/16 16:18:14 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FDF.h"

static void	safe_put_pixel(vertex_t vtx, mlx_image_t **img, int color)
{
	if (((unsigned int)vtx.x < (*img)->width && (int)vtx.x >= 0)
			&& ((unsigned int)vtx.y < (*img)->height && (int)vtx.y >= 0))
		mlx_put_pixel(*img, vtx.x, vtx.y, color);
}

static void	paint_low(vertex_t start, vertex_t end, mlx_image_t **img, int clr)
{
	int	distance_x;
	int	distance_y;
	int	yi;
	int	D;

	distance_x = end.x - start.x;
	distance_y = end.y - start.y;
	yi = 1;
	if (distance_y < 0)
	{
		yi = -1;
		distance_y *= -1;
	}
	D = (2 * distance_y) - distance_x;
	while (start.x != end.x)
	{
		safe_put_pixel(start, img, clr);
		if (D > 0)
		{
			start.y += yi;
			D += 2 * (distance_y - distance_x);
		}
		else
			D += 2 * distance_y;
		start.x++;
	}
}

static void	paint_high(vertex_t start, vertex_t end, mlx_image_t **img, int clr)
{
	int	distance_x;
	int	distance_y;
	int	xi;
	int	D;

	distance_x = end.x - start.x;
	distance_y = end.y - start.y;
	xi = 1;
	if (distance_x < 0)
	{
		xi = -1;
		distance_x *= -1;
	}
	D = (2 * distance_x) - distance_y;
	while (start.y != end.y)
	{
		safe_put_pixel(start, img, clr);
		if (D > 0)
		{
			start.x += xi;
			D += 2 * (distance_x - distance_y);
		}
		else
			D += 2 * distance_x;
		start.y++;
	}
}

void bresenham(t_coord *start, t_coord *end, mlx_image_t **img)
{
	if (end == NULL)
		safe_put_pixel(*start->world, img, start->color_hex);
	else
	{
		if (fabsf(end->world->y - start->world->y) < fabsf(end->world->x - start->world->x))
		{
			if (start->world->x > end->world->x)
				paint_low(*(end->world), *(start->world), img, start->color_hex); 	
			else
				paint_low(*(start->world), *(end->world), img, start->color_hex); 	
		}
		else
		{
			if (start->world->y > end->world->y)
				paint_high(*(end->world), *(start->world), img, start->color_hex); 	
			else
				paint_high(*(start->world), *(end->world), img, start->color_hex); 	
		}
	}
}
