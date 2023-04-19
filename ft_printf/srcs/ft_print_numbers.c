/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jusilanc <jusilanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 18:40:31 by jusilanc          #+#    #+#             */
/*   Updated: 2023/04/10 18:41:11 by jusilanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*ft_int(char *ptr, va_list *ap)
{
	char	*arg;

	arg = ft_itoa(va_arg(*ap, int));
	ptr = ft_strstock(ptr, arg, ft_strlen(arg), 3);
	return (ptr);
}

char	*ft_uint(char *ptr, va_list *ap)
{
	char	*arg;

	arg = ft_utoa(va_arg(*ap, int));
	ptr = ft_strstock(ptr, arg, ft_strlen(arg), 3);
	return (ptr);
}
