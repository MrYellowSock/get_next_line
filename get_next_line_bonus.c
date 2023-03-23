/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skulkamt <skulkamt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 17:16:14 by skulkamt          #+#    #+#             */
/*   rpdated: 2023/03/23 21:00:14 by skulkamt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	max(size_t a, size_t b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

void	mayalloc(t_vec *a)
{
	char	*newone;
	size_t	new_size;

	if (a->buff == NULL || a->offset + BUFFER_SIZE >= a->size)
	{
		new_size = max(a->size * 2, BUFFER_SIZE) + 1;
		newone = malloc(new_size);
		if (newone)
		{
			newone[0] = 0;
			if (a->buff)
				ft_strcpy(newone, a->buff);
			a->size = new_size;
		}
		else
		{
			a->size = 0;
			a->offset = 0;
		}
		free(a->buff);
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
		return (NULL);
	else if (readsize == 0)
	{
		if (vec->offset > 0)
		{
			ret = ft_strdup(vec->buff);
			vec->offset = 0;
			return (ret);
		}
		vec->size = 0;
		free(vec->buff);
		vec->buff = NULL;
		return (NULL);
	}
	vec->offset += readsize;
	return (get_next_line(fd));
}

char	*get_next_line(int fd)
{
	static t_vec	vecs[4097];
	char			*temp;
	size_t			retsize;
	t_vec			*vec;

	if (fd < 0)
		return (NULL);
	vec = &vecs[fd];
	temp = NULL;
	if (vec->buff != NULL)
		temp = ft_strchr(vec->buff, '\n');
	if (temp != NULL)
	{
		retsize = temp - vec->buff + 1;
		temp = malloc(retsize + 1);
		if (temp)
		{
			ft_memcpy(temp, vec->buff, retsize);
			temp[retsize] = 0;
			ft_strcpy(vec->buff, vec->buff + retsize);
			vec->offset -= retsize;
		}
		return (temp);
	}
	return (cont(vec, fd));
}
