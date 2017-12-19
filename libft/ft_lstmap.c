/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lesanche <lesanche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 15:14:36 by lesanche          #+#    #+#             */
/*   Updated: 2017/11/22 15:22:17 by lesanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new_lst;
	t_list	*new_lst_save;

	if (lst == NULL || f == NULL)
		return (NULL);
	new_lst = (t_list*)malloc(sizeof(t_list));
	if (new_lst == NULL)
		return (NULL);
	new_lst = (*f)(lst);
	new_lst_save = new_lst;
	while (lst->next)
	{
		lst = lst->next;
		new_lst->next = (t_list*)malloc(sizeof(t_list));
		if (new_lst->next == NULL)
		{
			free(new_lst);
			return (NULL);
		}
		new_lst->next = f(lst);
		new_lst = new_lst->next;
	}
	new_lst->next = NULL;
	return (new_lst_save);
}
