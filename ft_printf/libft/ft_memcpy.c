/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jusilanc <jusilanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 12:36:30 by jusilanc          #+#    #+#             */
/*   Updated: 2023/04/03 16:56:57 by jusilanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*dest;
	unsigned char	*str;
	size_t			i;

	i = -1;
	dest = (unsigned char *)dst;
	str = (unsigned char *)src;
	if (!n || dest == src)
		return (dest);
	while (dest && str && ++i < n)
		dest[i] = str[i];
	return (dest);
}
