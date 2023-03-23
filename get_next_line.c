#include "get_next_line.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))
typedef struct
{
	char			*buffer;
	size_t			realsize;
}  minivec;

void	mayalloc(minivec *a)
{
	char	*newone;
	size_t	new_size;

	if (a->buffer == NULL || ft_strlen(a->buffer) + BUFFER_SIZE >= a->realsize)
	{
		new_size = MAX(a->realsize * 2, BUFFER_SIZE) + 1;
		newone = malloc(new_size);
		if (newone)
		{
			newone[0] = 0;
			if(a->buffer)
				memcpy(newone, a->buffer, a->realsize);
			a->realsize = new_size;
		}
		else
		{
			a->realsize = 0;
		}
		free(a->buffer);
		a->buffer = newone;
	}
}

ssize_t	get_next_string(int fd, char *read_buf)
{
	ssize_t	totalRead;

	totalRead = read(fd, read_buf, BUFFER_SIZE);
	if (totalRead >= 0)
		read_buf[totalRead] = '\0';
	return (totalRead);
}

char	*get_next_line(int fd)
{
	static minivec	vec = {NULL,0};

	mayalloc(&vec);
	if(!vec.buffer)
		return (NULL);

	const char * next_end = ft_strchr(vec.buffer, '\n');
	if (next_end){
		size_t retsize = next_end - vec.buffer + 1;
		char * ret = malloc(retsize + 1);
		if(ret)
		{
			memcpy(ret, vec.buffer, retsize);
			ret[retsize] = 0;
			memmove(vec.buffer, vec.buffer + retsize , vec.realsize - retsize);
		}
		return ret;
	}
	else if(vec.buffer) {
		size_t current_len = ft_strlen(vec.buffer);
		ssize_t readsize = get_next_string(fd, vec.buffer + current_len);
		if(readsize < 0)
			return NULL;
		else if(readsize == 0)
		{
			if(current_len > 0){
				char * ret = strdup(vec.buffer);
				vec.buffer[0] = 0;
				return ret;
			}
		}
		else {
			return get_next_line(fd);
		}
	}
	return NULL;
}
