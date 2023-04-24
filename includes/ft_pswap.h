/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jusilanc <jusilanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 22:57:05 by jusilanc          #+#    #+#             */
/*   Updated: 2023/04/24 19:18:18 by jusilanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PSWAP_H
# define FT_PSWAP_H

# include "ft_printf.h"

enum				e_inst
{
	SA = 1,
	SB,
	RA,
	RB,
	RRA,
	RRB,
	PA,
	PB
};

typedef struct s_stack
{
	int				content;
	int				r_index;
	struct s_stack	*prev;
	struct s_stack	*next;
}					t_stack;

t_stack				*ft_pnlist_new(int content);
void				ft_pnlist_append(t_stack **stack, t_stack *new_lst);
void				ft_pnlist_addfront(t_stack **stack, t_stack *new_lst);
void				ft_pnlist_init(t_stack **lst, char **argv, int argc);
void				ft_pnlist_delone(t_stack **stack);
void				ft_pnlist_clear(t_stack **stack);

int					ft_order_check(t_stack *lst);
size_t				ft_pnlist_size(t_stack *stack);

int					ft_qs_pivot(t_stack *lst);

void				ft_swap_inst(t_stack **lst, char c);
void				ft_rev_rot_stack(t_stack **lst, char c);
void				ft_rot_stack(t_stack **lst, char c);
void				ft_push(t_stack **lst_a, t_stack **lst_b, char c);
void				ft_inst_selec(t_stack **alst, t_stack **blst, int op);

void				ft_pre_sort(t_stack **lst);
int					*ft_fill_tab(t_stack *stack);

#endif
