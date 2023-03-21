#include "get_next_line.h"
#include <stdlib.h>
#include <sys/_types/_ssize_t.h>
#include <unistd.h>

char	*expand(char *target, char const *addition)
{
	char	*newone;

	newone = ft_strjoin(target, addition);
	free(target);
	return (newone);
}

// a new string from fd
char	*get_next_string(int fd)
{
	char	*read_buf;
	ssize_t	totalRead;

	read_buf = malloc(BUFFER_SIZE + 1);
	if (!read_buf)
		return (NULL);
	totalRead = read(fd, read_buf, BUFFER_SIZE);
	if (totalRead < 0)
	{
		free(read_buf);
		return (NULL);
	}
	read_buf[totalRead] = '\0';
	return (read_buf);
}

char	*get_next_line(int fd)
{
	static char	*content_buffer;
	char		*next_end;
	char		*start;

	//initialize
	if (content_buffer == NULL)
	{
		content_buffer = malloc(0);
	}
	// newline exists in buffer : reuse them
	next_end = ft_strchr(content_buffer, '\n');
	if (next_end != NULL)
	{

	}
	return (content_buffer);
}
