#include <stdio.h>

/* packdate: packs date into 16-bit integer */
unsigned short packdate(unsigned short year, unsigned short month, unsigned short day) {
	unsigned short allone = ~0;

    return 0;
}

int main() {
	unsigned short year = 2016;
	unsigned short month = 10;
	unsigned short day = 27;
	printf("%d/%d/%d = %d\n", year, month, day, packdate(year, month, day));
}

/*
2016/10/27 = 8539
*/