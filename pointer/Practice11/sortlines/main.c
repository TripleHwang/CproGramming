#include <stdio.h>
#include <string.h>
#include <conio.h>
#include "rwlines.c"

#define MAXLINES 5000

char *lineptr[MAXLINES];

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);
void qsort(char * lineptr[], int left, int right);

int main() {
	int nlines;

	if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
		qsort(lineptr, 0, nlines-1);
		writelines(lineptr, nlines);
		char c;
		c = getch();
		return 0;
	}
	else {
		printf("error: input too big to sort\n");
		return 1;
	}
}