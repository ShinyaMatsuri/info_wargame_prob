#include <stdio.h>
#include <unistd.h>

void func(void)
{
	char name[48];
	
	puts("what's your name?");
	read(0, name, 256);
}

int main(void)
{
	func();
}
