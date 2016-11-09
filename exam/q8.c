#include <stdio.h>

/* packdate: packs date into 16-bit integer */
unsigned short packdate(unsigned short year, unsigned short month, unsigned short day) {
	/* from question 7 */
    return 0;
}

/* showpackeddate: unpacks and prints a packed date */
void showpackeddate(unsigned short date) {
	unsigned short allone = ~0;
	
}

int main() {
	unsigned short year = 2016;
	unsigned short month = 10;
	unsigned short day = 27;
	showpackeddate(packdate(year, month, day));
}
