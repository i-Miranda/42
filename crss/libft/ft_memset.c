/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 12:08:28 by ivmirand          #+#    #+#             */
/*   Updated: 2024/09/17 12:51:54 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t n)
{
	size_t	i;
	unsigned char *ptr;

	i = 0;
	ptr = (unsigned char *)b;
	while (i < n)
	{
		ptr[i] = c;
		i++;
	}
	return (b);
}
