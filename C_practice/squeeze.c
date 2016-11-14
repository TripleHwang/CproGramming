#include <stdio.h>

/* squeeze: delete all c from s */
void squeeze(char s[], char c[]) {
	int i, j;
	for (int k = 0; c[k] != '\0'; k++) {
		for (i = j = 0; s[i] != '\0'; i++)
			if (s[i] != c[k])
				s[j++] = s[i];
		s[j] = '\0';
	}
}

void main() {
	char a[10] = "hanyang";
	char b[5] = "ng";
	squeeze(a, b);
	printf("%s", a);
}