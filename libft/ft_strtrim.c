/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lesanche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 10:28:31 by lesanche          #+#    #+#             */
/*   Updated: 2017/11/22 15:09:21 by lesanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_create_and_fill_new_s(char const *s, int size, int i)
{
	int		ctr;
	char	*new_s;

	ctr = 0;
	new_s = (char *)malloc(sizeof(*new_s) * (size + 1));
	if (new_s == NULL)
		return (NULL);
	while (ctr < size && s[i] != '\0')
	{
		new_s[ctr] = s[i];
		i++;
		ctr++;
	}
	new_s[ctr] = '\0';
	return (new_s);
}

char		*ft_strtrim(char const *s)
{
	int		i;
	int		j;
	int		size;
	char	*new_s;

	if (s == NULL)
		return (NULL);
	i = 0;
	j = ft_strlen(s) - 1;
	while ((s[i] == ' ' || s[i] == '\n' || s[i] == '\t') && s[i])
		i++;
	while ((s[j] == ' ' || s[j] == '\n' || s[j] == '\t') && j >= 0)
		j--;
	size = j - i + 1;
	if (size <= 0)
		size = 0;
	new_s = ft_create_and_fill_new_s(s, size, i);
	return (new_s);
}
