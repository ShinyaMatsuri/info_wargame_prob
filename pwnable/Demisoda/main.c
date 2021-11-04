#include <stdio.h>
#include <unistd.h>
#include <string.h>

int x;

int binit()
{
	setvbuf(stdout, 0, 2, 0);
	setvbuf(stdin, 0, 2, 0);
	return setvbuf(stderr, 0, 2, 0);
}

int main(void)
{
	binit();

	char ans[500];

	memset(ans, 0, 500);

	printf("hey hey hey!\n");
	printf("Do you like [Demisoda]?\n\n");
	printf("1. yes    2. yes\n");
	
	scanf("%d", &x);

	if(x==1 || x==2) {
		printf("here the [Demisoda]!!!!");
		return 0;
	}

	printf("wrong input! what are you doing?\n");

	read(0, &ans, 505);

	printf("what is %s", ans);

	printf("\n\nWait, you hate [Demisoda]?\n");

	read(0, &ans, 1024);

	printf("\ntoo late! get out of here!!!!!\n");

	return 0;
}
