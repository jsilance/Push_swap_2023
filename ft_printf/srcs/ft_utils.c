/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jusilanc <jusilanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 19:57:56 by jusilanc          #+#    #+#             */
/*   Updated: 2023/04/10 18:41:03 by jusilanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*ft_strstock(const char *s1, const char *s2, size_t len, int param)
{
	char	*ptr;
	char	*tmp;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	tmp = (char *)malloc(len + 1);
	while (s2 && s2[j] && i < len)
	{
		tmp[i++] = s2[j++];
		tmp[i] = '\0';
	}
	ptr = ft_strjoin(s1, tmp);
	if (param == 1 || param == 3)
		free((void *)s1);
	if (param == 2 || param == 3)
		free((void *)s2);
	free(tmp);
	return (ptr);
}

char	*ft_string(char *ptr, va_list *ap)
{
	char	*arg;

	arg = va_arg(*ap, char *);
	if (arg && !ft_strlen(arg) && ptr)
		return (ptr);
	else if (!ptr && arg && !ft_strlen(arg))
		return (ft_strdup(""));
	if (arg)
		ptr = ft_strstock(ptr, arg, ft_strlen(arg), 1);
	else
		ptr = ft_strstock(ptr, "(null)", 6, 1);
	return (ptr);
}

char	*ft_char(char *ptr, va_list *ap, int *ret)
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
	arg[i] = va_arg(*ap, int);
	if (arg[i] == 0)
		(*ret)++;
	free(tmp);
	return (arg);
}
