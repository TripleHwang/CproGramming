#include <stdio.h>

/* copy input to output; 1st version */
int main() {
	int c;
	int d;

	while ((c = getchar()) != EOF) {
		if (c == ' ' && d == ' ')
			continue;
		putchar(c);
		d = c;
	}
}