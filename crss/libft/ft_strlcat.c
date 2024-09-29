/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 12:09:02 by ivmirand          #+#    #+#             */
/*   Updated: 2024/09/28 23:03:36 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_len;
	size_t	src_len;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (dst_len < dstsize)
	{
		if (src_len < dstsize - dst_len)
			ft_memmove(&dst[dst_len], src, src_len + 1);
		else
		{
			ft_memmove(&dst[dst_len], src, dstsize - dst_len - 1);
			dst[dstsize - 1] = '\0';
		}
		return (dst_len + src_len);
	}
	return (dstsize + src_len);
}
