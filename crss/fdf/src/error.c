/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 09:23:33 by ivmirand          #+#    #+#             */
/*   Updated: 2025/03/08 09:24:55 by ivan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FDF.h"

void	ft_error(void)
{
	fprintf(stderr, "%s\n", mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

