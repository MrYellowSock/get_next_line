#include "get_next_line.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void	expand(char **target, char const *addition)
{
	char	*newone;

	newone = ft_strjoin(*target, addition);
	if (*target)
		free(*target);
	*target = newone;
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
	if (totalRead <= 0)
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
	char		**splits;
	char		*recent;

	//initialize
	if (content_buffer == NULL)
		content_buffer = malloc(0);
	// newline exists in buffer : reuse them
	while (ft_strchr(content_buffer, '\n') == NULL)
	{
		recent = get_next_string(fd);
		expand(&content_buffer, recent);
		if (!content_buffer)
			return (NULL);
	}
	splits = ft_split_half(content_buffer, '\n');
	free(content_buffer);
	if (!splits)
		return (NULL);
	content_buffer = splits[1];
	return (splits[0]);
}
