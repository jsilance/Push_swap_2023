/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_other_sorter.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jusilanc <jusilanc@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 01:21:18 by jusilanc          #+#    #+#             */
/*   Updated: 2023/04/25 02:59:46 by jusilanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pswap.h"

static void	ft_simple_sort(t_stack **a, t_stack **b, int param)
{
	t_stack	*ptr;

	ptr = *a;
	if (param == SB)
		ptr = *b;
	if (param == SA && ptr->r_index > ptr->next->r_index)
		ft_inst_selec(a, b, param);
	else if (param == SB && ptr->r_index < ptr->next->r_index)
		ft_inst_selec(a, b, param);
}

void	ft_triple_sort(t_stack **a, t_stack **b)
{
	t_stack	*ptr;

	ptr = *a;
	if (ft_order_check(ptr))
		return ;
	if (ptr->r_index > ptr->next->r_index)
	{
		if (ptr->r_index > ptr->prev->r_index)
			ft_inst_selec(a, b, RRA);
		ft_simple_sort(a, b, SA);
	}
	else if (ptr->r_index < ptr->next->r_index
			&& ptr->r_index > ptr->prev->r_index)
		ft_inst_selec(a, b, RA);
	else if (ptr->r_index < ptr->next->r_index
			&& ptr->r_index < ptr->prev->r_index)
	{
		ft_inst_selec(a, b, RA);
		ft_inst_selec(a, b, SA);
	}
}

static void	ft_hard_code_insert(t_stack **a, t_stack **b)
{
	if ((*b)->r_index == 5)
	{
		ft_inst_selec(a, b, PA);
		ft_inst_selec(a, b, RRA);
	}
	else if ((*b)->r_index == 4)
	{
		ft_inst_selec(a, b, RA);
		ft_inst_selec(a, b, PA);
		ft_inst_selec(a, b, RRA);
		ft_inst_selec(a, b, RRA);
	}
	else
	{
		while ((*a)->r_index < (*b)->r_index)
			ft_inst_selec(a, b, RRA);
		ft_inst_selec(a, b, PA);
		while ((*a)->r_index > (*b)->r_index)
			ft_inst_selec(a, b, RA);
		ft_inst_selec(a, b, PA);
	}
}

void	ft_five_sort(t_stack **a, t_stack **b)
{
	t_stack	*ptr;

	ptr = *a;
	if (ft_order_check(ptr))
		return ;
	ft_inst_selec(a, b, PB);
	ft_inst_selec(a, b, PB);
	ft_triple_sort(a, b);
	ft_simple_sort(a, b, SB);
	ft_hard_code_insert(a, b);
}
