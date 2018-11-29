#include<stdio.h>
#include<string.h>

char *moon[100];
int num = 0;

int compare(char *str1, char *str2)
{
	if (*str1 == '\0' && *str2 == '\0')
		return 0;
	else {
		if (*str1 < *str2)
			return -1;
		else if (*str1 > *str2)
			return 1;
		else
			return compare(str1 + 1, str2 + 1);
	}
}

void input() {
	char buffer[100];
	for (int i = 0; i < 5; i++) {
		printf("단어: ");
		scanf("%s", buffer);
		moon[num++] = strdup(buffer);
	}
}

void sort() {
	char *buffer;
	for (int i = 0; i < num - 1; i++) {
		for (int j = i + 1; j < num; j++) {
			if (compare(moon[i], moon[j]) > 0) {
				buffer = strdup(moon[j]);
				moon[j] = moon[i];
				moon[i] = buffer;
			}
		}
	}
}

void print()
{
	for (int i = 0; i < num; i++)
		puts(moon[i]);
}

int main()
{
	input();
	sort();
	print();
}