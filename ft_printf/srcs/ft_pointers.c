/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jusilanc <jusilanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 23:38:26 by jusilanc          #+#    #+#             */
/*   Updated: 2023/04/20 18:33:01 by jusilanc         ###   ########.fr       */
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

int	ft_pointer(va_list *ap)
{
	char	*arg;
	int		ret;

	arg = ft_ulltohex(va_arg(*ap, unsigned long long), "0123456789abcdef");
	ret = write(1, "0x", 2);
	ret += write(1, arg, ft_strlen(arg));
	free(arg);
	return (ret);
}
