#include <stdio.h>
#include <string.h>

/* reverse: reverse string s in place */
void reverse(char s[]) {
  int c, i, j;

  for (i = 0, j = strlen(s)-1; i < j; i++, j--) {
    c = s[i];
    s[i] = s[j];
    s[j] = c;
  }
}

void myreverse(char *s){
	int i, j;
	char c;
	j = 0;
	while (*s != '\0') {
		j++;
		s++;
	}
	s = s - j;
	for (i = 0; i < j; i++, j--) {
		c = *(s + i);
		*(s + i) = *(s + j - 1);
		*(s + j - 1) = c;
	}
}

int main(void){
  char s[100] = "HANYANG";
  myreverse(s);
  printf("%s\n", s); // GNAYNAH
}