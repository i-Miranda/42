/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 09:09:36 by ivmirand          #+#    #+#             */
/*   Updated: 2025/04/20 01:01:54 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	update_position(t_fdf *fdf, int *key_down)
{
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_W))
	{
		transform_vertex(&fdf->position, 1, -5);
		*key_down = 1;
	}
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_S))
	{
		transform_vertex(&fdf->position, 1, 5);
		*key_down = 1;
	}
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_A))
	{
		transform_vertex(&fdf->position, 0, -5);
		*key_down = 1;
	}
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_D))
	{
		transform_vertex(&fdf->position, 0, 5);
		*key_down = 1;
	}
}

static void	update_scale(t_fdf *fdf, int *key_down)
{
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_UP))
	{
		transform_vertex(&fdf->scale, 1, -1);
		*key_down = 1;
	}
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_DOWN))
	{
		transform_vertex(&fdf->scale, 1, 1);
		*key_down = 1;
	}
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_LEFT))
	{
		transform_vertex(&fdf->scale, 0, -1);
		*key_down = 1;
	}
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_RIGHT))
	{
		transform_vertex(&fdf->scale, 0, 1);
		*key_down = 1;
	}
}

static void	update_height(t_fdf *fdf, int *key_down)
{
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_K))
	{
		transform_vertex(&fdf->scale, -1, 1);
		*key_down = 1;
	}
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_J))
	{
		transform_vertex(&fdf->scale, -1, -1);
		*key_down = 1;
	}
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_H))
	{
		transform_vertex(&fdf->scale, 1, -1);
		transform_vertex(&fdf->scale, 0, -1);
		*key_down = 1;
	}
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_L))
	{
		transform_vertex(&fdf->scale, 1, 1);
		transform_vertex(&fdf->scale, 0, 1);
		*key_down = 1;
	}
}

static void	update_resolution(t_fdf *fdf, int *key_down)
{
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_1))
	{
		fdf->res = 1;
		*key_down = 1;
	}
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_2))
	{
		fdf->res = 2;
		*key_down = 1;
	}
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_3))
	{
		fdf->res = 4;
		*key_down = 1;
	}
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_4))
	{
		fdf->res = 8;
		*key_down = 1;
	}
}

void	input_hook(void *fdf_param)
{
	t_fdf	*fdf;
	int		key_down;

	fdf = (t_fdf *)fdf_param;
	key_down = 0;
	update_position(fdf, &key_down);
	update_scale(fdf, &key_down);
	update_height(fdf, &key_down);
	update_resolution(fdf, &key_down);
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(fdf->mlx);
	if (key_down == 1)
	{
		iterate_fdf(&fdf, update_fdf);
		fdf_draw_call(fdf);
	}
}
