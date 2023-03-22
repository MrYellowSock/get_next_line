#include "get_next_line.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

//garunteed to free the target
char	*expand(char *target, char const *addition)
{
	char	*newone;

	if (target == NULL)
		newone = strdup(addition);
	else
		newone = ft_strjoin(target, addition);
	free(target);
	return (newone);
}

// a new string from fd
// empty string if eof
// NULL on error
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
	static char	*content_buffer ;
	char	**splits;
	char	*temp;

	if (content_buffer != NULL && ft_strchr(content_buffer, '\n'))
	{
		splits = ft_split_half(content_buffer, '\n');
		free(content_buffer);
		if (!splits)
			return (NULL);
		content_buffer = splits[1];
		temp = splits[0];
		free(splits);
		return (temp);
	}
	else
	{
		temp = get_next_string(fd);
		if (!temp)
			return (NULL);
		else if (ft_strlen(temp) == 0)
		{
			free(temp);
			if (content_buffer)
			{
				if(ft_strlen(content_buffer) > 0)
				{
					temp = strdup(content_buffer);
				}
				else{	temp = NULL;}
				free(content_buffer);
				content_buffer = NULL;
				return (temp);
			}
			else
			{
				return (NULL);
			}
		}
		else
		{
			content_buffer = expand(content_buffer, temp);
			free(temp);
			if (!content_buffer)
				return (NULL);
			return (get_next_line(fd));
		}
	}
}
