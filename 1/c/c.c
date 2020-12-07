#include <stdio.h>

#define P 4
int main() {
	int e[500];
	int n[P] = {0};
	FILE* f = fopen("input.txt", "r");
	while (!feof(f)) {
		int i;
		fscanf(f, "%d", &i);
		
		int p = i / (2020 / P);
		e[n[p]++ * P + p] = i;
		for (int j = 0; j < n[P - 1 - p]; ++j) {
			if (i + e[j * P + P - 1 - p] == 2020) {
				printf("+ %d [%d]%d [%d]%d %d\n", p, (n[p] - 1) * P + p, i, j * P + P - 1 - p, e[j * P + P - 1 - p], i + e[j * P + P - 1 - p]);
				return 0;
			} else {
//				printf("- %d [%d]%d [%d]%d %d\n", p, (n[p] - 1) * P + p, i, j * P + P - 1 - p, e[j * P + P - 1 - p], i + e[j * P + P - 1 - p]);
			}
		}
	}
}
