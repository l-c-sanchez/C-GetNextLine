#include "get_next_line.h"

void	ft_lstadd_end(t_list **begin_list, t_list *n)
{
	t_list *l;
	l = *begin_list;

	if (l == NULL)
	{
		*begin_list = n;
		return;
	}
	while (l->next)
		l = l->next;
	l->next = n;
}


int ft_shift_str_until(char *str, char c)
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
		return(1);	
	}
	while(str[i+1+j] != '\0')
	{
		str[j] = str[i + 1 + j]; 
		j++;
	}
	str[j] = '\0';
	return(0);
}

int get_line_len(t_list *begin_list)
{
	t_list *elem;
	int len;
	int i;
	char *str;

	len = 0;
	elem = begin_list;
	while (elem)
	{
		str = elem->content;
		i = 0;
		while (str[i] && (str[i] != '\n'))
			i++;
		len += i;
		elem = elem->next;
	}
	return(len);
}

int only_c_in_str(char *str, char c)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != c)
			return(0);
		i++;
	}
	return(1);
}


void del_content(void* content, size_t n)
{
	n++;
	free(content);
}

// Hint to keep only 1 static variable: keep only interesting char in buf.
// Still to do: put pos to BUFF_SIZE for EOF. 

int get_next_line(const int fd, char **line)
{
	static char buf[BUFF_SIZE + 1];
	int line_len;
	int nb;
	t_list *begin_list;
	t_list *elem;

	begin_list = 0;
	if (fd < 0)
		return(-1);
	nb = 0;
	while (1)
	{
		elem = ft_lstnew(buf, BUFF_SIZE + 1);
		ft_lstadd_end(&begin_list, elem);
		if (ft_strchr(buf, '\n'))
			break;
		nb = read(fd, buf, BUFF_SIZE);
		if (nb == -1)
			return(-1);
		buf[nb] = '\0';
		if (nb == 0)
			break;
	}
	if (nb == -1)
		return(-1);
	line_len = get_line_len(begin_list);
	*line = (char*)malloc((line_len) * sizeof(char));
	*line[0] = '\0';
	elem = begin_list;
	while (elem)
	{
		ft_strncat(*line, elem->content, line_len - ft_strlen(*line));
		elem = elem->next;
	}
	ft_lstdel(&begin_list, &del_content);
	ft_shift_str_until(buf, '\n');
	if ((nb < BUFF_SIZE) && (ft_strlen(*line) == 0) && only_c_in_str(buf, '\n'))
		return(0);
	return (1);
}


