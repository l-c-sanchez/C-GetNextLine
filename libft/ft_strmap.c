/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lesanche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 17:26:35 by lesanche          #+#    #+#             */
/*   Updated: 2017/11/22 14:31:48 by lesanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*new_s;
	int		i;
	int		size;

	i = 0;
	if (s != NULL && f != NULL)
	{
		size = ft_strlen(s);
		new_s = (char *)(malloc(sizeof(*new_s) * (size + 1)));
		if (new_s == NULL)
			return (NULL);
		while (s[i])
		{
			new_s[i] = f(s[i]);
			i++;
		}
		new_s[i] = '\0';
		return (new_s);
	}
	return (0);
}
