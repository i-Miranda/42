/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 14:56:23 by ivmirand          #+#    #+#             */
/*   Updated: 2025/03/19 13:16:07 by ivan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FDF.h"

t_vector3	*init_vector3(int x, int y, int z)
{
	t_vector3	*vector3;

	vector3 = ft_calloc(1, sizeof(t_vector3));
	if (vector3 == NULL)
		return (NULL);
	vector3->x = x;
	vector3->y = y;
	vector3->z = z;
	return (vector3);
}

void	free_vertex(t_vertex *vertex)
{
	if (vertex == NULL)
		return ;
	if (vertex->coord != NULL)
		free(vertex->coord);
	if (vertex->pos != NULL)
		free(vertex->pos);
	free(vertex);
}

t_vertex	*init_vertex(int x, int y, int z, int color_hex)
{
	t_vertex	*vertex;

	vertex = ft_calloc(1, sizeof(t_vertex));
	if (vertex == NULL)
		return (NULL);
	vertex->coord = init_vector3(x, y, z);
	vertex->pos = init_vector3(-1, -1, -1);
	if (vertex->coord == NULL || vertex->pos == NULL)
	{
		free_vertex(vertex);
		return (NULL);
	}
	if (color_hex < 0)	
		vertex->color_hex = color_hex;
	else
		vertex->color_hex = 0x00000000;
	vertex->next_x = NULL;
	vertex->next_y = NULL;
	return (vertex);
}
