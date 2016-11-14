#include <stdio.h>
#include <string.h>

#define MAXLEN 1000 

char *alloc(int);

static char allocbuf[MAXLEN];
static char *allocp = allocbuf;

char *alloc(int n) {
	if (allocbuf + MAXLEN - allocp >= n) {
		allocp += n;
		return allocp - n;
	}
	else
		return NULL;
}

/* readline: read line into s, return length */
int readline(char s[], int lim) {
	int c, i;

	i = 0;
	while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
		s[i++] = c;
	if (c == '\n')
		s[i++] = c;
	s[i] = '\0';
	return i;
}

int readlines(char *lineptr[], int maxlines) {
	int len, nlines;
	char *p, line[MAXLEN];

	nlines = 0;
	while ((len = readline(line, MAXLEN)) > 0)
		if (nlines >= maxlines || (p = alloc(len)) == NULL)
			return -1;
		else {
			line[len-1] = '\0';
			strcpy(p, line);
			lineptr[nlines++] = p;
		}
	return nlines;
}

void writelines(char *lineptr[], int nlines) {
	while (nlines-- > 0)
		printf("%s\n", *lineptr++);
}

void swap(char *v[], int i, int j) {
	char *temp;

	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}

void qsort(char *lineptr[], int left, int right)
{
	int i, last, pivot;
	if (left >= right)
		return;
	swap(lineptr, left, (left + right) / 2);
	pivot = left;
	for (i = left + 1; i <= right; i++)
		if (strcmp(lineptr[i], lineptr[pivot])<0)
			swap(lineptr, ++pivot, i);
	swap(lineptr, left, pivot);
	qsort(lineptr, left, pivot - 1);
	qsort(lineptr, pivot + 1, right);
}
