#include <stdio.h>
#include <ctype.h>

/* atof: convert string s to double */
double atof(char s[]) {
	double val, power;
	int i, sign;
	int e_num;
	int a = 0;

	for (i = 0; isspace(s[i]); i++);

	sign = (s[i] == '-') ? -1 : 1;
	if (s[i] == '+' || s[i] == '-')
		i++;
	for (val = 0.0; isdigit(s[i]); i++)
		val = 10.0 * val + (s[i] - '0');
	if (s[i] == '.')
		i++;
	for (power = 1.0; isdigit(s[i]); i++) {
		val = 10.0 * val + (s[i] - '0');
		power *= 10.0;
	}
	if (s[i] == 'E' || s[i] == 'e') {
		i++;
		if (s[i] == '+') {
			i++;
			a = s[i] - '0';
			for (i = 0; i < a; i++) {
				power /= 10;
			}
		}
		if (s[i] == '-') {
			i++;
			a = s[i] - '0';
			for (i = 0; i < a; i++) {
				power *= 10;
			}
		}
	}
	return sign * val / power;
}

int main() {
	char s[10] = "-123.45e-6";
	printf("%g\n",  atof(s));
}