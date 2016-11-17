#include <stdio.h>
#include <conio.h>

char *strncat(char *s, char *t, int n) {
	while (*s != '\0') {
		s++;
	}
	for (int j = 0; j < n; j++) {
		*(s + j) = *(t + j);
	}
	*(s + n + 1) = '\0';
}

void main() {
	char s[100] = "asdfasdf";
	strncat(s, "ERICA", 3);
	printf("%s", s);
	char c = getch();
}