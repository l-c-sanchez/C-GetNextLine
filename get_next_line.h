

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
#define BUFF_SIZE 25

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# include "../libft/libft.h"

# include <stdio.h>

int get_next_line(const int fd, char **line);

#endif 

