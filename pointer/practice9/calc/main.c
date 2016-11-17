#include <stdio.h>
#include <stdlib.h>    /* for atof() */
#include "calc.h"
#include "getch.c"
#include "getop.c"
#include "stack.c"

#define MAXOP   100    /* max size of operand or operator */

/* reverse Polish calculator */
int main(int argc, char *argv[]) {
	int type;
	double op2;
	char s[MAXOP];
	while(--argc > 0){
		++argv;
		type = getop(s, argv);
		switch (type) {
			case NUMBER: 
			    push(atof(p)); 
			    break;
			case '+': 
			    push(pop() + pop()); 
			    break;
			case '*': 
			    push(pop() * pop()); 
			    break;
			case '-':
			    op2 = pop();
			    push(pop() - op2);
			    break;
			case '/':
			    op2 = pop();
			    if (op2 != 0.0)
			    	push(pop() / op2);
			    else
			    	printf("error: zero divisor\n");
			    break;
			case '\n':
			    printf("\t%.8g\n", pop());
			    break;
			default:
			    printf("error: unknown command %s\n", s);
			    break;
		}
	}
	return 0;
}