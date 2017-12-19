#include "get_next_line.h"

int main(int argc, char **argv)
{
 	int fd;
    char *line;

	if ((argc < 2) || (argc < 2))
	{
		write(1, "usage: get_next_line[valid file]\n", 26);
		return(-1);
	}
	fd = open(argv[1], O_RDONLY);

	int i;
	i = 0;
	while (i < 10)
	{
		if (get_next_line(fd, &line) == 1)
			printf("voici la ligne %d : %s\n", i, line);
		i++;
	}

    close (fd);
    return (0);
}