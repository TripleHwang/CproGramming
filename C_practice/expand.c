#include <stdio.h>

void expand(char s[], char t[]) {
	int start, end;
	int i;
	int go;
	start = s[0];
	end = s[2];
	if (s[0] - s[2] < 0) {
		go = s[2] - s[0];
		for (i = 0; i <= go; i++) {
			t[i] = s[0]+i;
		}
		t[i] = '\0';
	}
	else if (s[0] == s[2]) {
		t[0] = s[0];
		t[1] = '\0';
	}
	else if (s[0] - s[2] > 0) {
		t[0] = '\0';
	}
}

int main() {
    char u0[10] = "2-7";
    char u1[10] = "3-3";
    char u2[10] ="4-2";
	char v[20];
    printf("Before: %s\n", u0);
    expand(u0, v);
    printf("After: %s\n", v);
    printf("Before: %s\n", u1);
    expand(u1, v);
    printf("After: %s\n", v);
    printf("Before: %s\n", u2);
    expand(u2, v);
    printf("After: %s\n", v);
}