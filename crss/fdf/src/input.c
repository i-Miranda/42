/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 09:09:36 by ivmirand          #+#    #+#             */
/*   Updated: 2025/04/09 22:21:24 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FDF.h"

static void	exit_fdf_window(t_fdf *fdf)
{
	ft_printf("EXITING FDF\n");
	mlx_close_window(*fdf->mlx);
}

static void	input_position(vertex_t *vertex, int is_x, int amount, char *msg)
{
	ft_printf("%s\n", msg);
	if (is_x == 0)
	{
		vertex->x += amount;
		if (vertex->x < 0)
			vertex->x = 1;
		else if (vertex->x > SCRN_WDTH)
			vertex->x = SCRN_WDTH;
	}
	else
	{
		vertex->y += amount;
		if (vertex->y < 0)
			vertex->y = 1;
		else if (vertex->y > SCRN_HGHT)
			vertex->y = SCRN_HGHT;
	}
}

void	input_hook(void *fdf_param)
{
	t_fdf	*fdf;
	int		key_down;

	fdf = (t_fdf *)fdf_param;
	key_down = 0;
	if (mlx_is_key_down(*fdf->mlx, MLX_KEY_W) || mlx_is_key_down(*fdf->mlx, MLX_KEY_UP) || mlx_is_key_down(*fdf->mlx, MLX_KEY_K))
	{
		input_position(fdf->position, 1, -1, "PRESSING UP");
		key_down = 1;
	}
	if (mlx_is_key_down(*fdf->mlx, MLX_KEY_S) || mlx_is_key_down(*fdf->mlx, MLX_KEY_DOWN) || mlx_is_key_down(*fdf->mlx, MLX_KEY_J))
	{
		input_position(fdf->position, 1, 1, "PRESSING DOWN");
		key_down = 1;
	}
	if (mlx_is_key_down(*fdf->mlx, MLX_KEY_A) || mlx_is_key_down(*fdf->mlx, MLX_KEY_LEFT) || mlx_is_key_down(*fdf->mlx, MLX_KEY_H))
	{
		input_position(fdf->position, 0, -1, "PRESSING LEFT");
		key_down = 1;
	}
	if (mlx_is_key_down(*fdf->mlx, MLX_KEY_D) || mlx_is_key_down(*fdf->mlx, MLX_KEY_RIGHT) || mlx_is_key_down(*fdf->mlx, MLX_KEY_L))
	{
		input_position(fdf->position, 0, 1, "PRESSING RIGHT");
		key_down = 1;
	}
	if (mlx_is_key_down(*fdf->mlx, MLX_KEY_ESCAPE))
		exit_fdf_window(fdf);
	if (key_down == 1)
	{
		iterate_fdf(&fdf, update_fdf);
		render_bg(fdf);
		iterate_fdf(&fdf, render_fdf);
		ft_printf("Position FDF: %d,%d\n", (int)fdf->position->x, (int)fdf->position->y);
	}
}
