#include <stdio.h>
#define MAXLINE 1000 /* maximum input line length */

int readline(char line[], int max);
int strrindex(char source[], char searchfor[]);

char pattern[] = "ould"; /* pattern to search for */

/* find all lines matching pattern */
int main() {
	char line[MAXLINE];
	int found = 0;

	while (readline(line, MAXLINE) > 0)
		if (strrindex(line, pattern) >= 0) {
			printf("%s", line);
			found++;
		}
	return found;
}