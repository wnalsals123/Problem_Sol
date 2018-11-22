#include<stdio.h>
#include<stdlib.h>

struct xy {
	int x;
	int y;
};

int main()
{
	FILE *f1 = fopen("input1.txt", "r");
	int **N, num, num2, pn = 0, cou = 0;
	struct xy point[100];

	fscanf(f1, "%d", &num);
	N = malloc(sizeof(int*) * num);
	for (int i = 0; i < num; i++)
		N[i] = malloc(sizeof(int) * num);	

	for (int i = 0; i < num; i++) {
		for (int j = 0; j < num; j++) {
			fscanf(f1, "%d", &num2);
			N[i][j] = num2;
		}
	}

	for (int i = 0; i < num; i++) {
		for (int j = 0; j < num; j++) {
			if (N[i][j] == 1) {
				point[pn].x = i;
				point[pn].y = j;
			}
		}
	}

	getchar();
	fclose(f1);
}