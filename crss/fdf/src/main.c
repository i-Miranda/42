/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 09:02:31 by ivmirand          #+#    #+#             */
/*   Updated: 2025/03/09 12:04:19 by ivan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FDF.h"

static void	close_hook(void *param)
{
	printf("%s", (char *)param);
}

int	main(void)
{
	mlx_t	*mlx;
	mlx_image_t	*img;

	mlx_set_setting(MLX_MAXIMIZED, true);	
	mlx = mlx_init(640, 480, "FDF", true);
	img = mlx_new_image(mlx, 64, 64);
	mlx_loop_hook(mlx, input_hook, mlx);
	mlx_close_hook(mlx, close_hook, "GOODBYE!\n");
	mlx_loop(mlx);
	mlx_delete_image(mlx, img);
	mlx_terminate(mlx);
}
