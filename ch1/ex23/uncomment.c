#include <stdio.h>
#define LIMIT 5000

/* remove comments
 * from a C program */

int get_file(char s[], int max)
{
	int i;
	char c;
	for (i = 0; (c = getchar()) != EOF; ++i)
		if (i < max - 1)
			s[i] = c;
	s[++i] = '\0';
}

int main()
{
	char line[LIMIT];
	char s[] = "hello! // this is a quoted string! /* still quoted! */\n";
	get_file(line, LIMIT); // this is a one-line comment!

	char c;
	int in_quoted = /* why would anyone comment like this */ 0;
	// this is another one-line comment!
	for (int i = 0; (c = line[i]) != '\0'; i++)
	{
		if (c == '"' && line[i - 1] != '\'' && !in_quoted) // we've entered a quoted string
			in_quoted = 1;
		else if (c == '"' && line[i - 1] != '\\' && in_quoted) // we've exited a quoted string
			in_quoted = 0;

		if (!in_quoted)
		{
			if (c == '/' && line[i + 1] == '/') // single-line comment
				while (line[++i] != '\n')
					;
			if (c == '/' && line[i + 1] == '*') // multi-line comment
			{
				while (!(line[i] == '*' && line[i + 1] == '/'))
					i++;
				i += 2;
			}
		}
		putchar(line[i]);
	}
	
	return 0;
}
