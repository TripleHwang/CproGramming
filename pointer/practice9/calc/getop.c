#include <stdio.h>
#include <ctype.h>
#include "calc.h"

/* getop: get next operator or numeric operand */
int getop(char s[], char* input) {
	int i, c;
	s[0] = ' ';
	s[1] = '\0'
	if (!isdigit(*input) && c != '.')
		return *input;      /* not a number */
	i = 0;
	if (isdigit(*input))    /* collect integer part */
		while (isdigit(s[++i] = *(input++)))
			;
	if (c == '.')      /* collect fraction part */
		while (isdigit(s[++i] = *(input++)))
			;
	s[i] = '\0';

	return NUMBER;
}