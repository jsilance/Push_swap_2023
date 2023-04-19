/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jusilanc <jusilanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 00:53:56 by jusilanc          #+#    #+#             */
/*   Updated: 2023/04/10 13:47:54 by jusilanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_intlen(int n)
{
	unsigned int	count_len;

	count_len = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n /= 10;
		count_len++;
	}
	return (count_len);
}

static int	ft_uintlen(unsigned int n)
{
	unsigned int	count_len;

	count_len = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n /= 10;
		count_len++;
	}
	return (count_len);
}

static char	*ft_strrev(char *str)
{
	int		size;
	int		count;
	char	tmp;

	count = 0;
	size = ft_strlen((char *)str) - 1;
	while (size > count)
	{
		tmp = str[count];
		str[count++] = str[size];
		str[size--] = tmp;
	}
	return ((char *)str);
}

char	*ft_itoa(int nb)
{
	int		count;
	long	n;
	char	*str;

	count = 0;
	n = nb;
	str = malloc(sizeof(char) * (ft_intlen(n) + (n < 0) + 1));
	if (!str)
		return (NULL);
	if (n < 0)
		str[ft_intlen(n)] = '-';
	if (n < 0)
		n = -n;
	if (n == 0)
		str[count++] = '0';
	while (n)
	{
		str[count++] = 48 + (n % 10);
		n /= 10;
	}
	if (str[count] == '-')
		count++;
	str[count] = '\0';
	str = ft_strrev((char *)str);
	return (str);
}

char	*ft_utoa(unsigned int nb)
{
	int		count;
	long	n;
	char	*str;

	count = 0;
	n = nb;
	str = malloc(sizeof(char) * (ft_uintlen(n) + 1));
	if (!str)
		return (NULL);
	if (n == 0)
		str[count++] = '0';
	while (n)
	{
		str[count++] = 48 + (n % 10);
		n /= 10;
	}
	str[count] = '\0';
	str = ft_strrev((char *)str);
	return (str);
}
