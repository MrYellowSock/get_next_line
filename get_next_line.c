#include "get_next_line.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

//garunteed to free the target
void	expand(char **target, char const *addition)
{
	char	*newone;

	newone = ft_strjoin(*target, addition);
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
	char		**splits;
	char		*recent;
	char		*ret;

	if (content_buffer == NULL)
		content_buffer = malloc(0);
	while (content_buffer != NULL && ft_strchr(content_buffer, '\n') == NULL)
	{
		recent = get_next_string(fd);
		expand(&content_buffer, recent);
		free(recent);
		if (!content_buffer)
			return (NULL);
	}
	splits = ft_split_half(content_buffer, '\n');
	free(content_buffer);
	if (!splits)
		return (NULL);
	content_buffer = splits[1];
	ret = splits[0];
	free(splits);
	return (ret);
}
