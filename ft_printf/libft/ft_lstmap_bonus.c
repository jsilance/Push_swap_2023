/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jusilanc <jusilanc@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 02:30:53 by jusilanc          #+#    #+#             */
/*   Updated: 2023/04/05 03:06:03 by jusilanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*ptr_lst;
	t_list	*ptr_new;

	if (!lst || !f || !del)
		return (NULL);
	ptr_lst = ft_lstnew(f(lst->content));
	if (!(ptr_lst))
		return (NULL);
	lst = lst->next;
	while (lst)
	{
		ptr_new = ft_lstnew(f(lst->content));
		if (!(ptr_new))
		{
			ft_lstclear(&ptr_new, del);
			return (NULL);
		}
		ft_lstadd_back(&ptr_lst, ptr_new);
		lst = lst->next;
	}
	return (ptr_lst);
}
