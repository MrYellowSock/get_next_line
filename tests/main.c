#include <stdlib.h>
#include <string.h>
#include "../get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#define LEN 1

int main()
{
	char *str;
	char files[LEN][30] = {
		"tests/file.txt"
	};
	int fds[LEN];
	for(int i=0;i<LEN;i++)
	{
		fds[i] = open(files[i], O_RDONLY);
		if (fds[i] == -1)
		{
			printf("fail to open file: %s", files[i]);	
			return (-1);
		}
	}
	//read keep track of file offset position for us
	while (1) {
		for(int i=0;i<LEN;i++)
		{
			char * what = get_next_line(fds[i]);
			if(what){
				printf("%s",what);
				free(what);
			}
		}
	}
}
