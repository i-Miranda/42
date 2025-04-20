/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 19:05:48 by ivmirand          #+#    #+#             */
/*   Updated: 2025/04/19 17:30:22 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	*get_rgb_values(int rgba)
{
	int	*rgba_vals;

	rgba_vals = ft_calloc(4 + 1, sizeof(int));
	rgba_vals[0] = (rgba >> 24) & 0xFF;
	rgba_vals[1] = (rgba >> 16) & 0xFF;
	rgba_vals[2] = (rgba >> 8) & 0xFF;
	rgba_vals[3] = rgba & 0xFF;
	return (rgba_vals);
}

void	safe_put_pixel(vertex_t vtx, mlx_image_t *img, int clr, int clr2)
{
	int	color;

	if (clr != clr2)
		color = lerp_rgba(clr, clr2, vtx.u);
	else
		color = clr;
	if (((unsigned int)vtx.x < img->width && (int)vtx.x >= 0)
		&& ((unsigned int)vtx.y < img->height && (int)vtx.y >= 0))
		mlx_put_pixel(img, vtx.x, vtx.y, color);
}

int	get_rgba(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

int	rgb_to_rgba(int rgb, int a)
{
	return (rgb << 8 | a);
}

int	lerp_rgba(int start, int end, float percent)
{
	int	*s_rgba;
	int	*e_rgba;
	int	lerp_rgba[4];
	int	rgba;

	s_rgba = get_rgb_values(start);
	e_rgba = get_rgb_values(end);
	lerp_rgba[0] = s_rgba[0] + (e_rgba[0] - s_rgba[0]) * percent;
	lerp_rgba[1] = s_rgba[1] + (e_rgba[1] - s_rgba[1]) * percent;
	lerp_rgba[2] = s_rgba[2] + (e_rgba[2] - s_rgba[2]) * percent;
	lerp_rgba[3] = s_rgba[3] + (e_rgba[3] - s_rgba[3]) * percent;
	rgba = get_rgba(lerp_rgba[0], lerp_rgba[1], lerp_rgba[2], lerp_rgba[3]);
	free(s_rgba);
	free(e_rgba);
	return (rgba);
}
