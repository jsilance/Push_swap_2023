/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jusilanc <jusilanc@s19.be>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 22:57:09 by jusilanc          #+#    #+#             */
/*   Updated: 2023/04/23 15:54:01 by jusilanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pswap.h"

static void	ft_error(int err)
{
	if (err == 1)
		ft_printf("Invalid number of arguments\n");
	exit(err);
}
#include <stdio.h>

static void	ft_pnlist_print(t_stack *a, t_stack *b)
{
	t_stack	*ptra;
	t_stack	*ptrb;

	ptra = a;
	ptrb = b;
	if (a)
	{
		printf("%d", a->content);
		a = a->next;
	}
	if (b)
	{
		printf("% 10d", b->content);
		b = b->next;
	}
	printf("\n");
	while (a != ptra || b != ptrb)
	{
		if (a != ptra)
		{
			printf("%d", a->content);
			a = a->next;
		}
		if (b != ptrb)
		{
			printf("% 10d", b->content);
			b = b->next;
		}
		printf("\n");
	}
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	t_stack	*ptr;
	int		pivot;

	if (argc < 2)
		ft_error(1);
	a = NULL;
	b = NULL;
	ft_pnlist_init(&a, argv, argc);
	ptr = a;
	ptr = ptr->next;
	if (ft_order_check(a))
		ft_printf("la lsite est dans l'ordre\n");
	else
		ft_printf("la lsite n'est pas dans l'ordre\n");
	pivot = ft_qs_pivot(a);
	ft_pnlist_print(a, b);
	ft_printf("\n\n");
	ft_swap_inst(&a, 'a');
	ft_pnlist_print(a, b);
	ft_pnlist_clear(&a);
	b = NULL;
	(void)b;
	return (0);
}
