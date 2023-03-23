#include "../get_next_line.h"
#include <stdio.h>

void test(char * str, char sep)
{
	char ** out = ft_split_half(str,sep);
	printf("input:%s\n",str);
	printf("%s|\n",out[0]);
	printf("%s|\n",out[1]);
}

int main ()
{
	test("abc;def", ';');
	//ft_strchr(NULL, '\n');
	free(NULL);
	test("abc;;def", ';');
	test(";abc;def", ';');
	test(";abcdef", ';');
	test("abcdef;", ';');
	test("abcdef", ';');
	test(";", ';');
	test(";;", ';');
	return 0;
}
