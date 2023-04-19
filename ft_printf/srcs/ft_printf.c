/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jusilanc <jusilanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 18:06:13 by jusilanc          #+#    #+#             */
/*   Updated: 2023/04/10 16:24:36 by jusilanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	ft_strintchr(const char *s, char c)
{
	int	i;

	i = 0;
	while (s && s[i])
		if (s[i++] == c)
			return (i - 1);
	return (-1);
}

static char	*ft_func_selector(char *ptr, va_list *ap, char type, int *ret)
{
	if (type == 's')
		ptr = ft_string(ptr, ap);
	else if (type == 'c')
		ptr = ft_char(ptr, ap, ret);
	else if (type == 'd' || type == 'i')
		ptr = ft_int(ptr, ap);
	else if (type == 'u')
		ptr = ft_uint(ptr, ap);
	else if (type == 'x')
		ptr = ft_hex_min(ptr, ap);
	else if (type == 'X')
		ptr = ft_hex_maj(ptr, ap);
	else if (type == '%')
		ptr = ft_percent(ptr);
	else if (type == 'p')
		ptr = ft_pointer(ptr, ap);
	return (ptr);
}

static char	*flag_processing(char *ptr, char **str, va_list *ap, int *ret)
{
	char	type;

	(*str)++;
	if (ft_strchr("cspdiuxX%", **str))
		type = "cspdiuxX%"[ft_strintchr("cspdiuxX%", **str)];
	else
		return (0);
	(*str)++;
	if (type == -1)
		return (NULL);
	ptr = ft_func_selector(ptr, ap, type, ret);
	return (ptr);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	char	*ptr;
	int		ret;

	if (!str || !*str)
		return (0);
	va_start(ap, str);
	ptr = 0;
	ret = 0;
	while (*str)
	{
		while (*str && *str != '%')
			ptr = ft_strstock(ptr, str++, 1, 1);
		if (*str && *str == '%')
			ptr = flag_processing(ptr, (char **)&str, &ap, &ret);
	}
	if (!ptr)
		ret = -1;
	if (ret != -1)
		write(1, ptr, ft_strlen(ptr));
	if (ret > -1)
		ret += ft_strlen(ptr);
	free(ptr);
	va_end(ap);
	return (ret);
}
