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

	}

	for (int i = 0; i < n; i++) {
		int a = e[i];
		for (int j = 0; j < n; j++) {
			int b = e[j];
			if (a + b <= 2020 && s[2020 - a - b]) {
				printf("%d\n", a * b * (2020 - a - b));
				return 0;
			}
		}
	}
}
