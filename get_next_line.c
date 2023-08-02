/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skulkamt <skulkamt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 17:16:14 by skulkamt          #+#    #+#             */
/*   Updated: 2023/08/02 10:37:30 by skulkamt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>

void	purge(t_vec *vec)
{
	free(vec->buff);
	vec->buff = NULL;
	vec->size = 0;
	vec->offset = 0;
}

void	mayalloc(t_vec *a)
{
	char	*newone;
	size_t	new_size;

	if (a->buff == NULL || a->offset + BUFFER_SIZE >= a->size)
	{
		new_size = a->size * 2;
		if (BUFFER_SIZE > new_size)
			new_size = BUFFER_SIZE;
		new_size = new_size + 1;
		newone = malloc(new_size);
		if (newone)
		{
			newone[0] = 0;
			if (a->buff)
				_strcpy(newone, a->buff);
			a->size = new_size;
			free(a->buff);
		}
		else
			purge(a);
		a->buff = newone;
	}
}

ssize_t	get_next_string(int fd, char *read_buf)
{
	ssize_t	totalread;

	totalread = read(fd, read_buf, BUFFER_SIZE);
	if (totalread >= 0)
		read_buf[totalread] = '\0';
	return (totalread);
}

char	*cont(t_vec *vec, int fd)
{
	char	*ret;
	ssize_t	readsize;

	mayalloc(vec);
	if (!vec->buff)
		return (NULL);
	readsize = get_next_string(fd, vec->buff + vec->offset);
	if (readsize < 0)
	{
		purge(vec);
		return (NULL);
	}
	else if (readsize == 0)
	{
		if (vec->offset > 0)
		{
			ret = _strdup(vec->buff);
			vec->offset = 0;
			return (ret);
		}
		purge(vec);
		return (NULL);
	}
	vec->offset += readsize;
	return (get_next_line(fd));
}

char	*get_next_line(int fd)
{
	static t_vec	vec;
	char			*next_end;
	size_t			retsize;
	char			*ret;

	if (fd < 0)
		return (NULL);
	next_end = NULL;
	if (vec.buff != NULL)
		next_end = _strchr(vec.buff, '\n');
	if (next_end != NULL)
	{
		retsize = next_end - vec.buff + 1;
		ret = malloc(retsize + 1);
		if (ret)
		{
			_memcpy(ret, vec.buff, retsize);
			ret[retsize] = 0;
			_strcpy(vec.buff, vec.buff + retsize);
			vec.offset -= retsize;
		}
		return (ret);
	}
	return (cont(&vec, fd));
}
