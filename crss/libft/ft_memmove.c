/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 12:08:25 by ivmirand          #+#    #+#             */
/*   Updated: 2024/09/28 23:03:35 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	const unsigned char	*temp_src;

	if (dst == NULL && src == NULL)
		return (NULL);
	temp_src = (unsigned char *)src;
	if (dst < src)
		return (ft_memcpy(dst, src, len));
	while (len--)
		((unsigned char *)dst)[len] = temp_src[len];
	return (dst);
}
