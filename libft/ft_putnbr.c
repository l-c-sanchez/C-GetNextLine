/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lesanche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 18:46:50 by lesanche          #+#    #+#             */
/*   Updated: 2017/11/21 18:27:46 by lesanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	long long print_n;

	print_n = n;
	if (n < 0)
	{
		ft_putchar('-');
		print_n = (print_n) * (-1);
	}
	if (print_n >= 0 && print_n <= 9)
		ft_putchar(print_n + '0');
	else
	{
		ft_putnbr(print_n / 10);
		ft_putnbr(print_n % 10);
	}
}
