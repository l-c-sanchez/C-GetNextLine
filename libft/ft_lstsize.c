/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lesanche <lesanche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 16:57:19 by lesanche          #+#    #+#             */
/*   Updated: 2017/11/22 17:18:29 by lesanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_lstsize(t_list *alst)
{
	t_list	*tmp;
	int		i;

	if (alst == NULL)
		return (0);
	i = 0;
	tmp = alst;
	while (tmp->next)
	{
		i++;
		tmp = tmp->next;
	}
	if (tmp->next == NULL)
		i++;
	return (i);
}
