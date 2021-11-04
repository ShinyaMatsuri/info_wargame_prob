#include <stdio.h>
#include <stdlib.h>

void lemon_tree()
{
	printf("Do you want a SPECIAL LEMON ?\n");
	system("/bin/sh");
}

int binit()
{
	setvbuf(stdout, 0, 2, 0);
	setvbuf(stdin, 0, 2, 0);
	return setvbuf(stderr, 0, 2, 0);
}

int main(void)
{
	binit();

	char buf[52];
	
	printf("lemon!\n");
	fgets(buf, 256, stdin);

	return 0;
}
