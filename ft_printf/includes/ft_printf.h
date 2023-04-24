/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jusilanc <jusilanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 02:13:23 by jusilanc          #+#    #+#             */
/*   Updated: 2023/04/24 12:55:19 by jusilanc         ###   ########.fr       */
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
}			t_arg;

int			ft_printf(const char *str, ...);
int			ft_string(va_list *ap);
int			ft_char(va_list *ap);
int			ft_int(va_list *ap);
int			ft_uint(va_list *ap);
int			ft_percent(void);
int			ft_hex_min(va_list *ap);
int			ft_hex_maj(va_list *ap);
int			ft_pointer(va_list *ap);

#endif
