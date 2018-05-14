#include<stdio.h>

int main(void) {

	unsigned char x = 0;

	printf("--> Testing printBin() <---\n");
	printBin(x+1);
	printBin(x+2);
	printBin(x+4);
	printBin(x+8);
	printBin(x+16);
	printBin(x+32);
	printBin(x+64);
	printBin(x+128);
}
