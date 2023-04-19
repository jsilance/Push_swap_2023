/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jusilanc <jusilanc@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 02:13:23 by jusilanc          #+#    #+#             */
/*   Updated: 2023/04/10 01:53:01 by jusilanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <stdarg.h>

typedef struct s_arg
{
	char	type;
	char	*str;
}	t_arg;

int		ft_printf(const char *str, ...);
char	*ft_strstock(const char *s1, const char *s2, size_t len, int param);
char	*ft_string(char *ptr, va_list *ap);
char	*ft_char(char *ptr, va_list *ap, int *ret);
char	*ft_int(char *ptr, va_list *ap);
char	*ft_uint(char *ptr, va_list *ap);
char	*ft_percent(char *ptr);
char	*ft_hex_min(char *ptr, va_list *ap);
char	*ft_hex_maj(char *ptr, va_list *ap);
char	*ft_pointer(char *ptr, va_list *ap);

#endif
