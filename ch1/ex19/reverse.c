#include <stdio.h>

void reverse(char s[], char t[])
{
	int i = 0;
	while (s[i + 1] != '\n')
		i++;
	// i is now at the last real character in the string
	int j = 0;
	while (i > -1)
		t[j++] = s[i--];
	t[j] = '\0';
}

int get_line(char s[], int max)
{
	char c;
	int i;
	for (i = 0; (c = getchar()) != EOF && i < max - 1; i++)
	{
		s[i] = c;
		if (c == '\n')
		{
			s[++i] = '\0';
			return i;
		}
	}
	s[i] = '\0';
	return i;
}

int main(void)
{
	char string[100], reversed[100];
	while (get_line(string, 100) != 0)
	{
		reverse(string, reversed);
		printf("%s\n", reversed);
	}
}
