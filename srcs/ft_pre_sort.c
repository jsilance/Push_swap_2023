/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pre_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jusilanc <jusilanc@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 13:05:15 by jusilanc          #+#    #+#             */
/*   Updated: 2023/04/25 01:06:59 by jusilanc         ###   ########.fr       */
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

int	ft_pre_sort(t_stack **lst)
{
	t_stack	*to_sort;
	size_t	i;
	int		*tab;

	if (!lst || !*lst)
		return (-1);
	to_sort = *lst;
	i = 0;
	tab = ft_fill_tab(*lst);
	if (!tab)
	{
		ft_pnlist_clear(lst);
		return (-1);
	}
	while (i <= ft_pnlist_size(to_sort))
	{
		to_sort->r_index = ft_intchr(tab, to_sort->content,
				ft_pnlist_size(to_sort));
		to_sort = to_sort->next;
		i++;
	}
	free(tab);
	return (0);
}
