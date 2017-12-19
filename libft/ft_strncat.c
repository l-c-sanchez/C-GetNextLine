/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lesanche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 15:53:45 by lesanche          #+#    #+#             */
/*   Updated: 2017/11/27 09:37:28 by lesanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	size_t i;
	size_t j;
	size_t k;

	k = 0;
	j = 0;
	i = 0;
	while (dest[k] != '\0')
		k++;
	while ((src[i] != '\0') && (j < n))
	{
		dest[k + i] = src[i];
		i++;
		j++;
	}
	dest[k + i] = '\0';
	return (dest);
}
