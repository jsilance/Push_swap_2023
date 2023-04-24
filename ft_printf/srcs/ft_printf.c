/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jusilanc <jusilanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 18:06:13 by jusilanc          #+#    #+#             */
/*   Updated: 2023/04/20 19:15:40 by jusilanc         ###   ########.fr       */
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

static int	ft_func_selector(va_list *ap, char type)
{
	int	ret;

	ret = -1;
	if (type == 's')
		ret = ft_string(ap);
	else if (type == 'c')
		ret = ft_char(ap);
	else if (type == 'd' || type == 'i')
		ret = ft_int(ap);
	else if (type == 'u')
		ret = ft_uint(ap);
	else if (type == 'x')
		ret = ft_hex_min(ap);
	else if (type == 'X')
		ret = ft_hex_maj(ap);
	else if (type == '%')
		ret = ft_percent();
	else if (type == 'p')
		ret = ft_pointer(ap);
	return (ret);
}

static int	flag_processing(char **str, va_list *ap)
{
	char	type;
	int		ret;

	ret = 0;
	(*str)++;
	if (ft_strchr("cspdiuxX%", **str))
		type = "cspdiuxX%"[ft_strintchr("cspdiuxX%", **str)];
	else
		return (0);
	(*str)++;
	if (type == -1)
		return (-1);
	ret = ft_func_selector(ap, type);
	return (ret);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		ret;
	int		i;

	if (!str)
		return (0);
	va_start(ap, str);
	ret = 0;
	i = 0;
	while (*str)
	{
		i = 0;
		while (str[i] && str[i] != '%')
			i++;
		write(1, str, i);
		str += i;
		ret += i;
		if (*str && *str == '%')
			ret += flag_processing((char **)&str, &ap);
	}
	va_end(ap);
	return (ret);
}
