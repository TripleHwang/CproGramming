#include <stdio.h>

/* packdate: packs date into 16-bit integer */
unsigned short packdate(unsigned short year, unsigned short month, unsigned short day) {
	unsigned short allone = ~0;
	year = year - 2000;
	year = year << 9;
	month = month << 5;
	day = day;
	allone = allone & (year+month+day);
    return allone;
}

/* showpackeddate: unpacks and prints a packed date */
void showpackeddate(unsigned short date) {
	unsigned short allone = ~0;
	allone = allone & date;
	unsigned short year = allone >> 9;
	year += 2000;
	unsigned short month = allone << 7;
	month = month >> 12;
	unsigned short day = allone << 11;
	day = day >> 11;
	printf("%d/%d/%d", year, month, day);
	
}

int main() {
	unsigned short year = 2016;
	unsigned short month = 10;
	unsigned short day = 27;
	showpackeddate(packdate(year, month, day));
}
