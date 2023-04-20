/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jusilanc <jusilanc@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 22:57:05 by jusilanc          #+#    #+#             */
/*   Updated: 2023/04/20 23:31:18 by jusilanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PSWAP_H
# define FT_PSWAP_H

# include "ft_printf.h"

typedef struct s_stack
{
	int				content;
	struct s_stack	*prev;
	struct s_stack	*next;
}					t_stack;

t_stack				*ft_pnlist_new(int content);
void				ft_pnlist_append(t_stack **stack, t_stack *new_lst);
void				ft_pnlist_init(t_stack **lst, char **argv, int argc);
void				ft_pnlist_delone(t_stack **stack);
void				ft_pnlist_clear(t_stack **stack);

#endif
