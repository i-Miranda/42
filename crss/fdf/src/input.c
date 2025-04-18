/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 09:09:36 by ivmirand          #+#    #+#             */
/*   Updated: 2025/04/18 02:38:19 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	transform_vertex(vertex_t *vtx, int is_x, float amnt, char *msg)
{
	if (msg != NULL)
		ft_printf("%s\n", msg);
	if (is_x == 0)
		vtx->x += amnt;
	else if (is_x < 0)
		vtx->z += amnt;
	else
		vtx->y += amnt;
}

static void	update_position(t_fdf *fdf, int *key_down)
{
	if (mlx_is_key_down(*fdf->mlx, MLX_KEY_W))
	{
		transform_vertex(fdf->position, 1, -5, "MOVING UP");
		*key_down = 1;
	}
	if (mlx_is_key_down(*fdf->mlx, MLX_KEY_S))
	{
		transform_vertex(fdf->position, 1, 5, "MOVING DOWN");
		*key_down = 1;
	}
	if (mlx_is_key_down(*fdf->mlx, MLX_KEY_A))
	{
		transform_vertex(fdf->position, 0, -5, "MOVING LEFT");
		*key_down = 1;
	}
	if (mlx_is_key_down(*fdf->mlx, MLX_KEY_D))
	{
		transform_vertex(fdf->position, 0, 5, "MOVING RIGHT");
		*key_down = 1;
	}
}

static void	update_scale(t_fdf *fdf, int *key_down)
{
	if (mlx_is_key_down(*fdf->mlx, MLX_KEY_UP))
	{
		transform_vertex(fdf->scale, 1, -1, "SCALING UP");
		*key_down = 1;
	}
	if (mlx_is_key_down(*fdf->mlx, MLX_KEY_DOWN))
	{
		transform_vertex(fdf->scale, 1, 1, "SCALING DOWN");
		*key_down = 1;
	}
	if (mlx_is_key_down(*fdf->mlx, MLX_KEY_LEFT))
	{
		transform_vertex(fdf->scale, 0, -1, "SCALING LEFT");
		*key_down = 1;
	}
	if (mlx_is_key_down(*fdf->mlx, MLX_KEY_RIGHT))
	{
		transform_vertex(fdf->scale, 0, 1, "SCALING RIGHT");
		*key_down = 1;
	}
}

static void	update_height(t_fdf *fdf, int *key_down)
{
	if (mlx_is_key_down(*fdf->mlx, MLX_KEY_K))
	{
		transform_vertex(fdf->scale, -1, 1, "LOWER Z");
		*key_down = 1;
	}
	if (mlx_is_key_down(*fdf->mlx, MLX_KEY_J))
	{
		transform_vertex(fdf->scale, -1, -1, "RAISE Z");
		*key_down = 1;
	}
	if (mlx_is_key_down(*fdf->mlx, MLX_KEY_H))
	{
		transform_vertex(fdf->scale, 1, -1, "ZOOM OUT");
		transform_vertex(fdf->scale, 0, -1, NULL);
		*key_down = 1;
	}
	if (mlx_is_key_down(*fdf->mlx, MLX_KEY_L))
	{
		transform_vertex(fdf->scale, 1, 1, "ZOOM IN");
		transform_vertex(fdf->scale, 0, 1, NULL);
		*key_down = 1;
	}
}

void	input_hook(void *fdf_param)
{
	t_fdf		*fdf;
	int			key_down;
	mlx_image_t	*tmp;

	fdf = (t_fdf *)fdf_param;
	key_down = 0;
	update_position(fdf, &key_down);
	update_scale(fdf, &key_down);
	update_height(fdf, &key_down);
	if (mlx_is_key_down(*fdf->mlx, MLX_KEY_ESCAPE))
	{
		ft_printf("EXITING FDF\n");
		mlx_close_window(*fdf->mlx);
	}
	if (key_down == 1)
	{
		iterate_fdf(&fdf, update_fdf);
		render_bg(fdf, 0x000000FF);
		iterate_fdf(&fdf, render_fdf);
		tmp = *fdf->nxt_img;
		*fdf->nxt_img = *fdf->img;
		*fdf->img = tmp;
		mlx_image_to_window(*fdf->mlx, *fdf->nxt_img, 0, 0);
		ft_printf("Position FDF: %d,%d\n",
			(int)fdf->position->x, (int)fdf->position->y);
		ft_printf("Scale FDF: %d,%d,%d\n",
			(int)fdf->scale->x, (int)fdf->scale->y, (int)fdf->scale->z);
	}
}
