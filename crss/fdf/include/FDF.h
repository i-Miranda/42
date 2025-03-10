/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FDF.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 09:05:57 by ivmirand          #+#    #+#             */
/*   Updated: 2025/03/09 16:44:54 by ivan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "libft.h"
#include "MLX42.h"

#define SCRN_WDTH 640;
#define SCRN_HGHT 480;
#define CHAR_DIMS 64;

// Render functions
int	get_rgba(int r, int g, int b, int a);

// Input functions
void	input_hook(void *mlx_param);

// Error functions
void	ft_error(void);
