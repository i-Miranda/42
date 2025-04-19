/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 09:05:57 by ivmirand          #+#    #+#             */
/*   Updated: 2025/04/19 23:49:44 by ivmirand         ###   ########.fr       */
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

# define SCRN_WDTH 1200
# define SCRN_HGHT 800

//color defaults
# define WHITE 0xFFFFFFFF
# define BLACK 0x000000FF

typedef struct s_coord
{
	vertex_t		local;
	vertex_t		world;
	int				color_hex;	
}	t_coord;

typedef struct s_fdf
{
	vertex_t	position;
	vertex_t	scale;
	t_coord		*coords;
	mlx_t		*mlx;
	mlx_image_t	*img;
	mlx_image_t	*nxt_img;
	int			res;
	int			height;
	int			width;
}	t_fdf;

// Render functions
void		render_bg(t_fdf *fdf, int color);
void		render_fdf(void *fdf_param, t_coord *current);
void		fdf_draw_call(t_fdf *fdf);

// color functions
void		safe_put_pixel(vertex_t vtx, mlx_image_t *img, int clr, int clr2);
int			lerp_rgba(int start, int end, float percent);
int			rgb_to_rgba(int rgb, int a);
int			get_rgba(int r, int g, int b, int a);

// bresenham functions
void		bresenham(t_coord *start, t_coord *end, mlx_image_t *img);

// input functions
void		input_hook(void *fdf_param);

// parse functions
int			parse_fdf(char *fdf_path, t_fdf **fdf);

// collision functions
void		get_bounding_box(vertex_t *start, vertex_t *end, vertex_t *bb);

// terminal functions
void		loading_fdf(int tick, char *msg);
void		ft_error(char *msg);

// fdf	functions
int			init_fdf(t_fdf **fdf, char *fd_pth);
void		mlx_to_fdf(t_fdf **f, mlx_t *m, mlx_image_t *i, mlx_image_t *n);
void		update_fdf(void *fdf_param, t_coord *current);
void		free_fdf(t_fdf *fdf);
void		iterate_fdf(t_fdf **fdf, void (*f)(void *, t_coord *));

// coord functions
void		transform_vertex(vertex_t *vertex, int is_x, float amount);
vertex_t	init_vertex(float x, float y, float z);
void		free_coord(t_coord *coord);
t_coord		*init_coord(int x, int y, char *z_str);

#endif
