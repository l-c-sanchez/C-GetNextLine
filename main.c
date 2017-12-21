/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lesanche <lesanche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 13:59:35 by lesanche          #+#    #+#             */
/*   Updated: 2017/12/21 14:46:41 by lesanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		main(int argc, char **argv)
{
	int		fd;
	char	*line;

	if ((argc < 2) || (argc < 2))
	{
		write(1, "usage: get_next_line[valid file]\n", 26);
		return (-1);
	}
	fd = open(argv[1], O_RDONLY);
	while (get_next_line(fd, &line) == 1)
	{
		printf("voici la ligne : %s\n", line);
	}
	close(fd);
	return (0);
}
