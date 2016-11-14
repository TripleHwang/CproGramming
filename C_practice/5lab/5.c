#include <stdio.h>

void odd_even_sum(int n, int sums[]) {
	int odd = 0;
	int even = 0;
	int i = 1;
	int j = 2;
	/*for (int cnt = 0; cnt < n; ++cnt) {
		odd += i;
		i += 2;
	}
	for (int cnt = 0; cnt < n; ++cnt) {
		even += j;
		j += 2;
	}*/
	int cnt = 0;

	while (cnt < n) {
		even += j;
		odd += i;
		i += 2;
		j += 2;
		cnt++;
	}

	sums[0] = even;
	sums[1] = odd;
	/* fill me */
	return sums;
}

int main() {
	int sums[2] = {0, 0};

	odd_even_sum(0, sums);
	printf("Odd = %d Even = %d\n", sums[1], sums[0]); /* 0 0 */
	odd_even_sum(1, sums);
	printf("Odd = %d Even = %d\n", sums[1], sums[0]); /* 1 2 */
	odd_even_sum(2, sums);
	printf("Odd = %d Even = %d\n", sums[1], sums[0]); /* 4 6 */
	odd_even_sum(3, sums);
	printf("Odd = %d Even = %d\n", sums[1], sums[0]); /* 9 12 */
	odd_even_sum(4, sums);
	printf("Odd = %d Even = %d\n", sums[1], sums[0]); /* 16 20 */
	odd_even_sum(5, sums);
	printf("Odd = %d Even = %d\n", sums[1], sums[0]); /* 25 30 */


}