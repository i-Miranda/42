/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 09:01:16 by ivmirand          #+#    #+#             */
/*   Updated: 2025/04/03 16:37:54 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FDF.h"

int	get_rgba(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

static	void paint_line(mlx_image_t *img, t_coord *start, t_coord *end)
{
	vertex_t distance;

	distance.x = start->world->x;	
	distance.y = start->world->y;
	if (end != NULL && start->world->z != 0 && end->world->z != 0)
	{
		ft_printf("paint_line: %d,%d to %d,%d\n", (int)start->world->x, (int)start->world->y,
				(int)end->world->x, (int)end->world->y);
		while (distance.x != end->world->x || distance.y != end->world->y)
		{
			mlx_put_pixel(img, distance.x, distance.y,
				get_rgba(0, 0, 255, 255));
			if (distance.x != end->world->x)
				distance.x++;
			if (distance.y != end->world->y)
				distance.y++;
		}	
	}
	else
	{
		mlx_put_pixel(img, distance.x, distance.y,
			get_rgba(255, 0, 0, 255));
	}
}

void	render_fdf(void *fdf_param)
{
	t_fdf	**fdf;
	t_coord *zero_coord;
	t_coord *next_y;
	t_coord *next_x;
	
	if (fdf_param == NULL)
		return ;
	fdf = (t_fdf **)fdf_param;
	zero_coord = (*fdf)->zero_coord;
	//mlx_delete_image(*(*fdf)->mlx, *(*fdf)->img);
	//if (!(*(*fdf)->img = mlx_new_image(*(*fdf)->mlx, 640, 480)))
	//{
	//	puts(mlx_strerror(mlx_errno));
	//	return ;
	//}
	while ((*fdf)->zero_coord)
	{
		if ((*fdf)->zero_coord == NULL)
			break;
		next_y = (*fdf)->zero_coord->next_y;
		while ((*fdf)->zero_coord)
		{
			next_x = (*fdf)->zero_coord->next_x;
			paint_line(*(*fdf)->img, (*fdf)->zero_coord, (*fdf)->zero_coord->next_x);
			paint_line(*(*fdf)->img, (*fdf)->zero_coord, (*fdf)->zero_coord->next_y);
			(*fdf)->zero_coord = next_x;
		}
		(*fdf)->zero_coord = next_y;
	}
	(*fdf)->zero_coord = zero_coord;
}
