#include <stdio.h>
#include <string.h> /* knows strlen function */

/* isoctal: checks if the given string is octal */
int isoctal(char s[]) {
    int i;

    return 0;
}

int main() {
    printf("%d\n", isoctal("0\0")); /* prints 0 */
    printf("%d\n", isoctal("3\0")); /* prints 0 */
    printf("%d\n", isoctal("00\0")); /* prints 1 */
    printf("%d\n", isoctal("01\0")); /* prints 1 */
    printf("%d\n", isoctal("02\0")); /* prints 1 */
    printf("%d\n", isoctal("07\0")); /* prints 1 */
    printf("%d\n", isoctal("08\0")); /* prints 0 */
    printf("%d\n", isoctal("010\0")); /* prints 1 */
    printf("%d\n", isoctal("011\0")); /* prints 1 */
    printf("%d\n", isoctal("017\0")); /* prints 1 */
    printf("%d\n", isoctal("020\0")); /* prints 1 */
    printf("%d\n", isoctal("077\0")); /* prints 1 */
    printf("%d\n", isoctal("078\0")); /* prints 0 */
    printf("%d\n", isoctal("0100\0")); /* prints 1 */
}