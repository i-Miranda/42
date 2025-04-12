/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 20:29:18 by ivmirand          #+#    #+#             */
/*   Updated: 2025/04/09 22:05:42 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FDF.h"

static void	paint_low(vertex_t start, vertex_t end, mlx_image_t **img, int color)
{
	int	dx;
	int	dy;
	int	yi;
	int	D;

	dx = end.x - start.x;
	dy = end.y - start.y;
	yi = 1;
	if (dy < 0)
	{
		yi = -1;
		dy = -dy;
	}
	D = (2 * dy) - dx;
	while (start.x != end.x)
	{
		if (((unsigned int)start.x <= (*img)->width && (int)start.x >= 0)
				&& ((unsigned int)start.y <= (*img)->height && (int)start.y >= 0))
			mlx_put_pixel(*img, start.x, start.y, color);
		if (D > 0)
		{
			start.y += yi;
			D += 2 * (dy - dx);
		}
		else
			D += 2 * dy;
		start.x++;
	}
}

static void	paint_high(vertex_t start, vertex_t end, mlx_image_t **img, int color)
{
	int	dx;
	int	dy;
	int	xi;
	int	D;

	dx = end.x - start.x;
	dy = end.y - start.y;
	xi = 1;
	if (dx < 0)
	{
		xi = -1;
		dx = -dx;
	}
	D = (2 * dx) - dy;
	while (start.y != end.y)
	{
		if (((unsigned int)start.x <= (*img)->width && (int)start.x >= 0)
				&& ((unsigned int)start.y <= (*img)->height && (int)start.y >= 0))
			mlx_put_pixel(*img, start.x, start.y, color);
		if (D > 0)
		{
			start.x += xi;
			D += 2 * (dx - dy);
		}
		else
			D += 2 * dx;
		start.y++;
	}
}


void bresenham(t_coord *start, t_coord *end, mlx_image_t **img)
{
	if (end == NULL)
	{
		if (((unsigned int)start->world->x <= (*img)->width && (int)start->world->x >= 0) 
			&& ((unsigned int)start->world->y <= (*img)->height && (int)start->world->y >= 0))
			mlx_put_pixel(*img, start->world->x, start->world->y, start->color_hex);
	}
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
