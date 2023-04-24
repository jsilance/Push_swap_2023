/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pnlist_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jusilanc <jusilanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 21:54:53 by jusilanc          #+#    #+#             */
/*   Updated: 2023/04/24 19:18:09 by jusilanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pswap.h"

t_stack	*ft_pnlist_new(int content)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->content = content;
	stack->r_index = 0;
	stack->prev = stack;
	stack->next = stack;
	return (stack);
}

void	ft_pnlist_addfront(t_stack **stack, t_stack *new_lst)
{
	t_stack	*lst;

	if (!stack || !*stack)
	{
		*stack = new_lst;
		return ;
	}
	lst = *stack;
	lst->prev->next = new_lst;
	new_lst->prev = lst->prev;
	lst->prev = new_lst;
	new_lst->next = lst;
	*stack = new_lst;
}

void	ft_pnlist_append(t_stack **stack, t_stack *new_lst)
{
	t_stack	*lst;

	if (!stack || !*stack)
	{
		*stack = new_lst;
		return ;
	}
	lst = *stack;
	lst->prev->next = new_lst;
	new_lst->prev = lst->prev;
	lst->prev = new_lst;
	new_lst->next = lst;
}

void	ft_pnlist_delone(t_stack **stack)
{
	t_stack	*ptr;

	if (!stack || !*stack)
		return ;
	ptr = *stack;
	if (ptr == ptr->next)
	{
		free(ptr);
		*stack = NULL;
		return ;
	}
	*stack = ptr->next;
	(ptr->prev)->next = ptr->next;
	(ptr->next)->prev = ptr->prev;
	free(ptr);
}

void	ft_pnlist_clear(t_stack **stack)
{
	t_stack	*ptr;

	ptr = *stack;
	if (!stack || !*stack)
		return ;
	while (ptr)
		ft_pnlist_delone(&ptr);
	*stack = NULL;
}

void	ft_pnlist_init(t_stack **lst, char **argv, int argc)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		ft_pnlist_append(lst, ft_pnlist_new(ft_atoi(argv[i++])));
	}
}
