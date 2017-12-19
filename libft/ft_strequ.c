/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lesanche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 11:33:56 by lesanche          #+#    #+#             */
/*   Updated: 2017/11/22 18:12:53 by lesanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strequ(char const *s1, char const *s2)
{
	int result;

	if (s1 != NULL && s2 != NULL)
	{
		result = ft_strcmp(s1, s2);
		if (result != 0)
			return (0);
		if (result == 0)
			return (1);
	}
	return (0);
}
