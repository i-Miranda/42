/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 10:23:24 by ivmirand          #+#    #+#             */
/*   Updated: 2025/04/16 18:55:02 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FDF.h"

//vertex_t	*get_bounding_box(vertex_t *start, vertex_t *end)
//{
//	vertex_t bb;
//
//	bb = ft_calloc(1+1, sizeof(vertex_t));
//	if  (end != NULL)
//	{		
//		if (start->x < end->x)
//			bb->x = start->x; 
//		else
//			bb->x = end->x; 
//		if (start->x > end->x)
//			bb->u = start->x; 
//		else
//			bb->u = end->x; 
//		if (start->y < end->y)
//			bb->y = start->y; 
//		else
//			bb->y = end->y; 
//		if (start->y > end->y)
//			bb->v = start->y; 
//		else
//			bb->v = end->y; 
//	}
//	return (bb);
//}

void	get_bounding_box(vertex_t *start, vertex_t *end, vertex_t *bb)
{
	if  (end != NULL)
	{		
		if (start->x < end->x)
			bb->x = start->x; 
		else
			bb->x = end->x; 
		if (start->x > end->x)
			bb->u = start->x; 
		else
			bb->u = end->x; 
		if (start->y < end->y)
			bb->y = start->y; 
		else
			bb->y = end->y; 
		if (start->y > end->y)
			bb->v = start->y; 
		else
			bb->v = end->y; 
	}
}
