/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lesanche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 18:00:03 by lesanche          #+#    #+#             */
/*   Updated: 2017/11/27 09:54:13 by lesanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*c_src;
	unsigned char	*c_dest;

	c_src = (unsigned char*)src;
	c_dest = (unsigned char*)dest;
	if (c_src <= c_dest)
	{
		while (n--)
			c_dest[n] = c_src[n];
	}
	else
		ft_memcpy(c_dest, c_src, n);
	return (c_dest);
}
