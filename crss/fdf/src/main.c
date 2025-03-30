/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 09:02:31 by ivmirand          #+#    #+#             */
/*   Updated: 2025/03/30 18:13:41 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FDF.h"

static void	close_hook(void *param)
{
	printf("%s", (char *)param);
}

static void	end_fdf(mlx_t **mlx, mlx_image_t **img, xpm_t **xpm, t_fdf **fdf, int err_code)
{
	if (*mlx == NULL)
		exit(EXIT_FAILURE);
	if (*xpm)
		mlx_delete_xpm42(*xpm);
	if (*img)
		mlx_delete_image(*mlx, *img);
	mlx_terminate(*mlx);
	if (*fdf)
		free_fdf(*fdf);
	exit(err_code);
}

int	main(int argc, char *argv[])
{
	mlx_t		*mlx;
	mlx_image_t	*img;
	xpm_t		*xpm;
	t_fdf		*fdf;

	if (argc != 2)
		exit(EXIT_FAILURE);
	mlx_set_setting(MLX_MAXIMIZED, true);	
	mlx = mlx_init(640, 480, "FDF", true);
	xpm = mlx_load_xpm42("xpm/test.xpm42");
	img = mlx_texture_to_image(mlx, &xpm->texture);
	if (!img || mlx_image_to_window(mlx, img, 0, 0) < 0)
		ft_error();
	parse_fdf(argv[1], &fdf);
	if (fdf == NULL)
		end_fdf(&mlx, &img, &xpm, &fdf, EXIT_FAILURE);
	ft_printf("FDF DIMENSIONS: %d,%d,%d\n", (int)fdf->dimensions->x, (int)fdf->dimensions->y, (int)fdf->dimensions->z);
	print_fdf(fdf);
	mlx_close_hook(mlx, close_hook, "GOODBYE!\n");
	mlx_loop_hook(mlx, input_hook, mlx);
	mlx_loop(mlx);
	end_fdf(&mlx, &img, &xpm, &fdf, EXIT_SUCCESS);
	return (EXIT_SUCCESS);
}
