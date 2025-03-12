/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 09:02:31 by ivmirand          #+#    #+#             */
/*   Updated: 2025/03/11 12:11:39 by ivan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FDF.h"

static void	close_hook(void *param)
{
	printf("%s", (char *)param);
}

static void	end_fdf(mlx_t **mlx, mlx_image_t **img, xpm_t **xpm, int ***fdf, int err_code)
{
	if (mlx == NULL)
		exit(EXIT_FAILURE);
	if (img)
		mlx_delete_image(*mlx, *img);
	if (xpm)
		mlx_delete_xpm42(*xpm);
	if (fdf)
		free(*fdf);
	mlx_terminate(*mlx);
	exit(err_code)
}

int	main(int argc, char *argv[])
{
	mlx_t		*mlx;
	mlx_image_t	*img;
	xpm_t		*xpm;
	int			**fdf;

	if (argc != 2)
		exit(EXIT_FAILURE);
	mlx_set_setting(MLX_MAXIMIZED, true);	
	mlx = mlx_init(640, 480, "FDF", true);
	xpm = mlx_load_xpm42("xpm/test.xpm42");
	img = mlx_texture_to_image(mlx, &xpm->texture);
	if (!img || mlx_image_to_window(mlx, img, 0, 0) < 0)
		ft_error();
	fdf = parse_fdf(argv[1]);
	if (fdf == NULL)
		end_fdf(&mlx, &img, &xpm, &fdf, EXIT_FAILURE);
	mlx_loop_hook(mlx, input_hook, mlx);
	mlx_close_hook(mlx, close_hook, "GOODBYE!\n");
	mlx_loop(mlx);
	end_fdf(&mlx, &img, &xpm, &fdf, EXIT_SUCCESS);
	return (EXIT_SUCCESS);
}
