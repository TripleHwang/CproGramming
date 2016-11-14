#include <stdio.h>

int double_sum_for(int n) {
	int sum = 0, i;
	if (n > 0) {
		for (i = n; i < 2 * n + 1; i++) {
			sum += i;
		}
	}

	else if (n < 0) {
		for (i = 2*n; i <=n ; i++) {
			sum += i;
		}
	}

	/* fill me */
	return sum;
}

int double_sum_while(int n) {
	int sum = 0;

	if (n > 0) {
		int i = n;
		while (i <= 2 * n) {
			sum += i;
			i++;
		}
	}

	else if (n < 0) {
		int i = 2*n;
		while (i <= n) {
			sum += i;
			i++;
		}
	}

	/* fill me */
	return sum;
}

int main() {
	printf("%d\n", double_sum_for(0)); /* 0 */
	printf("%d\n", double_sum_for(1)); /* 3 */
	printf("%d\n", double_sum_for(3)); /* 18 */
	printf("%d\n", double_sum_for(-3)); /* -18 */
	printf("%d\n", double_sum_while(0)); /* 0 */
	printf("%d\n", double_sum_while(1)); /* 3 */
	printf("%d\n", double_sum_while(3)); /* 18 */
	printf("%d\n", double_sum_while(-3)); /* -18 */
}