/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gestion_error.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jusilanc <jusilanc@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 00:42:35 by jusilanc          #+#    #+#             */
/*   Updated: 2023/04/26 01:34:42 by jusilanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pswap.h"

static int	ft_is_greater_int(const char *s)
{
	long	res;
	long	sign;

	sign = 1;
	res = 0;
	if (!s)
		return (-1);
	if (*s == '+' || *s == '-')
		if (*s++ == '-')
			sign = -1;
	while (*s)
	{
		res = res * 10 + *s++ - '0';
		if ((res * sign < INT_MIN && sign < 0) || (res > INT_MAX && sign > 0))
			return (-1);
	}
	return (0);
}

int	ft_nb_verif(char **ptr, int words)
{
	int	i;
	int	j;

	i = 0;
	while (ptr && ptr[i] && i < words)
	{
		j = 0;
		while (ptr[i][j])
		{
			if (!ft_isdigit(ptr[i][j]) && ptr[i][j] != '-')
				return (1);
			j++;
		}
		if (ft_is_greater_int(ptr[i]) == -1)
			return (1);
		i++;
	}
	return (0);
}
