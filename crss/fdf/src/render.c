/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 09:01:16 by ivmirand          #+#    #+#             */
/*   Updated: 2025/03/09 12:01:48 by ivan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FDF.h"

int	get_rgba(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

//static	void paint_line(mlx_image_t *img, t_coord *start, t_coord *end)
//{
//	if (end != NULL)
//	{
//		//calculate distance between start->world and end->world
//		//paint with bresenham into img
//	}
//}
//
//void	crdpnt_rcsv(mlx_image_t *img, t_coord *coord)
//{
//	if (coord->next_x != NULL)
//	{
//		crdpnt_rcsv(img, coord->next_x);
//		paint_line(img, coord, coord->next_x);
//	}
//	if (coord->next_x != NULL)
//	{
//		crdpnt_rcsv(img, coord->next_y);
//		paint_line(img, coord, coord->next_y);
//	}
//}
