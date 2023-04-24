/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pre_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jusilanc <jusilanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 13:05:15 by jusilanc          #+#    #+#             */
/*   Updated: 2023/04/24 19:28:01 by jusilanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pswap.h"

static int	ft_intchr(int *tab, int content, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		if (tab[i] == content)
			return (i + 1);
		i++;
	}
	return (-1);
}

void	ft_pre_sort(t_stack **lst)
{
	t_stack	*to_sort;
	size_t	i;
	int		*tab;

	if (!lst || !*lst)
		return ;
	to_sort = *lst;
	i = 0;
	while (i <= ft_pnlist_size(to_sort))
	{
		tab = ft_fill_tab(*lst);
		to_sort->r_index = ft_intchr(tab, to_sort->content,
				ft_pnlist_size(to_sort));
		to_sort = to_sort->next;
		i++;
	}
	free(tab);
}
