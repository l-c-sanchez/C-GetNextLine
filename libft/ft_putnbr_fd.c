/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lesanche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 16:49:42 by lesanche          #+#    #+#             */
/*   Updated: 2017/11/21 18:29:01 by lesanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long long	print_n;

	print_n = n;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		print_n = (print_n) * (-1);
	}
	if (print_n >= 0 && print_n <= 9)
		ft_putchar_fd(print_n + '0', fd);
	else
	{
		ft_putnbr_fd(print_n / 10, fd);
		ft_putnbr_fd(print_n % 10, fd);
	}
}
