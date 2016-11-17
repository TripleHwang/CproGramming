#include <stdio.h>

char *strncmp(char *s, char *t, int n) {
	int isequal = 0;
	for (int i = 0; i < n; i++) {
		if (*(s + i) - *(t + i) == 0) {
			;
		}
		else {
			return *(s + i) - *(t + i);
		}
	}
}

void main() {
	printf("%d", strncmp("ERaCA", "ERICA", 5));
}