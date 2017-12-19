/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lesanche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 16:39:45 by lesanche          #+#    #+#             */
/*   Updated: 2017/11/27 09:25:55 by lesanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	char			*c_s;
	unsigned char	c_c;

	i = 0;
	c_s = (char *)(s);
	c_c = (unsigned char)c;
	while (i < n)
	{
		c_s[i] = c_c;
		i++;
	}
	return (c_s);
}
