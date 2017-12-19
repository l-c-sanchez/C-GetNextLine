/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lesanche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 18:05:56 by lesanche          #+#    #+#             */
/*   Updated: 2017/11/27 09:08:29 by lesanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	size_t i;
	size_t j;
	size_t k;

	i = 0;
	if (needle[i] == '\0')
		return ((char*)haystack);
	while (haystack[i] != '\0' && i < n)
	{
		j = 0;
		k = i;
		while (haystack[i] == needle[j] && (i < n))
		{
			if (needle[j + 1] == '\0')
				return ((char *)haystack + k);
			i++;
			j++;
		}
		i = k;
		i++;
	}
	return (NULL);
}
