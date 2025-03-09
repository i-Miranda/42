/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FDF.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 09:05:57 by ivmirand          #+#    #+#             */
/*   Updated: 2025/03/08 19:33:19 by ivan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "MLX42.h"

#define SCRN_WDTH 640;
#define SCRN_HGHT 480;
#define CHAR_DIMS 64;

// Input functions
void	input_hook(void *mlx_param);

// Error functions
void	ft_error(void);

// Render functions
int	get_rgba(int r, int g, int b, int a);
