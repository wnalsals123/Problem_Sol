#include<stdio.h>
#define true 1
#define false 0
#define PATHWAY 0	// white
#define WALL 1		// blue
#define BLOCKED 2	// red
#define PATH 3		// green

typedef int boolean;
int N = 8;
int maze[][8] = {
{0, 0, 0, 0, 0, 0, 0, 1},
{0, 1, 1, 0, 1, 1, 0, 1},
{0, 0, 0, 1, 0, 0, 0, 1},
{0, 1, 0, 0, 1, 0, 0, 0},
{0, 1, 0, 1, 1, 0, 1, 0},
{0, 1, 1, 0, 0, 1, 1, 0},
{0, 0, 0, 0, 1, 1, 1, 0},
{0, 1, 1, 0, 0, 0, 0, 0}
};
int count = 0;

boolean findfath(int x, int y)
{
	if (x < 0 || y < 0 || x >= N || y >= N) // 
		return false;
	else if (maze[x][y] != PATHWAY) // 그린, 레드, 벽 즉 벽 또는 방문한 셀이면
		return false;
	else if (x == N - 1 && y == N - 1) { // 출구면
		maze[x][y] = PATHWAY;
		count++;
		return false;
	}
	else{
		maze[x][y] = PATH;
		if (findfath(x - 1, y) || findfath(x, y + 1) || findfath(x + 1, y) || findfath(x, y - 1))
			return true;
		maze[x][y] = BLOCKED; // 길 없음
		return false;
	}
}

int main()
{
	findfath(0, 0);
	printf("경로: %d개\n", count);
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++)
			printf("%d ", maze[i][j]);
		printf("\n");
	}
}