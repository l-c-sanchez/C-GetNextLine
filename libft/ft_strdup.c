/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lesanche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 11:36:34 by lesanche          #+#    #+#             */
/*   Updated: 2017/11/27 09:57:45 by lesanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		i;
	int		size;
	char	*new_s;

	i = 0;
	size = 0;
	while (s[size] != '\0')
		size++;
	new_s = (char*)malloc(sizeof(*new_s) * (size + 1));
	if (new_s == NULL)
		return (NULL);
	while (i < size)
	{
		new_s[i] = s[i];
		i++;
	}
	new_s[i] = '\0';
	return (new_s);
}
