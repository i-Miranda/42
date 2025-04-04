/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FDF.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 09:05:57 by ivmirand          #+#    #+#             */
/*   Updated: 2025/04/03 15:45:49 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <unistd.h>
# include <fcntl.h>
# include <limits.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <stdbool.h>
# include <math.h>

# include "MLX42.h"
# include "MLX42_Int.h"
# include "libft.h"
# include "ft_printf.h"
# include "get_next_line.h"

# define SCRN_WDTH 640
# define SCRN_HGHT 480
# define CHAR_DIMS 64

typedef struct s_coord
{
	struct s_coord	*next_x;
	struct s_coord	*next_y;
	vertex_t		*local;
	vertex_t		*world;
	int				color_hex;	
}	t_coord;

typedef struct s_fdf
{
	mlx_t		**mlx;
	mlx_image_t **img;
	t_coord		*zero_coord;
	vertex_t	*dimensions;
	vertex_t	*position;
	vertex_t	*scale;
	float		angle;
}	t_fdf;

// Render functions
int		get_rgba(int r, int g, int b, int a);
void	crdpnt_rcsv(mlx_image_t *img, t_coord *coord);
void	render_fdf(void *fdf_param);

// Input functions
void	input_hook(void *fdf_param);

// Error functions
void	ft_error(void);

// Parse functions
void	parse_fdf(char *fdf_path, t_fdf **fdf, mlx_t **mlx, mlx_image_t **img);

// fdf	functions
t_fdf	*init_fdf(int origin_x, int origin_y, char *z_str);
void	update_fdf(void *fdf_param);
void	print_fdf(t_fdf **fdf);
void	free_fdf(t_fdf *fdf);

// Vertex functions
void		vector_slope(vertex_t *start, vertex_t *end, int scale);
vertex_t	*init_vertex(float x, float y, float z);
void		free_coord(t_coord **coord);
t_coord		*init_coord(int x, int y, char *z_str);

#endif
