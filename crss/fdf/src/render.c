/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 09:01:16 by ivmirand          #+#    #+#             */
/*   Updated: 2025/04/09 22:25:14 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FDF.h"

int	get_rgba(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

int	rgb_to_rgba(int rgb, int a)
{
	return (rgb << 8 | a);
}

int		lerp(int start, int current, int end)
{
	int	full;
	int	partial;
	int	percent;

	full = start - end;
	partial = current - end;
	percent = (partial / full) * 100;

	return (percent);
}

void	render_bg(t_fdf *fdf)
{
	int	x;
	int	y;

	y = 0;
	while ((unsigned int)y < (*fdf->img)->height)
	{
		x = 0;
		while ((unsigned int)x < (*fdf->img)->width)
		{
			mlx_put_pixel(*fdf->img, (unsigned int)x, (unsigned int)y, 0x000000FF);
			x++;
		}
		y++;
	}
}

void	render_fdf(void *fdf_param)
{
	t_fdf	**fdf;

	fdf = (t_fdf **)fdf_param;
//	if (((unsigned int)(*fdf)->zero_coord->world->x <= (*(*fdf)->img)->width && (int)(*fdf)->zero_coord->world->x >= 0) 
//		&& ((unsigned int)(*fdf)->zero_coord->world->y <= (*(*fdf)->img)->height && (int)(*fdf)->zero_coord->world->y >= 0))
//	{
//		if (((unsigned int)(*fdf)->zero_coord->next_x->world->x <= (*(*fdf)->img)->width && (int)(*fdf)->zero_coord->next_x->world->x >= 0) 
//			&& ((unsigned int)(*fdf)->zero_coord->next_x->world->y <= (*(*fdf)->img)->height && (int)(*fdf)->zero_coord->next_x->world->y >= 0))
		bresenham((*fdf)->zero_coord, (*fdf)->zero_coord->next_x, (*fdf)->img);
//		if (((unsigned int)(*fdf)->zero_coord->next_x->world->x <= (*(*fdf)->img)->width && (int)(*fdf)->zero_coord->next_x->world->x >= 0) 
//			&& ((unsigned int)(*fdf)->zero_coord->next_x->world->y <= (*(*fdf)->img)->height && (int)(*fdf)->zero_coord->next_x->world->y >= 0))
		bresenham((*fdf)->zero_coord, (*fdf)->zero_coord->next_y, (*fdf)->img);
//	}
}
