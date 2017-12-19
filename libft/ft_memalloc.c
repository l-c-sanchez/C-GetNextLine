/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lesanche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 11:12:46 by lesanche          #+#    #+#             */
/*   Updated: 2017/11/22 18:30:34 by lesanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char	*new_memory;
	size_t	i;

	i = 0;
	new_memory = (char*)malloc(sizeof(*new_memory) * (size));
	if (new_memory == 0)
		return (NULL);
	while (i < size)
	{
		new_memory[i] = 0;
		i++;
	}
	return ((void*)new_memory);
}
