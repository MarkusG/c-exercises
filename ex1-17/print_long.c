#include <stdio.h>
#define MAXLINE 5000

void append(char target[], char source[]);
int get_line(char s[], int max);

int main(void)
{
	char line[MAXLINE];
	char final[MAXLINE];
	final[0] = '\0';

	int len;

	while ((len = get_line(line, MAXLINE)) > 0)
		if (len > 80)
 			append(final, line);

	printf("The lines longer than 80 characters are:\n%s", final);
	return 0;
}

void append(char t[], char s[])
{
	int i, l;

	i = l = 0;
	while (t[i] != '\0')
		i++;
	while ((t[i++] = s[l++]) != '\0')
		;
}

int get_line(char s[], int max)
{
	int i, c;

	for (i = 0; i < max - 1 && (c = getchar()) != EOF && c != '\n'; i++)
		s[i] = c;
	if (c == '\n')
		s[i++] = c;
	s[i] = '\0';
	return i;
}
