/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FDF.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 09:05:57 by ivmirand          #+#    #+#             */
/*   Updated: 2025/03/18 16:10:54 by ivan             ###   ########.fr       */
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

# include "MLX42.h"

# include "libft.h"
# include "ft_printf.h"
# include "get_next_line.h"

# define SCRN_WDTH 640;
# define SCRN_HGHT 480;
# define CHAR_DIMS 64;

//MLX42_Int.h does have the vertex_t struct but im not sure if i want uv data
//yet.
typedef struct s_vector3
{
	int	x;
	int	y;
	int	z;
}	t_vector3;

typedef struct s_vertex
{
	struct s_vertex	*next_x;
	struct s_vertex	*next_y;
	t_vector3		*coord;
	t_vector3		*pos;
	int				color_hex;	
}	t_vertex;

typedef struct s_fdf
{
	t_vertex	*zero_vertex;
	t_vector3	*dimensions;
	t_vector3	*origin;
	t_vector3	*scale;
}	t_fdf;

// Render functions
int		get_rgba(int r, int g, int b, int a);

// Input functions
void	input_hook(void *mlx_param);

// Error functions
void	ft_error(void);

// Parse functions
t_fdf	*parse_fdf(char *fdf_path);

// Vertex functions
t_vector3	*init_vector3(int x, int y, int z);
void		free_vertex(t_vertex *vertex);
t_vertex	*init_vertex(int x, int y, int z, int color_hex);

#endif
