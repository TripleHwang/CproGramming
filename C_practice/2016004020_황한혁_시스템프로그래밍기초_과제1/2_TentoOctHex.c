#include <stdio.h> 

void print_bin(unsigned x) {
	const int SIZE = sizeof(x) * 8; 
	printf("decimal : %u\n", x); 
	printf("binary : "); 
	for (int i = 0; i < SIZE; i++) 
		printf("%c", (x >> (SIZE - i - 1) & 1) + 48); 
	printf("\n"); 
}

void print_oct(unsigned x) {
	int controlnum = 0;
	const int SIZE = sizeof(x) * 8;
	char eightnum[11];
	printf("decimal : %u\n", x);
	printf("octal : ");
	for (int i = 0; i < SIZE; i+=3, controlnum++) {
		if (i == 0) {
			eightnum[controlnum] = ((x >> (SIZE - 1) & 1) * 2) + (x >> (SIZE - 2) & 1)+48;
		}
		else{
			eightnum[controlnum] = ((x >> (SIZE - i) & 1) * 4) + ((x >> (SIZE - i-1) & 1) * 2) + (x >> (SIZE - i -2) & 1)+48;
		}
	}
	for (int i = 0; i < controlnum; i++)
		printf("%c", eightnum[i]);
	printf("\n");
}

void print_hex(unsigned x) {
	int controlnum = 0;
	int nownum;
	const int SIZE = sizeof(x) * 8;
	char hexnum[7];
	char overten[6] = { 'A', 'B', 'C', 'D', 'E', 'F' };
	printf("decimal : %u\n", x);
	printf("hex : ");
	for (int i = 0; i < SIZE; i += 4, controlnum++) {
		nownum =((x >> (SIZE - i - 1 ) & 1) * 8) + ((x >> (SIZE - i - 2) & 1) * 4) + ((x >> (SIZE - i - 3) & 1) * 2) + (x >> (SIZE - i - 4) & 1);
		if (nownum >= 10) {
			hexnum[controlnum] = overten[nownum - 10];
		}
		else {
			hexnum[controlnum] = nownum+48;
		}
	}
	for (int i = 0; i < controlnum; i++) {
		printf("%c", hexnum[i]);
	}
}

int main() { 
	unsigned x = 25;    
	print_bin(x);
	print_oct(x);    
	print_hex(x);
	return 0; 
}