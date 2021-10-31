#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

void haa(void)
{
	puts("haa!");
}

void hee(void)
{
	puts("hee!");
}

void hoo(void)
{
	puts("hoo!");
}

void math_test(void)
{
	int a,b;
	int n;
	int i;

	for(i=0; i<100; i++) {
		a = rand()%100;
		b = rand()%100;
		printf("%d + %d = ", a, b);
		scanf("%d", &n);
		if(n!=a+b) exit(0);
		puts("correct!");
	}
}

void func(void)
{
	char chance[64]="here the input chance!";
	char buf;
	
	puts(chance);
	read(0, &buf, 256);
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
	
	srand((unsigned int)time(NULL));

	int n;

	puts("1. haa");
	puts("2. hee");
	puts("3. hoo");
	
	printf("input : ");

	scanf("%d", &n);

	if(n==1) haa();
	if(n==2) hee();
	if(n==3) hoo();

	else if(n>0 && n<10000) {
		if((n+4)*10-(n+100)==9633) {
			puts("here the hidden text, \"huu!\"");
			puts("here the math test!");
			
			math_test();
			
			puts("here the hidden text \"hii!\"");
			func();
		}
	}
}
