/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 09:02:31 by ivmirand          #+#    #+#             */
/*   Updated: 2025/04/19 00:45:22 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	end_fdf(void *fdf_param)
{
	t_fdf	**fdf;

	fdf = (t_fdf **)fdf_param;
	if ((*fdf)->mlx == NULL)
		exit(EXIT_FAILURE);
	if ((*fdf)->img)
		mlx_delete_image(*(*fdf)->mlx, *(*fdf)->img);
	mlx_terminate(*(*fdf)->mlx);
	if (*fdf)
		free_fdf(*fdf);
}

static int	init_mlx(mlx_t **mlx, mlx_image_t **img, t_fdf **fdf, char *path)
{
	int	scrn_wdth;
	int	scrn_hght;

	scrn_wdth = 0;
	scrn_hght = 0;
	*mlx = mlx_init(SCRN_WDTH, SCRN_HGHT, "FDF", true);
	if (!(*mlx))
		return (EXIT_FAILURE);
	mlx_get_monitor_size(0, &scrn_wdth, &scrn_hght);
	mlx_set_window_size(*mlx, SCRN_WDTH, SCRN_HGHT);
	mlx_set_window_pos(*mlx, scrn_wdth / 4, scrn_hght / 4);
	*img = mlx_new_image(*mlx, SCRN_WDTH / 4, SCRN_HGHT / 4);
	if (!(*img))
	{
		mlx_terminate(*mlx);
		return (EXIT_FAILURE);
	}
	init_fdf(fdf, mlx, img, path);
	return (0);
}

int	main(int argc, char *argv[])
{
	mlx_t		*mlx;
	mlx_image_t	*img;
	mlx_image_t	*nxt_img;
	t_fdf		*fdf;

	if (argc != 2)
		ft_error("Error: incorrect argument count (2)");
	if (init_mlx(&mlx, &img, &fdf, argv[1]) != 0)
		ft_error("Error: incorrect filetype (.fdf)");
	nxt_img = mlx_new_image(*fdf->mlx, SCRN_WDTH / 4, SCRN_HGHT / 4);
	fdf->nxt_img = &nxt_img;
	iterate_fdf(&fdf, update_fdf);
	render_bg(fdf, 0x000000FF);
	iterate_fdf(&fdf, render_fdf);
	mlx_resize_image(img, SCRN_WDTH, SCRN_HGHT);
	if (!img || mlx_image_to_window(mlx, img, 0, 0) < 0)
		ft_error((char *)mlx_strerror(mlx_errno));
	mlx_loop_hook(mlx, input_hook, fdf);
	mlx_loop(mlx);
	end_fdf(&fdf);
	return (EXIT_SUCCESS);
}
