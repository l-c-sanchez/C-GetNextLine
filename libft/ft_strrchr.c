/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lesanche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 16:39:27 by lesanche          #+#    #+#             */
/*   Updated: 2017/11/27 10:04:36 by lesanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strrchr(const char *s, int c)
{
	char	*c_s;
	char	c_c;

	c_s = (char *)s;
	c_c = (char)c;
	while (*c_s != '\0')
		c_s++;
	while (*c_s != c_c)
	{
		if (c_s == s)
			return (NULL);
		c_s--;
	}
	return ((char *)c_s);
}
