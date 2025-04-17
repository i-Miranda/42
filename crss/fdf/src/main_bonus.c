/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 09:02:31 by ivmirand          #+#    #+#             */
/*   Updated: 2025/04/17 12:51:07 by ivmirand         ###   ########.fr       */
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

int	main(int argc, char *argv[])
{
	int			scrn_wdth;
	int			scrn_hght;
	mlx_t		*mlx;
	mlx_image_t	*img;
	t_fdf		*fdf;

	if (argc != 2)
		exit(EXIT_FAILURE);
	scrn_wdth = 0;
	scrn_hght = 0;
	mlx = mlx_init(SCRN_WDTH, SCRN_HGHT, "FDF", true);
	if (!mlx)
		return (EXIT_FAILURE);
	mlx_get_monitor_size(0, &scrn_wdth, &scrn_hght);
	mlx_set_window_size(mlx, scrn_wdth / 2, scrn_hght / 2);
	mlx_set_window_pos(mlx, scrn_wdth / 4, scrn_hght / 4);
	img = mlx_new_image(mlx, SCRN_WDTH, SCRN_HGHT);
	if (!img)
		return (EXIT_FAILURE);
	init_fdf(&fdf, &mlx, &img);
	if (parse_fdf(argv[1], &fdf) == -1)
	{
		end_fdf(&fdf);
		return (EXIT_FAILURE);
	}
	iterate_fdf(&fdf, update_fdf);
	render_bg(fdf);
	iterate_fdf(&fdf, render_fdf);
	if (!img || mlx_image_to_window(mlx, img, 0, 0) < 0)
		ft_error();
	mlx_loop_hook(mlx, input_hook, fdf);
	mlx_loop(mlx);
	end_fdf(&fdf);
	return (EXIT_SUCCESS);
}
