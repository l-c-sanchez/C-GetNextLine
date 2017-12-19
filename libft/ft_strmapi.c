/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lesanche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 18:17:26 by lesanche          #+#    #+#             */
/*   Updated: 2017/11/21 17:59:55 by lesanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*new_s;
	int		i;
	int		size;

	i = 0;
	if (s != NULL && f != NULL)
	{
		size = ft_strlen(s);
		new_s = (char *)(malloc(sizeof(char) * (size + 1)));
		if (new_s == NULL)
			return (NULL);
		while (s[i])
		{
			new_s[i] = f(i, s[i]);
			i++;
		}
		new_s[i] = '\0';
		return (new_s);
	}
	return (0);
}
