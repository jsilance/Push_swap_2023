/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_order_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jusilanc <jusilanc@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 13:18:09 by jusilanc          #+#    #+#             */
/*   Updated: 2023/04/26 00:44:00 by jusilanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pswap.h"

int	ft_ptrlen(char **ptr)
{
	int	i;

	i = 0;
	while (ptr && *ptr++)
		i++;
	return (i);
}

int	ft_order_check(t_stack *lst)
{
	t_stack	*first;

	first = lst;
	if (lst->next == first)
		return (1);
	if (lst->r_index > lst->next->r_index)
		return (0);
	lst = lst->next;
	while (lst != first && lst->next != first)
	{
		if (lst->r_index > lst->next->r_index)
			return (0);
		lst = lst->next;
	}
	return (1);
}
