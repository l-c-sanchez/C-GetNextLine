/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lesanche <lesanche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 13:55:51 by lesanche          #+#    #+#             */
/*   Updated: 2017/12/27 11:03:56 by lesanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_lstadd_end(t_list **begin_list, t_list *n)
{
	t_list *l;

	l = *begin_list;
	if (l == NULL)
	{
		*begin_list = n;
		return ;
	}
	while (l->next)
		l = l->next;
	l->next = n;
}

int		ft_shift_str_until(char *str, char c)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (str[i] && str[i] != c)
		i++;
	if (i + 1 >= (int)ft_strlen(str))
	{
		str[0] = '\0';
		return (1);
	}
	while (str[i + 1 + j] != '\0')
	{
		str[j] = str[i + 1 + j];
		j++;
	}
	str[j] = '\0';
	return (0);
}

void	ft_lstdel_bis(t_list **b_list)
{
	t_list	*n;

	while (*b_list != NULL)
	{
		n = (*b_list)->next;
		free((*b_list)->content);
		ft_memdel((void **)b_list);
		*b_list = n;
	}
}

int		get_line_from_list(t_list *b_list, char **line, t_list *el)
{
	int		line_len;
	char	*str;
	int		i;

	line_len = 0;
	while (el)
	{
		str = el->content;
		i = 0;
		while (str[i] && (str[i] != '\n'))
			i++;
		line_len += i;
		el = el->next;
	}
	if ((*line = (char*)malloc((line_len + 1) * sizeof(char))) == NULL)
		return (-1);
	el = b_list;
	*line[0] = '\0';
	while (el)
	{
		ft_strncat(*line, el->content, line_len - ft_strlen(*line));
		el = el->next;
	}
	ft_lstdel_bis(&b_list);
	return (0);
}

int		get_next_line(const int fd, char **line)
{
	static char		buf[BUFF_SIZE + 1];
	int				nb;
	t_list			*b_list;
	t_list			*el;

	b_list = 0;
	while (1)
	{
		ft_lstadd_end(&b_list, ft_lstnew(buf, BUFF_SIZE + 1));
		if (ft_strchr(buf, '\n') || (nb = read(fd, buf, BUFF_SIZE)) == 0)
			break ;
		if (nb == -1 || fd < 0)
			return (-1);
		buf[nb] = '\0';
	}
	el = b_list;
	if (get_line_from_list(b_list, line, el) == -1)
		return (-1);
	if ((int)ft_strlen(buf) == 1 && buf[0] == '\n')
		buf[0] = '\0';
	else if ((nb < BUFF_SIZE) && (ft_strlen(*line) == 0)
			&& (ft_strlen(buf) == 0))
		return (0);
	ft_shift_str_until(buf, '\n');
	return (1);
}
