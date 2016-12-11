#include <stdio.h>
#include <stdlib.h>

struct _Test{
	int a;
}typedef Test;

int main(){
	Test *str1 = (Test *) malloc(sizeof(Test));
	str1 -> a = 5;
	printf("%d",str1->a);
	free(str1);
	str1 = NULL;
	printf("%d",str1->a);
	return 0;
}