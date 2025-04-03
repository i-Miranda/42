/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 09:02:31 by ivmirand          #+#    #+#             */
/*   Updated: 2025/04/03 11:13:30 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FDF.h"

static void	end_fdf(mlx_t **mlx, mlx_image_t **img, t_fdf **fdf, int err_code)
{
	if (*mlx == NULL)
		exit(EXIT_FAILURE);
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
	t_fdf		*fdf;

	if (argc != 2)
		exit(EXIT_FAILURE);
	mlx_set_setting(MLX_MAXIMIZED, true);	
	if (!(mlx = mlx_init(SCRN_WDTH, SCRN_HGHT, "FDF", true)))
	{
		puts(mlx_strerror(mlx_errno));
		return(EXIT_FAILURE);
	}
	if (!(img = mlx_new_image(mlx, 640, 480)))
	{
		puts(mlx_strerror(mlx_errno));
		return(EXIT_FAILURE);
	}
	parse_fdf(argv[1], &fdf);
	if (fdf == NULL)
		end_fdf(&mlx, &img, &fdf, EXIT_FAILURE);
	ft_printf("FDF DIMENSIONS: %d,%d,%d\n", (int)fdf->dimensions->x, (int)fdf->dimensions->y, (int)fdf->dimensions->z);
	fdf->scale->x = 10;
	fdf->scale->y = 10;
	fdf->scale->z = 10;
	update_fdf(&fdf);
	print_fdf(&fdf);
	render_fdf(img, &fdf);
	if (!img || mlx_image_to_window(mlx, img, 0, 0) < 0)
		ft_error();
	mlx_loop_hook(mlx, input_hook, mlx);
	mlx_loop(mlx);
	end_fdf(&mlx, &img, &fdf, EXIT_SUCCESS);
	return (EXIT_SUCCESS);
}
