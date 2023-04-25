/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gestion_error.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jusilanc <jusilanc@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 00:42:35 by jusilanc          #+#    #+#             */
/*   Updated: 2023/04/25 00:44:54 by jusilanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pswap.h"

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
		i++;
	}
	return (0);
}
