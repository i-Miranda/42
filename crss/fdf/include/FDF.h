/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FDF.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 09:05:57 by ivmirand          #+#    #+#             */
/*   Updated: 2025/03/12 11:18:31 by ivan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <limits.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "libft.h"
#include "ft_printf.h"
#include "get_next_line.h"
#include "MLX42.h"

#define SCRN_WDTH 640;
#define SCRN_HGHT 480;
#define CHAR_DIMS 64;

//MLX42_Int.h does have the vertex_t struct but im not sure if i want uv data
//yet.
typedef struct s_vector3
{
	float	x;
	float	y;
	float	z;
}	t_vector3

typedef struct s_vertex
{
	t_vector3	*coord;
	t_vector3	*pos;
	int color_hex;	
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
char	*parse_fdf(char *fdf_path);
