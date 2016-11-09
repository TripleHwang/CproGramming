#include <stdio.h>

/* hailstones : prints hailstone sequence for n and returns the number of the sequence */
int hailstones(int n) {
	int count = 0;
	if(n == 0){
		return 0;
	}
	else if(n<0){
		return 0;
	}

	count++;

	while(n != 1){
		if(n%2 == 0){
			n = n/2;
			++count;
		}
		else{
			n = n * 3 + 1;
			++count;
		}
	}
	return count;
}

int main() {
	printf("Number of Hailstones = %d\n", hailstones(37));
	printf("Number of Hailstones = %d\n", hailstones(1));
	printf("Number of Hailstones = %d\n", hailstones(-3));
} 

/*
37, 112, 56, 28, 14, 7, 22, 11, 34, 17, 52, 26, 13, 40, 20, 10, 5, 16, 8, 4, 2, 1
Number of Hailstones = 22
1
Number of Hailstones = 1
Number of Hailstones = 0
*/