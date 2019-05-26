#include <stdio.h>
#define MAXLENGTH 5000

void squeeze(char s1[], char s2[], char result[]);
int shouldremove(char c, char s[]);

int main()
{
	char original[MAXLENGTH] = "Hello, world! Will this remove punctuation?";
	char new[MAXLENGTH];
	char delete[10] = ",!?";

	squeeze(original, delete, new);

	printf("%s\n", original);
	printf("%s", new);
}

void squeeze(char s1[], char s2[], char result[])
{
	int i, l;

	for (i = 0; s1[i] != '\0'; i++)
		if (!shouldremove(s1[i], s2))
			result[l++] = s1[i];
}

int shouldremove(char c, char s[])
{
	int i;

	for (i = 0; s[i] != '\0'; i++)
		if (s[i] == c)
			return 1;
	return 0;
}
