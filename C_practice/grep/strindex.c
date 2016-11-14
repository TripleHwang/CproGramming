/* strindex: return index of t in s, -1 if none */
int strindex(char s[], char t[]) {
	int i, j, k;

	for (i = 0; s[i] != '\0'; i++) {
		for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++);
		if (k > 0 && t[k] == '\0')
			return i;
	}
	return -1;
}

int strrindex(char s[], char t[]) {
	int i, j, k;
	int result = -1;
	for (i = 0; s[i] != '\0'; i++) {
		for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++);
		if (k > 0 && t[k] == '\0')
			result = i;
	}
	if (result == -1) {
		return -1;
	}
	return result;
}

