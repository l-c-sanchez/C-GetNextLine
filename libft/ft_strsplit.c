/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lesanche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 14:05:05 by lesanche          #+#    #+#             */
/*   Updated: 2017/11/26 19:38:53 by lesanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nb_words(char const *s, char c)
{
	int	nb_words;
	int	i;

	nb_words = 0;
	i = 0;
	while (s[i])
	{
		if (i == 0 && s[i] != c)
			nb_words++;
		else if (s[i] == c && s[i + 1] != c && s[i + 1] != '\0')
			nb_words++;
		i++;
	}
	return (nb_words);
}

static int	ft_new_word(char const *s, size_t i, char c)
{
	int beginning;

	beginning = 0;
	if ((i == 0 && s[i] != c) || (s[i] != c && s[i - 1] == c))
		beginning = 1;
	if (s[i] == '\0')
		beginning = 0;
	return (beginning);
}

static char	*ft_fill_tab(char const *s, int i, size_t j)
{
	char	*new_s;
	size_t	ctr;

	ctr = 0;
	new_s = (char *)malloc(sizeof(*new_s) * (j + 1));
	if (new_s == NULL)
		return (NULL);
	while (ctr < j && s[i] != '\0')
	{
		new_s[ctr] = s[i];
		i++;
		ctr++;
	}
	new_s[ctr] = '\0';
	return (new_s);
}

static char	**ft_tab(char **tab, char const *s, char c)
{
	int i;
	int j;
	int w;

	i = 0;
	w = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		j = 0;
		if (ft_new_word(s, i, c) == 1)
		{
			while (s[i + j] != c && s[i + j] != '\0')
				j++;
			tab[w] = ft_fill_tab(s, i, j);
			w++;
			i += j;
		}
	}
	tab[w] = 0;
	return (tab);
}

char		**ft_strsplit(char const *s, char c)
{
	int		words;
	char	**tab;

	if (s == NULL)
		return (NULL);
	words = ft_nb_words(s, c);
	tab = (char **)malloc(sizeof(char *) * (words + 1));
	if (tab == NULL)
		return (NULL);
	tab = ft_tab(tab, s, c);
	return (tab);
}
