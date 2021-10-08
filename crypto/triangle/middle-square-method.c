#include <stdio.h>
#include <sodium.h>
#include <math.h>
#include <string.h>
#include <stdint.h>

uint64_t seed = 0;

void init_seed() {
	uint64_t x = (uint64_t) randombytes_random();
	uint64_t y = (uint64_t) randombytes_random();
	seed = (x << 32) + y;
	return;
}

uint64_t getDigits(uint64_t number, double start, double end) {
	return (number % lround(pow(10, end)))/lround(pow(10, start-1));
}

uint64_t nextRand() {
	seed = getDigits(seed, 5, 12);
	seed *= seed;
	return seed;
}

void print_flag() {
	FILE *f = fopen("flag", "r");
	char flag[108];
	fgets(flag, sizeof(flag), f);
	printf("%s\n", flag);
	return;
}

int main()
{
	setvbuf(stdout, NULL, _IONBF, 0);
	
	char chs[100];

	init_seed();

	printf("\n triangle ! triangle ! triangle ! \n");
	printf("1. print next number\n");
	printf("2. cat flag\n");
	printf("3. quit\n");

	while(1) {
		printf(">>> ");
		fgets(chs, sizeof(chs), stdin);
		chs[strcspn(chs, "\n")] = 0;

		if(!strcmp("1", chs)) {
			uint64_t x = nextRand();
			printf("%lu\n", x);
		}
		
		if(!strcmp("2", chs)) {
			printf("\nLet's guess the next three random numbers.\nWhat's next number?\n> ");
			uint64_t number = 0;
			fgets(chs, sizeof(chs), stdin);
			sscanf(chs, "%lu", &number);
			if(number == nextRand()) {
				printf("\nCurrect, What's next number?\n> ");
			}
			else {
				printf("\nNah...\n");
				break;
			}
			number = 0;
			fgets(chs, sizeof(chs), stdin);
			sscanf(chs, "%lu", &number);
			if(number == nextRand()) {
				printf("\nCurrect, What's next number?\n> ");
			}
			else {
				printf("\nTry again...\n");
				break;
			}
			number = 0;
			fgets(chs, sizeof(chs), stdin);
			sscanf(chs, "%lu", &number);
			if(number == nextRand()) {
				printf("\nCongratulation! Here the flag!\n");
				print_flag();
				break;
			}
			else {
				printf("\nNice try, but it's wrong number, try again...\n");
				break;
			}
		}

		if(!strcmp("3", chs)) {
			printf("\nBye!\n");
			break;
		}
	}
	return 0;
}
