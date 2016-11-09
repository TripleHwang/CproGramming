#include <stdio.h>

/* copy input to output */
int main() {
    int c;

	while ((c = getchar()) != EOF){
		if(c <= 'z' && c>= 'a'){
			c +='A'-'a';
		}
		putchar(c);
	}
}