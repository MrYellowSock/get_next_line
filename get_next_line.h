#include <stdlib.h>
#include <unistd.h>
#include <stddef.h>

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

// READ BUFFER SIZE
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# ifndef MAX_LINE_SIZE
#  define MAX_LINE_SIZE 2097152
# endif

char	*ft_strjoin(char const *s1, char const *s2);
char *get_next_line(int fd);
char	*ft_strchr(const char *s, int c);

#endif
