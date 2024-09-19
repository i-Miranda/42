/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 12:08:25 by ivmirand          #+#    #+#             */
/*   Updated: 2024/09/17 12:50:31 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//if dst memaddr comes before src, we can memcpy
void	*ft_memmove(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*temp_src;

	if (dst < src)
		ft_memcpy(dst, src, n);
	else
	{
		i = 0;
		temp_src = (unsigned char *)src;
		while (i < n)
		{
			((unsigned char *)dst)[i] = temp_src[i];
			i++;
		}
	}
	return (dst);
}
