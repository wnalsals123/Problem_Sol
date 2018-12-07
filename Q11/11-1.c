#include<stdio.h>
#include<math.h>
#define true 1
#define false 0

typedef int boolean;

int N, level; // start: level 0의미
int cols[20]; // cols[1]의 값: 1번말의 열번호

boolean promising(int level)
{
	for (int i = 1; i < level; i++) {
		if (cols[i] == cols[level])
			return false;
		else if (level - i == abs(cols[level] - cols[i]))
			return false;
	}
	return true;
}

boolean queens(int level) // level 만큼 퀸이 놓였다.
{
	if (!promising(level))
		return false;
	else if (level == N)
		return true;
	for (int i = 1; i <= N; i++) {
		cols[level + 1] = i;
		if (queens(level + 1))
			return true;
	}
	return false;
}

int main()
{

}