/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lesanche <lesanche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 13:55:51 by lesanche          #+#    #+#             */
/*   Updated: 2018/01/03 10:53:52 by lesanche         ###   ########.fr       */
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

void	ft_free_b_list(t_list **b_list)
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

int		ft_get_line_from_list(t_list *b_list, char **line, t_list *el)
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
	ft_free_b_list(&b_list);
	return (0);
}

int		get_next_line(const int fd, char **line)
{
	static char		b[BUFF_SIZE + 1];
	int				nb;
	t_list			*b_list;
	t_list			*el;

	b_list = 0;
	if (fd < 0)
		return (-1);
	while (1)
	{
		ft_lstadd_end(&b_list, ft_lstnew(b, BUFF_SIZE + 1));
		if (ft_strchr(b, '\n') || (nb = read(fd, b, BUFF_SIZE)) == 0
			|| nb == -1)
			break ;
		b[nb] = '\0';
	}
	el = b_list;
	if (nb == -1 || ft_get_line_from_list(b_list, line, el) == -1)
		return (-1);
	if ((int)ft_strlen(b) == 1 && b[0] == '\n')
		b[0] = '\0';
	else if (nb < BUFF_SIZE && ft_strlen(*line) == 0 && ft_strlen(b) == 0)
		return (0);
	ft_shift_str_until(b, '\n');
	return (1);
}
