#include <stdio.h>

void expand(char s[], char t[]) {
	int start, end;
	int i;
	int go;
	start = 48;
	end = 57;
	if (s[0] >= '0' && s[0] <= '9') {
		start = s[0];
		if (s[2] >= '0' && s[2] <= '9') {
			end = s[2];
		}
		else if (s[1] == '-') {

		}
		else {
			start = s[0];
			end = s[0];
		}
	}
	else {
		if (s[1] >= '0' && s[1] <= '9') {
			end = s[1];
		}
	}
	if (start - end <= 0) {
		go = end - start;
		for (i = 0; i <= go; i++) {
			t[i] = start + i;
		}
		t[i] = '\0';
	}
}

int main() {
    char u0[10] = "-";
    char u1[10] = "-3";
    char u2[10] = "4-";
    char u3[10] = "5";
    char v[10];
    printf("Before: %s\n", u0);
    expand(u0, v);
    printf("After: %s\n", v);
    printf("Before: %s\n", u1);
    expand(u1, v);
    printf("After: %s\n", v);
    printf("Before: %s\n", u2);
    expand(u2, v);
    printf("After: %s\n", v);
    printf("Before: %s\n", u3);
    expand(u3, v);
    printf("After: %s\n", v);
}