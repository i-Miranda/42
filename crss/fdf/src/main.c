/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 09:02:31 by ivmirand          #+#    #+#             */
/*   Updated: 2025/04/09 22:07:19 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FDF.h"

static void	end_fdf(void *fdf_param)
{
	t_fdf **fdf;

	fdf = (t_fdf **)fdf_param;
	if ((*fdf)->mlx == NULL)
		exit(EXIT_FAILURE);
	if ((*fdf)->img)
		mlx_delete_image(*(*fdf)->mlx, *(*fdf)->img);
	if ((*fdf)->bg)
		mlx_delete_image(*(*fdf)->mlx, *(*fdf)->bg);
	mlx_terminate(*(*fdf)->mlx);
	if (*fdf)
		free_fdf(*fdf);
}

int	main(int argc, char *argv[])
{
	int			scrn_wdth;
	int			scrn_hght;
	mlx_t		*mlx;
	mlx_image_t	*img;
	mlx_image_t	*bg;
	t_fdf		*fdf;

	if (argc != 2)
		exit(EXIT_FAILURE);
	scrn_wdth = 0;
	scrn_hght = 0;
	if (!(mlx = mlx_init(SCRN_WDTH, SCRN_HGHT, "FDF", true)))
	{
		puts(mlx_strerror(mlx_errno));
		return(EXIT_FAILURE);
	}
	mlx_get_monitor_size(0, &scrn_wdth, &scrn_hght);
	mlx_set_window_size(mlx, scrn_wdth/2, scrn_hght/2);	
	mlx_set_window_pos(mlx, scrn_wdth/4, scrn_hght/4);
	if (!(img = mlx_new_image(mlx, SCRN_WDTH, SCRN_HGHT)))
	{
		puts(mlx_strerror(mlx_errno));
		return(EXIT_FAILURE);
	}
	if (!(bg = mlx_new_image(mlx, SCRN_WDTH, SCRN_HGHT)))
	{
		puts(mlx_strerror(mlx_errno));
		return(EXIT_FAILURE);
	}
	init_fdf(&fdf, &mlx, &img, &bg);
	parse_fdf(argv[1], &fdf);
	ft_printf("FDF DIMENSIONS: %d,%d,%d\n", (int)fdf->dimensions->x, (int)fdf->dimensions->y, (int)fdf->dimensions->z);
	if (!img || mlx_image_to_window(mlx, bg, 0, 0) < 0)
		ft_error();
	if (!img || mlx_image_to_window(mlx, img, 0, 0) < 0)
		ft_error();
	mlx_loop_hook(mlx, input_hook, fdf);
	//mlx_loop_hook(mlx, update_hook, &fdf);
	//mlx_loop_hook(mlx, render_hook, &fdf);
	mlx_loop(mlx);
	end_fdf(&fdf);
	return (EXIT_SUCCESS);
}
