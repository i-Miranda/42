/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 09:02:31 by ivmirand          #+#    #+#             */
/*   Updated: 2025/04/20 12:15:08 by ivmirand         ###   ########.fr       */
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
		mlx_delete_image((*fdf)->mlx, (*fdf)->img);
	if ((*fdf)->nxt_img)
		mlx_delete_image((*fdf)->mlx, (*fdf)->nxt_img);
	mlx_terminate((*fdf)->mlx);
	if (*fdf)
		free_fdf(*fdf);
}

static int	init_mlx(mlx_t **mlx, t_fdf **fdf, char *path)
{
	mlx_image_t	*img;
	mlx_image_t	*nxt_img;
	int			scrn_wdth;
	int			scrn_hght;
	int			init;

	scrn_wdth = 0;
	scrn_hght = 0;
	init = init_fdf(fdf, path);
	if (init != 0)
		return (init);
	*mlx = mlx_init(SCRN_WDTH, SCRN_HGHT, "FDF", true);
	if (!(*mlx))
		return (EXIT_FAILURE);
	mlx_get_monitor_size(0, &scrn_wdth, &scrn_hght);
	mlx_set_window_size(*mlx, SCRN_WDTH, SCRN_HGHT);
	mlx_set_window_pos(*mlx, scrn_wdth / 4, scrn_hght / 4);
	img = mlx_new_image(*mlx, SCRN_WDTH / 4, SCRN_HGHT / 4);
	nxt_img = mlx_new_image(*mlx, SCRN_WDTH / 4, SCRN_HGHT / 4);
	mlx_to_fdf(fdf, *mlx, img, nxt_img);
	return (init);
}

int	main(int argc, char *argv[])
{
	mlx_t		*mlx;
	t_fdf		*fdf;

	if (argc != 2)
		ft_error("Error: incorrect argument count (2)");
	if (init_mlx(&mlx, &fdf, argv[1]) != 0)
		ft_error("Error: incorrect filetype (.fdf)");
	iterate_fdf(&fdf, update_fdf);
	render_bg(fdf, BLACK);
	iterate_fdf(&fdf, render_fdf);
	mlx_resize_image(fdf->img, SCRN_WDTH, SCRN_HGHT);
	if (!fdf->img || mlx_image_to_window(mlx, fdf->img, 0, 0) < 0)
		ft_error((char *)mlx_strerror(mlx_errno));
	mlx_loop_hook(mlx, input_hook, fdf);
	mlx_loop(mlx);
	end_fdf(&fdf);
	return (EXIT_SUCCESS);
}
