#include <Stdio.h>

int any(char s[], char t[]) {
	int i, j;
	int presentNum = -1;

	for (i = 0; s[i] != '\0'; i++) {
		for (j = 0; t[j] != '\0'; j++) {
			if (t[j] == s[i]) {
				if (i < presentNum || presentNum == -1) {
					presentNum = i;
				}
			}
		}
	}
	return presentNum;
}

int main() {
	char u1[10] = "Hanyang";
	char u2[10] = "Ansan";
	char u3[10] = "ERICA"; 
	printf("%d\n", any(u1, u2));
	printf("%d\n", any(u2, u3)); 
	printf("%d\n", any(u3, u1)); 
	printf("%d\n", any(u2, u1));
	printf("%d\n", any(u3, u2)); 
	printf("%d", any(u1, u3));
}