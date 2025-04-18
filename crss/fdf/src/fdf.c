/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 03:19:23 by ivmirand          #+#    #+#             */
/*   Updated: 2025/04/19 01:12:39 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
		* (int)(*fdf)->scale->x;
	(*fdf)->zero_coord->world->y = (*fdf)->position->y
		+ ((*fdf)->zero_coord->local->x + (*fdf)->zero_coord->local->y)
		* (int)(*fdf)->scale->y;
	(*fdf)->zero_coord->world->z = (*fdf)->zero_coord->local->z
		* (int)(*fdf)->scale->z;
	(*fdf)->zero_coord->world->y -= (*fdf)->zero_coord->world->z;
}

void	free_fdf(t_fdf *fdf)
{
	if (fdf == NULL)
		return ;
	if (fdf->zero_coord != NULL)
		iterate_fdf(&fdf, free_coords);
	if (fdf->position != NULL)
		free(fdf->position);
	if (fdf->scale != NULL)
		free(fdf->scale);
	if (fdf->dimensions != NULL)
		free(fdf->dimensions);
	free(fdf);
	fdf = NULL;
}

void	init_fdf(t_fdf **fdf, mlx_t **mlx, mlx_image_t **img, char *fd_pth)
{
	*fdf = ft_calloc(1 + 1, sizeof(t_fdf));
	if (*fdf == NULL)
		return ;
	(*fdf)->mlx = mlx;
	(*fdf)->img = img;
	(*fdf)->zero_coord = NULL;
	(*fdf)->dimensions = init_vertex(0, 0, 1);
	if (parse_fdf(fd_pth, fdf) == -1)
		return ;
	(*fdf)->position = init_vertex(SCRN_WDTH / 4, SCRN_HGHT / 16, 0);
	(*fdf)->scale = init_vertex(SCRN_WDTH / ((*fdf)->dimensions->x * 4),
			SCRN_HGHT / ((*fdf)->dimensions->y * 4), 1);
	(*fdf)->res = 4;
}
