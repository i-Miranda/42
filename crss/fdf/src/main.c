/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 09:02:31 by ivmirand          #+#    #+#             */
/*   Updated: 2025/03/31 13:01:13 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FDF.h"

//static void	end_fdf(mlx_t **mlx, mlx_image_t **img, xpm_t **xpm, t_fdf **fdf, int err_code)
//{
//	if (*mlx == NULL)
//		exit(EXIT_FAILURE);
//	if (*xpm)
//		mlx_delete_xpm42(*xpm);
//	if (*img)
//		mlx_delete_image(*mlx, *img);
//	mlx_terminate(*mlx);
//	if (*fdf)
//		free_fdf(*fdf);
//	exit(err_code);
//}

//int	main(int argc, char *argv[])
int	main(void)
{
	mlx_t		*mlx;
	//mlx_image_t	*img;
	//xpm_t		*xpm;
	//t_fdf		*fdf;

	//if (argc != 2)
	//	exit(EXIT_FAILURE);
	mlx_set_setting(MLX_MAXIMIZED, true);	
	if (!(mlx = mlx_init(640, 480, "FDF", true)))
	{
		puts(mlx_strerror(mlx_errno));
		return(EXIT_FAILURE);
	}
	//xpm = mlx_load_xpm42("xpm/test.xpm42");
	//img = mlx_texture_to_image(mlx, &xpm->texture);
	//if (!img || mlx_image_to_window(mlx, img, 0, 0) < 0)
	//	ft_error();
	//parse_fdf(argv[1], &fdf);
	//if (fdf == NULL)
	//	end_fdf(&mlx, &img, &xpm, &fdf, EXIT_FAILURE);
	//ft_printf("FDF DIMENSIONS: %d,%d,%d\n", (int)fdf->dimensions->x, (int)fdf->dimensions->y, (int)fdf->dimensions->z);
	//print_fdf(fdf);
	mlx_loop_hook(mlx, input_hook, mlx);
	mlx_loop(mlx);
	//end_fdf(&mlx, &img, &xpm, &fdf, EXIT_SUCCESS);
	return (EXIT_SUCCESS);
}
