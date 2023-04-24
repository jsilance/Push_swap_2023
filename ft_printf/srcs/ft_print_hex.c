/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jusilanc <jusilanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 16:53:15 by jusilanc          #+#    #+#             */
/*   Updated: 2023/04/20 18:29:21 by jusilanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	ft_inthexlen(unsigned int nb)
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

static char	*ft_itohex(unsigned int nbr, char *base)
{
	char	*ptr;
	int		i;

	ptr = (char *)calloc(sizeof(char), ft_inthexlen(nbr) + 1);
	if (!ptr)
		return (NULL);
	if (nbr == 0)
	{
		ptr[0] = base[0];
		return (ptr);
	}
	i = ft_inthexlen(nbr) - 1;
	while (nbr)
	{
		ptr[i--] = base[nbr % 16];
		nbr /= 16;
	}
	return (ptr);
}

int	ft_hex_min(va_list *ap)
{
	char	*arg;
	int		ret;

	arg = ft_itohex(va_arg(*ap, int), "0123456789abcdef");
	ret = write(1, arg, ft_strlen(arg));
	free(arg);
	return (ret);
}

int	ft_hex_maj(va_list *ap)
{
	char	*arg;
	int		ret;

	arg = ft_itohex(va_arg(*ap, int), "0123456789ABCDEF");
	ret = write(1, arg, ft_strlen(arg));
	free(arg);
	return (ret);
}

int	ft_percent(void)
{
	return (write(1, "%", 1));
}
