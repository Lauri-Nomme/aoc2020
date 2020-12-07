#include <stdio.h>

int main() {
	int e[500];
	char s[9999] = {0};
	int n = 0;
	FILE* f = fopen("input.txt", "r");
	while (!feof(f)) {
		int i;
		fscanf(f, "%d", &i);
			e[n++] = i;
			s[i] = 1;

		if (s[2020 - i]) {
			printf("%d\n", i * (2020 - i));
			return 0;
		}
	}
}
