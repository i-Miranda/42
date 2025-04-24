/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 03:19:23 by ivmirand          #+#    #+#             */
/*   Updated: 2025/04/20 12:53:46 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	update_fdf(void *fdf_param, t_coord *current)
{
	t_fdf	**fdf;

	fdf = (t_fdf **)fdf_param;
	current->world.x = (*fdf)->position.x
		+ (current->local.x - current->local.y) * (*fdf)->scale.x;
	current->world.y = (*fdf)->position.y
		+ (current->local.x + current->local.y) * (*fdf)->scale.y;
	current->world.z = current->local.z * (*fdf)->scale.z;
	current->world.y -= current->world.z;
}

void	free_fdf(t_fdf *fdf)
{
	if (fdf == NULL)
		return ;
	if (fdf->coords != NULL)
	{
		free(fdf->coords);
		fdf->coords = NULL;
	}
	free(fdf);
	fdf = NULL;
}

int	init_fdf(t_fdf **fdf, char *fd_pth)
{
	*fdf = ft_calloc(1, sizeof(t_fdf));
	if (*fdf == NULL)
		return (-1);
	(*fdf)->coords = NULL;
	if (parse_fdf(fd_pth, fdf) == -1)
	{
		free_fdf(*fdf);
		return (-1);
	}
	(*fdf)->position = init_vertex(SCRN_WDTH / 4 + 10, 10, 0);
	(*fdf)->scale = init_vertex(SCRN_WDTH / ((*fdf)->width * 2),
			SCRN_HGHT / ((*fdf)->height * 3), 1);
	(*fdf)->res = 4;
	return (0);
}

void	mlx_to_fdf(t_fdf **f, mlx_t *m, mlx_image_t *i, mlx_image_t *n)
{
	(*f)->mlx = m;
	(*f)->img = i;
	(*f)->nxt_img = n;
}

void	iterate_fdf(t_fdf **fdf, void (*f)(void *, t_coord *))
{
	t_coord	*coords;
	t_coord	*current;
	int		y;
	int		x;

	if (fdf == NULL)
		return ;
	coords = (*fdf)->coords;
	y = 0;
	while (y < (*fdf)->height)
	{
		x = 0;
		while (x < (*fdf)->width)
		{
			current = &coords[y * (*fdf)->width + x];
			f((void *)fdf, current);
			x++;
		}
		y++;
	}
}
