/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lesanche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 10:42:38 by lesanche          #+#    #+#             */
/*   Updated: 2017/11/27 09:38:57 by lesanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*c_s;
	int		i;

	i = 0;
	c_s = (char *)s;
	if (c == '\0')
		return ((char *)(c_s + ft_strlen(c_s)));
	while (*c_s != '\0')
	{
		if (*c_s == c)
			return ((char *)c_s);
		c_s++;
	}
	return (NULL);
}
