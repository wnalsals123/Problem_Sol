#include<stdio.h>
#include<stdlib.h>

struct xy {
	int x;
	int y;
};

int **N, pn = 0;
struct xy point[100], *sta, now;

void nsave(int i, int j)
{
	now.x = i;
	now.y = j;
}

void psave(int i, int j)
{
	point[pn].x = i;
	point[pn].y = j;
	pn++;
	N[i][j] = 2;
}

void search(int i, int j, int num)
{
	int get = 0;
	nsave(i, j);
	psave(i, j);

	do {
		for (int a = now.x - 1; a < now.x + 2; a++) {
			if (a < 0 || a > num - 1)
				continue;
			for (int b = now.y - 1; b < now.y + 2; b++) {
				if (b < 0 || b > num - 1)
					continue;
				if (N[a][b] == 1) {
					nsave(a, b);
					psave(a, b);
					get = 1;
					break;
				}
			}
			if (get == 1)
				break;
		}
		if (get == 1) {
			get = 0;
			continue;
		}
		if (sta != NULL && sta->x == now.x && sta->y == now.y) {
			sta--;
			nsave(sta->x, sta->y);
			continue;
		}
		sta = point + pn - 2;
		nsave(sta->x, sta->y);
	} while (point[0].x != now.x || point[0].y != now.y);

	printf("%d ", pn);
	pn = 0;
}

int main()
{
	FILE *f1 = fopen("input1.txt", "r");
	int num, num2; 

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
			if (N[i][j] == 1)
				search(i, j, num);
		}
	}
	free(N);
	getchar();
	fclose(f1);
}