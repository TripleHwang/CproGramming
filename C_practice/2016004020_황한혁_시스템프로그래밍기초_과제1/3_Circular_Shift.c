#include <stdio.h>

void print_bin(unsigned x) {
	const int SIZE = sizeof(x) * 8;
	printf("decimal : %u\n", x);
	printf("binary : ");
	for (int i = 0; i < SIZE; i++)
		printf("%c", (x >> (SIZE - i - 1) & 1) + 48);
	printf("\n");
}

unsigned circular_shift(unsigned x, int n) {
	int num = n;
	int bitnum;
	const int SIZE = sizeof(x) * 8;
	for (int i = 0; i < num; i++) {
		bitnum = (x >> (SIZE - 1) & 1);
		x = x << 1;
		x += bitnum;
	}
	return x;
}

int main() {
	unsigned x = 25;  
	print_bin(x);   
	print_bin(circular_shift(x, 30));    
	return 0;
}