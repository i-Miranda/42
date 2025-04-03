/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 09:09:36 by ivmirand          #+#    #+#             */
/*   Updated: 2025/04/03 16:38:25 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FDF.h"

void	input_hook(void *fdf_param)
{
	t_fdf	*fdf;

	if (fdf_param == NULL)
	{
		ft_printf("input_hook param is null\n");
		return ;
	}
	fdf = (t_fdf *)fdf_param;
	if (mlx_is_key_down(*fdf->mlx, MLX_KEY_W) || mlx_is_key_down(*fdf->mlx, MLX_KEY_UP)
		|| mlx_is_key_down(*fdf->mlx, MLX_KEY_K))
		{
			ft_printf("PRESSING UP\n");
			fdf->scale->y++;
		}
	if (mlx_is_key_down(*fdf->mlx, MLX_KEY_S) || mlx_is_key_down(*fdf->mlx, MLX_KEY_DOWN)
		|| mlx_is_key_down(*fdf->mlx, MLX_KEY_J))
		{
			ft_printf("PRESSING DOWN\n");
			fdf->scale->y--;
		}
	if (mlx_is_key_down(*fdf->mlx, MLX_KEY_A) || mlx_is_key_down(*fdf->mlx, MLX_KEY_LEFT)
		|| mlx_is_key_down(*fdf->mlx, MLX_KEY_H))
		{
			ft_printf("PRESSING LEFT\n");
			fdf->scale->x--;
		}
	if (mlx_is_key_down(*fdf->mlx, MLX_KEY_D) || mlx_is_key_down(*fdf->mlx, MLX_KEY_RIGHT)
		|| mlx_is_key_down(*fdf->mlx, MLX_KEY_L))
		{
			ft_printf("PRESSING RIGHT\n");
			fdf->scale->x++;
		}
	if (mlx_is_key_down(*fdf->mlx, MLX_KEY_ESCAPE))
	{
		ft_printf("EXITING FDF\n");
		mlx_close_window(*fdf->mlx);
	}
}
