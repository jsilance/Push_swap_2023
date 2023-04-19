/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jusilanc <jusilanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 12:47:49 by jusilanc          #+#    #+#             */
/*   Updated: 2023/04/03 16:59:21 by jusilanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*dest;
	unsigned char	*str;

	if (!dst && !src)
		return (NULL);
	dest = (unsigned char *)dst;
	str = (unsigned char *)src;
	if (dst < src)
		ft_memcpy(dst, src, len);
	else if (src && dst > src)
		while (len-- > 0)
			dest[len] = str[len];
	return (dst);
}
