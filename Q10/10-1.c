#include<stdio.h>
#include<string.h>

int palindrome(char moon[], int i, int j)
{
	if (moon[i] == '\0')
		return 1;
	else {
		if (moon[i] == moon[j])
			return palindrome(moon, i + 1, j - 1);
		else
			return -1;
	}
}

int main()
{
	char moon[100];
	int res;

	while(1){
		printf("input: ");
		scanf("%s", moon);
		if (!strcmp(moon, "exit"))
			break;
		res = palindrome(moon, 0, strlen(moon) - 1);
		if (res == 1)
			puts("yse");
		else
			puts("no");
	}
}