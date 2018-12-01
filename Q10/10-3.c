#include<stdio.h>
#include<stdlib.h>
#define MAX 100

int data[MAX];
int N, K;
int count = 0;

void OK(int start, int end)
{
	int sum = data[start] + data[end];
	if (start < end) {
		if (sum > K)
			return OK(start, end - 1);
		else if (sum < K)
			return OK(start + 1, end);
		else {
			count++;
			return OK(start + 1, end - 1);
		}
	}
}

int main()
{
	int buffer;
	FILE *f1 = fopen("input1.txt", "r");

	fscanf(f1, "%d", &buffer);
	N = buffer;
	for (int i = 0; i < N; i++)
		fscanf(f1, "%d", &data[i]);
	fscanf(f1, "%d", &buffer);
	K = buffer;
	OK(0, N - 1);

	printf("%d\n", count);
}