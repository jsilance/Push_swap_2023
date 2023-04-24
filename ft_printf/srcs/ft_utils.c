/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jusilanc <jusilanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 19:57:56 by jusilanc          #+#    #+#             */
/*   Updated: 2023/04/20 19:05:28 by jusilanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_string(va_list *ap)
{
	char	*arg;

	arg = va_arg(*ap, char *);
	if (arg && !ft_strlen(arg))
		return (0);
	if (arg)
		return (write(1, arg, ft_strlen(arg)));
	return (write(1, "(null)", 6));
}

int	ft_char(va_list *ap)
{
	char	c;

	c = va_arg(*ap, int);
	return (write(1, &c, 1));
}
