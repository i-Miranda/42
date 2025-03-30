/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 03:19:23 by ivmirand          #+#    #+#             */
/*   Updated: 2025/03/30 13:29:34 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "FDF.h"

static void free_coords_rcsv(t_coord *start)
{
	if (start->next_x != NULL)
		free_coords_rcsv(start->next_x);
	if (start->next_y != NULL)
		free_coords_rcsv(start->next_y);
	free_coord(start);
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

void	print_fdf(t_fdf *fdf)
{
	t_coord *temp;
	int	x;
	int y;
	int y_times;
	
	if (fdf == NULL)
		return ;
	temp = fdf->zero_coord;
	y = 0;
	while (y < fdf->dimensions->y)
	{
		y_times = 0;
		while (y_times < y)
		{
			temp = temp->next_y;
			y_times++;
		}
		x = 0;
		while (x < fdf->dimensions->x)
		{
			ft_printf("%d ", (int)temp->local->z);
			temp = temp->next_x;
			x++;
		}
		ft_printf("%c", '\n');
		temp = fdf->zero_coord;
		y++;
	}
}

void	free_fdf(t_fdf *fdf)
{
	if (fdf == NULL)
		return ;
	if (fdf->zero_coord != NULL)
		free_coords_rcsv(fdf->zero_coord);
	if (fdf->dimensions != NULL)
		free(fdf->dimensions);
	if (fdf->origin != NULL)
		free(fdf->origin);
	if (fdf->scale != NULL)
		free(fdf->scale);
	free(fdf);
}
