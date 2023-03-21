#include "get_next_line.h"
#include <stdlib.h>
#include <sys/_types/_ssize_t.h>
#include <unistd.h>

char	*get_next_line(int fd)
{
	char	*read_buf;

	read_buf = malloc(BUFFER_SIZE + 1);
	if (!read_buf)
		return (NULL);
	ssize_t totalRead = read(fd, read_buf, BUFFER_SIZE);
}
