#include<stdio.h>
#include<stdlib.h>
#define MAX 100

int data[MAX];
int N, K;

void floor(int start)
{
	int res;
	if (data[start] > K)
		printf("-1\n");
	else {
		if (data[start + 1] == NULL || data[start + 1] > K) {
			printf("%d\n", data[start]);
		}
		else
			return floor(start + 1);
	}
}

void ceiling(int end)
{
	if (data[end] < K)
		printf("-1\n");
	else {
		if (data[end - 1] == NULL || data[end - 1] < K) {
			printf("%d\n", data[end]);
		}
		else
			return ceiling(end - 1);
	}
}

int main()
{
	int buffer;
	FILE *f1 = fopen("input2.txt", "r");

	fscanf(f1, "%d", &buffer);
	N = buffer;
	for (int i = 0; i < N; i++)
		fscanf(f1, "%d", &data[i]);
	fscanf(f1, "%d", &buffer);
	K = buffer;

	floor(0);
	ceiling(N - 1);
}