#include<stdio.h>
#include<string.h>
#define MAX_LEN 1000

int main()
{
	FILE *f1 = fopen("input1.txt", "r");
	int all, N[MAX_LEN] = {0}, n = 0, Nn = 0;
	char buffer[MAX_LEN];

	fscanf(f1, "%d", &all);
	for (int i = 0; i < all; i++) {
		fscanf(f1, "%s", buffer);
		while (buffer[n] != NULL) {
			if (buffer[n] == '('){
				N[Nn++]++;
				printf("%d ", Nn);
				n++;
			}
			else if (buffer[n] == ')') {
				for (int j = Nn - 1; j >= 0; j--)  {
					if (N[j] == 1) {
						printf("%d ", j + 1);
						N[j]--;
						n++;
						break;
					}
					if (j == 0) n++;
				}
			}
			else n++;
		}
		memset(N, 0, sizeof(int)*Nn);
		Nn = 0;
		n = 0;
		printf("\n");
	}
	fclose(f1);
}