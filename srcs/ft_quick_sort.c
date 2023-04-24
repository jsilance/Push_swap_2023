/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quick_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jusilanc <jusilanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 13:03:33 by jusilanc          #+#    #+#             */
/*   Updated: 2023/04/24 16:48:24 by jusilanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pswap.h"

size_t	ft_pnlist_size(t_stack *stack)
{
	t_stack	*ptr;
	size_t	size;

	if (!stack)
		return (0);
	ptr = stack;
	size = 1;
	stack = stack->next;
	while (ptr != stack)
	{
		stack = stack->next;
		size++;
	}
	return (size);
}

static void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

static void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (tab[i] > tab[j])
				ft_swap(&tab[i], &tab[j]);
			j++;
		}
		i++;
	}
}

int	*ft_fill_tab(t_stack *stack)
{
	size_t	size;
	int		*tab;
	size_t	i;

	i = 0;
	size = ft_pnlist_size(stack);
	tab = (int *)malloc(sizeof(int) * size);
	if (size == 0 || !tab)
		return (0);
	while (i < size)
	{
		tab[i++] = stack->content;
		stack = stack->next;
	}
	ft_sort_int_tab(tab, size);
	return (tab);
}
