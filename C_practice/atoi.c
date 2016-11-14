#include <stdio.h>

/* atoi: convert s to integer */
int atoi(char s[]) {
    int i, n;

    n = 0;
	for (i = 0; s[i] >= '0' && s[i] <= '9' || s[i] >= 'A' && s[i] <= 'F'; ++i) {
		if (s[i] >= '0' && s[i] <= '9') {
			n = 16 * n + (s[i] - '0');
		}
		else {
			n = 16 * n + (s[i] - 'A' + 10);
		}
	}
	return n;
}

void main() {
	char st[5] = "000B";
	printf("%d", atoi(st));
}