/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_other_sorter.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jusilanc <jusilanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 01:21:18 by jusilanc          #+#    #+#             */
/*   Updated: 2023/05/18 19:26:16 by jusilanc         ###   ########.fr       */
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
	t_stack	*pt;

	pt = *a;
	if (ft_order_check(pt))
		return ;
	if (pt->r_index > pt->next->r_index)
	{
		if (pt->r_index > pt->prev->r_index)
			ft_inst_selec(a, b, RA);
		ft_simple_sort(a, b, SA);
	}
	else if (pt->r_index < pt->next->r_index && pt->r_index > pt->prev->r_index)
		ft_inst_selec(a, b, RRA);
	else if (pt->r_index < pt->next->r_index && pt->r_index < pt->prev->r_index)
	{
		ft_inst_selec(a, b, RRA);
		ft_inst_selec(a, b, SA);
	}
}

static void	ft_min_dist(t_stack **a, int nb, size_t *i, size_t *j)
{
	t_stack	*ptr;

	ptr = *a;
	while (ptr->content != nb)
	{
		ptr = ptr->next;
		(*i)++;
	}
	ptr = *a;
	while (ptr->content != nb)
	{
		ptr = ptr->prev;
		(*j)++;
	}
}

static void	ft_push_min(t_stack **a, t_stack **b)
{
	size_t	i;
	size_t	j;
	int		*tab;

	tab = ft_fill_tab(*a);
	i = 0;
	j = 0;
	ft_min_dist(a, tab[0], &i, &j);
	if (i > j)
		while (j--)
			ft_inst_selec(a, b, RRA);
	else
		while (i--)
			ft_inst_selec(a, b, RA);
	ft_inst_selec(a, b, PB);
	free(tab);
}

void	ft_five_sort(t_stack **a, t_stack **b)
{
	if (ft_order_check(*a))
		return ;
	if (ft_pnlist_size(*a) == 5)
		ft_push_min(a, b);
	if (ft_pnlist_size(*a) == 4)
		ft_push_min(a, b);
	ft_triple_sort(a, b);
	while (ft_pnlist_size(*b))
		ft_inst_selec(a, b, PA);
}
