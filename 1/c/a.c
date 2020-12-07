#include <stdio.h>

int main() {
	int is[500];
	int n = 0;
	FILE* f = fopen("input.txt", "r");
	while (!feof(f)) {
		int i;
		fscanf(f, "%d", &i);
		is[n++] = i;
		for (int j = 0; j < n - 1; ++j) {
			if (i + is[j] == 2020) {
				printf("+ [%d]%d [%d]%d %d\n", n - 1, i, j, is[j], i + is[j]);
				return 0;
			} else {
//				printf("- [%d]%d [%d]%d %d\n", n - 1, i, j, is[j], i + is[j]);
			}
		}
	}
}
