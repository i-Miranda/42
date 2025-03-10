/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 09:09:36 by ivmirand          #+#    #+#             */
/*   Updated: 2025/03/10 11:15:23 by ivan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FDF.h"

void	input_hook(void *mlx_param)
{
	mlx_t *mlx;
	if (mlx_param == NULL)
	{
		ft_printf("input_hook param is null\n");
		return ;
	}
		mlx = (mlx_t *)mlx_param; 
	if (mlx_is_key_down(mlx, MLX_KEY_W) || mlx_is_key_down(mlx, MLX_KEY_UP)
			|| mlx_is_key_down(mlx, MLX_KEY_K))
		ft_printf("PRESSING UP\n");
	if (mlx_is_key_down(mlx, MLX_KEY_S) || mlx_is_key_down(mlx, MLX_KEY_DOWN)
			|| mlx_is_key_down(mlx, MLX_KEY_J))
		ft_printf("PRESSING DOWN\n");
	if (mlx_is_key_down(mlx, MLX_KEY_A) || mlx_is_key_down(mlx, MLX_KEY_LEFT)
			|| mlx_is_key_down(mlx, MLX_KEY_H))
		ft_printf("PRESSING LEFT\n");
	if (mlx_is_key_down(mlx, MLX_KEY_D) || mlx_is_key_down(mlx, MLX_KEY_RIGHT)
			|| mlx_is_key_down(mlx, MLX_KEY_L))
		ft_printf("PRESSING RIGHT\n");
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
	{
		ft_printf("EXITING FDF\n");
		mlx_close_window(mlx);
	}
}
