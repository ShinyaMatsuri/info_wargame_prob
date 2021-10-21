#include <stdio.h>
#include <unistd.h>

void func(void)
{
	char name[48];
	
	puts("what's your name?");
	read(0, name, 256);
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
	puts("welcome to ROP world");
	func();
}
