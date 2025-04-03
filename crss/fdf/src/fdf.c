/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 03:19:23 by ivmirand          #+#    #+#             */
/*   Updated: 2025/04/02 22:27:03 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "FDF.h"

static void free_coords(t_coord **start)
{
	t_coord *next_y;
	t_coord *next_x;

	if (start == NULL)
		return;
	while (start)
	{
		if (*start == NULL)
			break;
		next_y = (*start)->next_y;
		while (*start)
		{
			next_x = (*start)->next_x;
			free_coord(start);
			*start = next_x;	
		}
		*start = next_y;	
	}
	free(*start);
}

t_fdf	*init_fdf(int origin_x, int origin_y, char *z_str)
{
	t_fdf	*fdf;

	fdf = ft_calloc(1 + 1, sizeof(t_fdf));
	if (fdf == NULL)
		return (NULL);
	fdf->zero_coord = init_coord(origin_x, origin_y, z_str);	
	return (fdf);
}

void	update_fdf(t_fdf **fdf)
{
	t_coord *zero_coord;
	t_coord *next_y;
	t_coord *next_x;
	
	if (fdf == NULL)
		return ;
	zero_coord = (*fdf)->zero_coord;
	while ((*fdf)->zero_coord)
	{
		if ((*fdf)->zero_coord == NULL)
			break;
		next_y = (*fdf)->zero_coord->next_y;
		while ((*fdf)->zero_coord)
		{
			next_x = (*fdf)->zero_coord->next_x;
			(*fdf)->zero_coord->world->x = (*fdf)->zero_coord->local->x * (*fdf)->scale->x;
			(*fdf)->zero_coord->world->y = (*fdf)->zero_coord->local->y * (*fdf)->scale->y;
			(*fdf)->zero_coord->world->z = (*fdf)->zero_coord->local->z * (*fdf)->scale->z;
			(*fdf)->zero_coord = next_x;
		}
		(*fdf)->zero_coord = next_y;
	}
	(*fdf)->zero_coord = zero_coord;
}

void	print_fdf(t_fdf **fdf)
{
	t_coord *zero_coord;
	t_coord *next_y;
	t_coord *next_x;
	
	if (fdf == NULL)
		return ;
	zero_coord = (*fdf)->zero_coord;
	while ((*fdf)->zero_coord)
	{
		if ((*fdf)->zero_coord == NULL)
			break;
		next_y = (*fdf)->zero_coord->next_y;
		while ((*fdf)->zero_coord)
		{
			next_x = (*fdf)->zero_coord->next_x;
			ft_printf("%d ", (int)(*fdf)->zero_coord->world->z);
			(*fdf)->zero_coord = next_x;
		}
		ft_printf("\n");
		(*fdf)->zero_coord = next_y;
	}
	(*fdf)->zero_coord = zero_coord;
}

void	free_fdf(t_fdf *fdf)
{
	if (fdf == NULL)
		return ;
	if (fdf->zero_coord != NULL)
		free_coords(&fdf->zero_coord);
	if (fdf->dimensions != NULL)
		free(fdf->dimensions);
	if (fdf->origin != NULL)
		free(fdf->origin);
	if (fdf->scale != NULL)
		free(fdf->scale);
	free(fdf);
	fdf = NULL;
}
