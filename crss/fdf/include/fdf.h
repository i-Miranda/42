/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 09:05:57 by ivmirand          #+#    #+#             */
/*   Updated: 2025/04/18 02:16:59 by ivmirand         ###   ########.fr       */
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

# define SCRN_WDTH 400
# define SCRN_HGHT 400
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
	mlx_image_t	**img;
	mlx_image_t	**nxt_img;
	t_coord		*zero_coord;
	vertex_t	*position;
	vertex_t	*scale;
}	t_fdf;

// Render functions
void		render_bg(t_fdf *fdf, int color);
void		render_fdf(void *fdf_param);

// color functions
void	safe_put_pixel(vertex_t vtx, mlx_image_t **img, int clr, int clr2);
int		lerp_rgba(int start, int end, float percent);
int		rgb_to_rgba(int rgb, int a);
int		get_rgba(int r, int g, int b, int a);

// bresenham functions
void		bresenham(t_coord *start, t_coord *end, mlx_image_t **img);

// input functions
void		input_hook(void *fdf_param);

// error functions
void		ft_error(char *msg);

// parse functions
void		parse_fd(int fd, t_fdf **fdf);
int			parse_fdf(char *fdf_path, t_fdf **fdf);

// collision functions
void		get_bounding_box(vertex_t *start, vertex_t *end, vertex_t *bb);

// loading functions
void		loading_fdf(int tick);

// fdf	functions
void		init_fdf(t_fdf **fdf, mlx_t **mlx, mlx_image_t **img);
void		update_fdf(void *fdf_param);
void		free_fdf(t_fdf *fdf);

// coord functions
vertex_t	*init_vertex(float x, float y, float z);
void		free_coord(t_coord *coord);
t_coord		*init_coord(int x, int y, char *z_str);

// Hook functions
void		iterate_fdf(t_fdf **fdf, void (*f)(void *));
void		update_hook(void *fdf_param);
void		render_hook(void *fdf_param);
#endif
