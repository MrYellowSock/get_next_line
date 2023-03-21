#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#define LEN 1

int main()
{
	char *str;
	char files[LEN][30] = {
		"file.txt"
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
	for(int i=0;i<LEN;i++)
	{
		char * test = malloc(40);
		read(fds[i], test,40);
		printf("%s",test);
	}
	for(int i=0;i<LEN;i++)
	{
		char * test = malloc(40);
		read(fds[i], test,40);
		printf("%s",test);
	}
	for(int i=0;i<LEN;i++)
	{
		char * test = malloc(40);
		read(fds[i], test,40);
		printf("%s",test);
	}
}

