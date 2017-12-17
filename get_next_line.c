
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

/*
** Returns 1 if c is in str. 
** In that case, update pos[0] to the position of c in str.
** Else pos[0] to 0.
*/
int c_in_str(char *str, char c, int pos[1])
{
	int i;

	i = 0;
	i = pos[0];
	while (str[i])
	{
		if (str[i] == c)
		{
			pos[0] = i;
			return(1);
		}
		i++;
	}
	pos[0] = 0;
	return(0);
}

int get_line_len(t_list *begin_list)
{
	t_list *elem;
	int len;
	int pos[1];

	len = 0;
	pos[0] = 0;
	elem = begin_list;
	while (elem)
	{
		if (c_in_str(elem->content, '\n', pos))
			len += pos[0];
		else
			len += ft_strlen(elem->content);
		elem = elem->next;
	}
	return(len);
}

void del_content(void* content, size_t n)
{
	free(content);
}

// Hint to keep only 1 static variable: keep only interesting char in buf.
// Still to do: put pos to BUFF_SIZE for EOF. 

int get_next_line(const int fd, char **line)
{
	static char buf[BUFF_SIZE + 1];
	static int pos[1];
	int line_len;
	int nb;
	t_list *begin_list;
	t_list *elem;

	begin_list = 0;
	
	// printf("Buffer at beginning: %s\n", buf);
	if (pos[0] < ft_strlen(buf))
	{
		elem = ft_lstnew(buf + pos[0], ft_strlen(buf) - pos[0]);
		ft_lstadd_end(&begin_list, elem);
	}

	nb = 0;
	while ((c_in_str(buf, '\n', pos) == 0) &&
		((nb = read(fd, buf, BUFF_SIZE)) > 0))
	{
		buf[nb] = '\0';
		elem = ft_lstnew(buf, nb + 1);
		ft_lstadd_end(&begin_list, elem);

		// printf("Buffer in while: %s\n", buf);
	}

	line_len = get_line_len(begin_list);
	*line = (char*)malloc(line_len * sizeof(char));
	*line[0] = '\0';
	elem = begin_list;
	while (elem)
	{
		// printf("Buffer in elem: %s\n", elem->content);	
		ft_strncat(*line, elem->content, line_len - ft_strlen(*line));
		elem = elem->next;
	}
	ft_lstdel(&begin_list, &del_content);
	pos[0]++;

	return (1);
}

