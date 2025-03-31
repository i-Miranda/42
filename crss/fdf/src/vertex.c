/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 14:56:23 by ivmirand          #+#    #+#             */
/*   Updated: 2025/03/31 02:12:21 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FDF.h"

//scale should probably be a float.  If i do this maybe i should just use the
//mlx vector
//void	vertex_slope(vertex_t *start, vertex_t *end)
//{
//	if (start == NULL || end == NULL)
//		return ;
//	if (start->x == end->x)
//		//get slope between y and z
//		return ;
//	else if (start->y == end->y)
//		//get slope between x and z
//		return ;
//	else
//		//get slope between x and y
//		return ;
//}

vertex_t	*init_vertex(float x, float y, float z)
{
	vertex_t	*vertex;

	vertex = ft_calloc(1, sizeof(vertex_t));
	if (vertex == NULL)
		return (NULL);
	vertex->x = x;
	vertex->y = y;
	vertex->z = z;
	return (vertex);
}

void	free_coord(t_coord *coord)
{
	if (coord == NULL)
		return ;
	ft_printf("Freeing coord: %d,%d\n", (int)coord->local->x, (int)coord->local->y);
	if (coord->local != NULL)
	{
		free(coord->local);
		coord->local = NULL;
	}
	if (coord->world != NULL)
	{
		free(coord->world);
		coord->world = NULL;
	}
	free(coord);
	coord = NULL;
}

t_coord	*init_coord(int x, int y, char *z_str)
{
	char 	**color_split;
	t_coord	*coord;

	color_split = ft_split(z_str, ',');
	coord = ft_calloc(1, sizeof(t_coord));
	if (coord == NULL || color_split == NULL)
		return (NULL);
	coord->local = init_vertex(x, y, (int)ft_atol(color_split[0]));
	coord->world = init_vertex(-1, -1, -1);
	if (coord->local == NULL || coord->world == NULL)
	{
		free_coord(coord);
		return (NULL);
	}
	if (color_split[1] != NULL)
		coord->color_hex = 0x000000;
	else
		coord->color_hex = 0xFFFFFF;
	ft_free_split(color_split);
	coord->next_x = NULL;
	coord->next_y = NULL;
	return (coord);
}
