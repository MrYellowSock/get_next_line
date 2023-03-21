#include <unistd.h>

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

// READ BUFFER SIZE
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4096
# endif

# ifndef MAX_LINE_SIZE
#  define MAX_LINE_SIZE 2097152
# endif

char *get_next_line(int fd);

#endif
