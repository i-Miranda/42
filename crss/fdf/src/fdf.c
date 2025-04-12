/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 03:19:23 by ivmirand          #+#    #+#             */
/*   Updated: 2025/04/09 22:14:51 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "FDF.h"

static void free_coords(void *fdf_param)
{
	t_fdf **fdf;

	fdf = (t_fdf **)fdf_param;
	free_coord(&(*fdf)->zero_coord);
}

void	update_fdf(void *fdf_param)
{
	t_fdf **fdf;

	fdf = (t_fdf **)fdf_param;
	(*fdf)->zero_coord->world->x = (*fdf)->position->x + ((*fdf)->zero_coord->local->x - (*fdf)->zero_coord->local->y) * (*fdf)->scale->x;
	(*fdf)->zero_coord->world->y = (*fdf)->position->y + ((*fdf)->zero_coord->local->x + (*fdf)->zero_coord->local->y) * (*fdf)->scale->y;
	(*fdf)->zero_coord->world->z = (*fdf)->zero_coord->local->z * (*fdf)->scale->z;
	(*fdf)->zero_coord->world->y -= (*fdf)->zero_coord->world->z;
}

//void	print_fdf(void *fdf_param)
//{
//	t_fdf	**fdf;
//
//	fdf = (t_fdf **)fdf_param;
//	ft_printf("%d ", (int)(*fdf)->zero_coord->world->z);
//	ft_printf("\n");
//}

void	parse_fdf(char *fdf_path, t_fdf **fdf)
{
	t_coord *coord;
	int		fd;	
	int		col_count;	
	int		row_count;	

	fd = open(fdf_path, O_RDONLY);
	parse_fd(fd, fdf);
	coord = (*fdf)->zero_coord;
	row_count = 1;
	col_count = 1;
	while (coord->next_y != NULL)
	{
		coord = coord->next_y;
		row_count++;
	}
	while (coord->next_x != NULL)
	{
		coord = coord->next_x;
		col_count++;
	}
	(*fdf)->dimensions->x = col_count;
	(*fdf)->dimensions->y = row_count;
	(*fdf)->dimensions->z = 0; //get the real dimensions
	close(fd);
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

void	init_fdf(t_fdf **fdf, mlx_t **mlx, mlx_image_t **img, mlx_image_t **bg)
{
	*fdf = ft_calloc(1 + 1, sizeof(t_fdf));
	if (fdf == NULL)
		return;
	(*fdf)->mlx = mlx;
	(*fdf)->img = img;
	(*fdf)->bg = bg;
	(*fdf)->zero_coord = NULL;
	(*fdf)->dimensions = init_vertex(0, 0, 0);
	(*fdf)->position = init_vertex(SCRN_WDTH/2, SCRN_HGHT/2, 0);
	(*fdf)->scale = init_vertex(10, 1, 4);
}
