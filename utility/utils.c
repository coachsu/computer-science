#include<stdio.h>

void printBin(unsigned char uc) {
	unsigned char mask = 1;

	printf("0b");

	int i;

	for(i=7;i>=0;i--) {
		unsigned char tmp = uc;
		tmp = tmp >> i;
		tmp = tmp & mask;
		printf("%d",tmp);
	}
	printf("\n");
}
