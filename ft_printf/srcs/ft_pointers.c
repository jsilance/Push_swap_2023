/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jusilanc <jusilanc@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 23:38:26 by jusilanc          #+#    #+#             */
/*   Updated: 2023/04/10 01:18:15 by jusilanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	ft_ullhexlen(unsigned long long nb)
{
	int	i;

	i = 0;
	if (nb == 0)
		return (1);
	while (nb)
	{
		nb /= 16;
		i++;
	}
	return (i);
}

static char	*ft_ulltohex(unsigned long long nbr, char *base)
{
	char	*ptr;
	int		i;

	ptr = (char *)calloc(sizeof(char), ft_ullhexlen(nbr) + 1);
	if (!ptr)
		return (NULL);
	if (nbr == 0)
	{
		ptr[0] = base[0];
		return (ptr);
	}
	i = ft_ullhexlen(nbr) - 1;
	while (nbr)
	{
		ptr[i--] = base[nbr % 16];
		nbr /= 16;
	}
	return (ptr);
}

char	*ft_pointer(char *ptr, va_list *ap)
{
	char	*arg;

	arg = ft_ulltohex(va_arg(*ap, unsigned long long), "0123456789abcdef");
	ptr = ft_strstock(ptr, "0x", 2, 1);
	ptr = ft_strstock(ptr, arg, ft_strlen(arg), 3);
	return (ptr);
}
