/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jusilanc <jusilanc@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 22:57:09 by jusilanc          #+#    #+#             */
/*   Updated: 2023/04/20 23:30:47 by jusilanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pswap.h"

static void	ft_error(int err)
{
	if (err == 1)
		ft_printf("Invalid number of arguments\n");
	exit(err);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	t_stack	*ptr;

	if (argc < 2)
		ft_error(1);
	ft_pnlist_init(&a, argv, argc);
	ptr = a;
	ft_printf("[%d]", ptr->content);
	ptr = ptr->next;
	// remplissage de la stack a avec les argv -> ok
	// free de toute la stack a apres usage -> ok
	ft_pnlist_clear(&a);
	b = NULL;
	(void)b;
	return (0);
}
