/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jusilanc <jusilanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 18:40:31 by jusilanc          #+#    #+#             */
/*   Updated: 2023/04/20 18:37:50 by jusilanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	ft_intlen(long nb)
{
	int	ret;

	ret = 0;
	if (nb == 0)
		return (1);
	if (nb < 0)
		ret++;
	while (nb)
	{
		nb /= 10;
		ret++;
	}
	return (ret);
}

int	ft_int(va_list *ap)
{
	int	arg;

	arg = va_arg(*ap, int);
	ft_putnbr_fd(arg, 1);
	return (ft_intlen(arg));
}

int	ft_uint(va_list *ap)
{
	char	*arg;
	int		ret;

	arg = ft_utoa(va_arg(*ap, unsigned int));
	ret = write(1, arg, ft_strlen(arg));
	free(arg);
	return (ret);
}
