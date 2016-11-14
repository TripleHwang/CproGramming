#include <stdio.h>
#define MAXLINE 10  /* maximum input line size */

int readline(char line[], int maxline);
void copy(char to[], char from[]);
void reverse(char line[], int len);

/* print longest input line */
int main() {
    int len;                 /* current line length */  
	char line[MAXLINE];      /* current input line */  
	while ((len = readline(line, MAXLINE)) > 0) {
		reverse(line, len);
		printf("%s", line);
	}/* there was a line */
	return 0;
}

/* readline: read a line into s, return length */
int readline(char s[], int lim) {
	int c, i;
	
	for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
		s[i] = c;
	if (c == '\n') {
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	return i;
}

void reverse(char line[], int len) {
	char reline[MAXLINE];
	copy(reline, line);
	int i;
	for (i = 0; i < len; ++i) {
		line[len-i-1] = reline[i];
	}
}

/* copy: copy 'from' into 'to'; assume to is big enough */
void copy(char to[], char from[]) {
	int i;
	
	i = 0;
	while ((to[i] = from[i]) != '\0')
		++i;
}
