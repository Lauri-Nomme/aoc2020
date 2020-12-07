#include <stdio.h>

int main() {
	int e[500];
	int n[2] = {0};
	FILE* f = fopen("input.txt", "r");
	while (!feof(f)) {
		int i;
		fscanf(f, "%d", &i);
		
		int p = i < 2020 / 2;
		e[n[p]++ * 2 + p] = i;
		for (int j = 0; j < n[1 - p]; ++j) {
			if (i + e[j * 2 + 1 - p] == 2020) {
				printf("+ %d [%d]%d [%d]%d %d\n", p, (n[p] - 1) * 2 + p, i, j * 2 + 1 - p, e[j * 2 + 1 - p], i + e[j * 2 + 1 - p]);
				return 0;
			} else {
//				printf("- %d [%d]%d [%d]%d %d\n", p, (n[p] - 1) * 2 + p, i, j * 2 + 1 - p, e[j * 2 + 1 - p], i + e[j * 2 + 1 - p]);
			}
		}
	}
}
