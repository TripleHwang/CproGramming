#include <stdio.h>

char *strncopy(char *s, char *t, int n) {
	for (int i = 0; i < n; i++) {
		if (*(t + i) == '\0') {
			*(s + i) = '\0';
		}
		else {
			*(s + i) = *(t + i);
		}
	}
}


void main() {
	char s[100] = "asdfasdf";
	strncopy(s, "ERICA", 3);
	printf("%s", s);
}