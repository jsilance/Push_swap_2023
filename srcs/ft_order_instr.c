/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_order_instr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jusilanc <jusilanc@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 15:12:27 by jusilanc          #+#    #+#             */
/*   Updated: 2023/04/24 02:58:01 by jusilanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pswap.h"

void	ft_swap_inst(t_stack **lst, char c)
{
	int		tmp;
	t_stack	*ptr;

	ptr = *lst;
	if (!lst || !*lst)
		return ;
	if (ft_pnlist_size(ptr) == 1)
		return ;
	else if (ft_pnlist_size(ptr) > 1)
	{
		tmp = ptr->content;
		ptr->content = ptr->next->content;
		ptr->next->content = tmp;
	}
	ft_printf("s%c\n", c);
}

void	ft_rot_stack(t_stack **lst, char c)
{
	t_stack	*ptr;

	if (!lst || !*lst)
		return ;
	ptr = *lst;
	ptr = ptr->next;
	ft_printf("r%c\n", c);
}

void	ft_rev_rot_stack(t_stack **lst, char c)
{
	t_stack	*ptr;

	if (!lst || !*lst)
		return ;
	ptr = *lst;
	ptr = ptr->prev;
	*lst = ptr;
	ft_printf("rr%c\n", c);
}

void	ft_push(t_stack **lst_a, t_stack **lst_b, char c)
{
	//add front et surtout pas append refaire la finction mais dans l'autre sens *-*
	// et proteger les fonctions pour ne pas crash si la liste est vide
	ft_pnlist_append(lst_b, ft_pnlist_new((*lst_a)->content));
	ft_pnlist_delone(lst_a);
	ft_printf("p%c\n", c);
}

void	ft_inst_selec(t_stack **alst, t_stack **blst, int op)
{
	if (op == SA)
		ft_swap_inst(alst, 'a');
	else if (op == SB)
		ft_swap_inst(blst, 'b');
	else if (op == RA)
		ft_rot_stack(alst, 'a');
	else if (op == RB)
		ft_rot_stack(blst, 'b');
	else if (op == RRA)
		ft_rev_rot_stack(alst, 'a');
	else if (op == RRB)
		ft_rev_rot_stack(blst, 'b');
	else if (op == PA)
		ft_push(blst, alst, 'a');
	else if (op == PB)
		ft_push(alst, blst, 'b');
}
