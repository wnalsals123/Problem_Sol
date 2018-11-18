#include<stdio.h>
#include<stdlib.h>
#define MAX_N 1000000

int main()
{
	FILE *f1 = fopen("input1.txt", "r");
	int all, num, n = 0, sum = 0, top = 0;
	int *N;

	fscanf(f1, "%d", &all);
	for (int i = 0; i < all; i++) {
		fscanf(f1, "%d", &num);
		N = malloc(sizeof(int)*num);
		for (int j = 0; j < num; j++)	
			fscanf(f1, "%d", &N[n++]);

		int *stack = malloc(sizeof(int)*num);
		stack[0] = N[n - 1];

		for (int k = n - 2; k >= 0; k--) {
			while (1) {
				if (N[k] <= stack[top]) {
					top++;
					stack[top] = N[k];
					break;
				}
				else if (top < 0) {
					top = 0;
					stack[top] = N[k];
					break;
				}
				else top--;
			}
			sum += top;
			sum %= 1000000;
		}
		printf("%d\n", sum % MAX_N);
		n = 0;
		sum = 0;
		free(N);
	}
	fclose(f1);
}