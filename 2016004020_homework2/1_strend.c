#include <stdio.h>
#include <conio.h>

int strend(char *s, char *t) {
	int len = 0;
	while (*s != '\0') {
		s++;
	}
	while (*t != '\0') {
		t++;
		len++;
	}
	for (int i = 0; i < len; i++) {
		s--;
		t--;
		if (*s != *t) {
			return 0;
		}
	}
	return 1;
}

int main() {
	printf("%d\n", strend("HanyangERICA", "ERICA"));
	printf("%d\n", strend("HanyangERICAERICA", "ERICA"));
	printf("%d\n", strend("HanyangERICAnsan", "ERICA"));
	printf("%d\n", strend("Hanyang", "ERICA"));
	char c = getch();
}