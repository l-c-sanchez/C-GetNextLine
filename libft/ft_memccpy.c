/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lesanche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 17:57:06 by lesanche          #+#    #+#             */
/*   Updated: 2017/11/27 10:08:04 by lesanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*c_dest;
	unsigned char	*c_src;
	unsigned char	c_c;

	i = 0;
	c_src = (unsigned char*)src;
	c_dest = (unsigned char*)dest;
	c_c = (unsigned char)c;
	while (i < n)
	{
		c_dest[i] = c_src[i];
		if (c_c == c_dest[i])
			return (c_dest + i + 1);
		i++;
	}
	return (NULL);
}
