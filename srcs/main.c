/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jusilanc <jusilanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 22:57:09 by jusilanc          #+#    #+#             */
/*   Updated: 2023/04/24 19:44:13 by jusilanc         ###   ########.fr       */
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
		printf("%d:%d", a->content, a->r_index);
		a = a->next;
	}
	if (b)
	{
		printf("% 10d:%d", b->content, b->r_index);
		b = b->next;
	}
	printf("\n");
	while (a != ptra || b != ptrb)
	{
		if (a != ptra)
		{
			printf("%d:%d", a->content, a->r_index);
			a = a->next;
		}
		if (b != ptrb)
		{
			printf("% 10d:%d", b->content, b->r_index);
			b = b->next;
		}
		printf("\n");
	}
	printf("\n\n");
}

int	main(int argc, char **argv)
{
	t_stack		*a;
	t_stack		*b;
	size_t		i;
	size_t		j;
	long long	nb;

	nb = 1;
	if (argc < 2)
		ft_error(1);
	a = NULL;
	b = NULL;
	ft_pnlist_init(&a, argv, argc);
	ft_pre_sort(&a);
	i = ft_pnlist_size(a);
	while (!ft_order_check(a) && nb > 0)
	{
		j = 0;
		while (j++ < i)
		{
			if (a->r_index)
				ft_printf("[%d]:[%d] & [%d]\n", a->content, a->r_index, nb);
			if (a->r_index & nb)
				ft_inst_selec(&a, &b, PB);
			ft_inst_selec(&a, &b, RA);
		}
		while (ft_pnlist_size(b))
			ft_inst_selec(&a, &b, PA);
		nb = nb << 1;
		ft_printf("\n");
	}
	if (ft_order_check(a))
		ft_printf("la lsite est dans l'ordre\n");
	else
		ft_printf("la lsite n'est pas dans l'ordre\n");
	ft_pnlist_print(a, b);
	// ft_pnlist_print(a, b);
	// ft_pnlist_clear(&a);
	b = NULL;
	(void)b;
	return (0);
}
