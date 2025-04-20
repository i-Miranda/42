/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coord.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 14:56:23 by ivmirand          #+#    #+#             */
/*   Updated: 2025/04/19 13:02:53 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	transform_vertex(vertex_t *vertex, int is_x, float amount)
{
	if (is_x == 0)
		vertex->x += amount;
	else if (is_x < 0)
		vertex->z += amount;
	else
		vertex->y += amount;
}

vertex_t	init_vertex(float x, float y, float z)
{
	vertex_t	vertex;

	vertex.x = x;
	vertex.y = y;
	vertex.z = z;
	return (vertex);
}
