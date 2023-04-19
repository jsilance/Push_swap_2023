/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jusilanc <jusilanc@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 16:53:15 by jusilanc          #+#    #+#             */
/*   Updated: 2023/04/10 01:18:18 by jusilanc         ###   ########.fr       */
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

char	*ft_hex_min(char *ptr, va_list *ap)
{
	char	*arg;

	arg = ft_itohex(va_arg(*ap, int), "0123456789abcdef");
	ptr = ft_strstock(ptr, arg, ft_strlen(arg), 3);
	return (ptr);
}

char	*ft_hex_maj(char *ptr, va_list *ap)
{
	char	*arg;

	arg = ft_itohex(va_arg(*ap, int), "0123456789ABCDEF");
	ptr = ft_strstock(ptr, arg, ft_strlen(arg), 3);
	return (ptr);
}

char	*ft_percent(char *ptr)
{
	char	*arg;
	size_t	i;
	char	*tmp;

	i = 0;
	tmp = ptr;
	arg = ft_calloc(ft_strlen(ptr) + 2, sizeof(char));
	if (!arg)
		return (0);
	while (ptr && *ptr)
		arg[i++] = *ptr++;
	arg[i] = '%';
	free(tmp);
	return (arg);
}
