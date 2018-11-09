#include<stdio.h>
#include"mlibrary.h"

int main()
{
	extern int a, b;

	printf("%d %d\n", a, b);
	add_song();
	a = read_line();
	printf("%d\n", a);
	a = remove_song();
	printf("%d\n", a);
	a = MAX;
	printf("%d\n", a);

	return 0;
}