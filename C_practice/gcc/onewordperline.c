#include <stdio.h>

/* copy input to output; 1st version */
int main() {
	int c;
	int d = 0;

	while ((c = getchar()) != EOF) {
		if (d != ' ' && d != '\n' && d != '\t') {
			if (c == ' ' || c == '\n' || c == '\t') {
				d = c;
				printf("\n");
				continue;
			}
		}
		else if (d == ' ' || d == '\n' || d == '\t') {
			if (c == ' ' || c == '\n' || c == '\t') {
				d = c;
				continue;
			}
		}
		d = c;
		putchar(c);
	}
}