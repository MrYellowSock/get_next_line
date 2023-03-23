#include <stdlib.h>
#include <string.h>
#include "../get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int main(int argc, char *files[])
{
	int fd = open(files[1], O_RDONLY);
	// printf("%s fd is %d\n" ,files[1], fd);
	//read keep track of file offset position for us
	while (1) {
		char * what = get_next_line(fd);
		if(!what)
			break;
	}
		
}
