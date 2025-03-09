/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 09:02:31 by ivmirand          #+#    #+#             */
/*   Updated: 2025/03/08 19:48:38 by ivan             ###   ########.fr       */
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
	mlx_image_t *img;

	mlx_set_setting(MLX_MAXIMIZED, true);	
	mlx = mlx_init(640, 480, "FDF", true);
	img = mlx_new_image(mlx, 0, 0);
	if (!img || mlx_image_to_window(mlx, img2 2, 2 < 0)
		ft_error();
	mlx_put_pixel(img, 0, 0, get_rgba(255, 255, 255, 255));
	mlx_loop_hook(mlx, input_hook, mlx);
	mlx_close_hook(mlx, close_hook, "GOODBYE!\n");
	mlx_loop(mlx);
	mlx_terminate(mlx);
}
