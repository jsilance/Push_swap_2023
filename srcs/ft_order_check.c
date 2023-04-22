/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_order_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jusilanc <jusilanc@s19.be>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 13:18:09 by jusilanc          #+#    #+#             */
/*   Updated: 2023/04/22 13:36:26 by jusilanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pswap.h"

int	ft_order_check(t_stack *lst)
{
	t_stack	*first;

	first = lst;
	if (lst->next == first)
		return (1);
	if (lst->content > lst->next->content)
		return (0);
	lst = lst->next;
	while (lst != first && lst->next != first)
	{
		if (lst->content > lst->next->content)
			return (0);
		lst = lst->next;
	}
	return (1);
}
