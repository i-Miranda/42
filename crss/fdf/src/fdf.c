/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 03:19:23 by ivmirand          #+#    #+#             */
/*   Updated: 2025/04/17 12:23:36 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FDF.h"

static void	free_coords(void *fdf_param)
{
	t_fdf	**fdf;

	fdf = (t_fdf **)fdf_param;
	free_coord((*fdf)->zero_coord);
}

void	update_fdf(void *fdf_param)
{
	t_fdf	**fdf;

	fdf = (t_fdf **)fdf_param;
	(*fdf)->zero_coord->world->x = (*fdf)->position->x
		+ ((*fdf)->zero_coord->local->x - (*fdf)->zero_coord->local->y)
		* (*fdf)->scale->x;
	(*fdf)->zero_coord->world->y = (*fdf)->position->y
		+ ((*fdf)->zero_coord->local->x + (*fdf)->zero_coord->local->y)
		* (*fdf)->scale->y;
	(*fdf)->zero_coord->world->z = (*fdf)->zero_coord->local->z * (*fdf)->scale->z;
	(*fdf)->zero_coord->world->y -= (*fdf)->zero_coord->world->z;
}

void	free_fdf(t_fdf *fdf)
{
	if (fdf == NULL)
		return ;
	if (fdf->zero_coord != NULL)
		iterate_fdf(&fdf, free_coords);
	if (fdf->dimensions != NULL)
		free(fdf->dimensions);
	if (fdf->position != NULL)
		free(fdf->position);
	if (fdf->scale != NULL)
		free(fdf->scale);
	free(fdf);
	fdf = NULL;
}

void	init_fdf(t_fdf **fdf, mlx_t **mlx, mlx_image_t **img)
{
	*fdf = ft_calloc(1 + 1, sizeof(t_fdf));
	if (fdf == NULL)
		return ;
	(*fdf)->mlx = mlx;
	(*fdf)->img = img;
	(*fdf)->zero_coord = NULL;
	(*fdf)->dimensions = init_vertex(0, 0, 0);
	(*fdf)->position = init_vertex(SCRN_WDTH / 2, SCRN_HGHT / 2, 0);
	(*fdf)->scale = init_vertex(10, 1, 4);
}
