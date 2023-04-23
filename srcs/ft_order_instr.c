/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_order_instr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jusilanc <jusilanc@s19.be>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 15:12:27 by jusilanc          #+#    #+#             */
/*   Updated: 2023/04/23 15:58:57 by jusilanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pswap.h"

void	ft_swap_inst(t_stack **lst, char c)
{
	t_stack	*a;
	t_stack	*b;

	a = *lst;
	if (a == NULL)
		return ;
	if (ft_pnlist_size(a) == 1)
		return ;
	else if (ft_pnlist_size(a) > 1)
	{
		*lst = a->next;
		a->prev->next = a->next;
		a->prev = a->next;
		a->next->prev = a->prev;
		a->next = a->next->next;
	}
	// *lst = a->prev;
	// not fonctionnal here
	ft_printf("r%c\n", c);
}
