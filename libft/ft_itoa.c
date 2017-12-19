/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lesanche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 10:12:15 by lesanche          #+#    #+#             */
/*   Updated: 2017/11/24 10:46:51 by lesanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_find_size(int n, int add_neg)
{
	int size;

	size = add_neg;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n = n / 10;
		size++;
	}
	return (size);
}

static char		*ft_fill_new_s(char *new_s, int size, int n, int add_neg)
{
	int		i;

	i = 0;
	while (i < size + 1)
	{
		new_s[i] = '\0';
		i++;
	}
	new_s[size] = '\0';
	size--;
	while (size >= 0)
	{
		new_s[size] = n % 10 + '0';
		n = n / 10;
		size--;
	}
	if (add_neg == 1)
		new_s[0] = '-';
	return (new_s);
}

char			*ft_itoa(int n)
{
	char		*new_s;
	int			add_neg;
	int			size;

	add_neg = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n < 0)
		add_neg = 1;
	size = ft_find_size(n, add_neg);
	if (add_neg == 1)
		n = n * (-1);
	new_s = (char *)malloc(sizeof(*new_s) * (size + 1));
	if (new_s == 0)
		return (NULL);
	new_s = ft_fill_new_s(new_s, size, n, add_neg);
	return (new_s);
}
