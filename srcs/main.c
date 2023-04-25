/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jusilanc <jusilanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 22:57:09 by jusilanc          #+#    #+#             */
/*   Updated: 2023/04/25 12:47:16 by jusilanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pswap.h"

void	ft_error(int err)
{
	if (err == 1)
		ft_printf("Error\n");
	exit(err);
}

static void	ft_radis_x(t_stack **alst, t_stack **blst)
{
	size_t		i;
	size_t		j;
	long long	nb;

	nb = 1;
	i = ft_pnlist_size(*alst);
	while (!ft_order_check(*alst) && nb > 0)
	{
		j = 0;
		while (j++ < i && !ft_order_check(*alst))
		{
			if (!((*alst)->r_index & nb))
				ft_inst_selec(alst, blst, PB);
			else
				ft_inst_selec(alst, blst, RA);
		}
		while (ft_pnlist_size(*blst))
			ft_inst_selec(alst, blst, PA);
		nb = nb << 1;
	}
}

static char	**ft_duty_free(char **ptr_ptr, int words)
{
	int	i;

	i = 0;
	if (!ptr_ptr)
		return (NULL);
	while (ptr_ptr[i] && i < words)
		free((void *)ptr_ptr[i++]);
	free((void **)ptr_ptr);
	return (NULL);
}

static void	ft_pre_check(int argc, char **argv, t_stack **a)
{
	char	**ptr;

	if (argc == 2)
	{
		ptr = ft_split(argv[0], ' ');
		if (!ptr)
			ft_error(1);
		if (ft_nb_verif(ptr, ft_ptrlen(ptr)))
		{
			ft_duty_free(ptr, ft_ptrlen(ptr));
			ft_error(1);
		}
		ft_pnlist_init(a, ptr, ft_ptrlen(ptr));
		ft_duty_free(ptr, ft_ptrlen(ptr));
	}
	else
	{
		if (ft_nb_verif(argv, argc - 1))
			ft_error(1);
		ft_pnlist_init(a, argv, argc);
	}
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (argc < 2)
		ft_error(1);
	ft_pre_check(argc, &argv[1], &a);
	b = NULL;
	if (ft_pre_sort(&a) == -1)
	{
		ft_pnlist_clear(&a);
		ft_error(1);
	}
	if (ft_pnlist_size(a) <= 3)
		ft_triple_sort(&a, &b);
	else if (ft_pnlist_size(a) <= 5)
		ft_five_sort(&a, &b);
	else
		ft_radis_x(&a, &b);
	ft_pnlist_clear(&a);
	return (0);
}
