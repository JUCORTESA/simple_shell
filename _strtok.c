#include "holberton.h"
/**
* *strtok1 -  breaks a string into a sequence of nonempty tokens.
* @str: string.
* @delim: set of bytes that delimit the tokens in the parsed string.
* Return: a pointer to the next token, or NULL if there are no more tokens.
*/

char *strtok1(char *str, const char *delim)
{
	static char *buffer;

	if (str != NULL)
		buffer = str;
	if (buffer[0] == '\0')
		return (NULL);
	char *ret = buffer, *buffer2;
	const char *delim2;

	for (buffer2 = buffer; *buffer2 != '\0'; buffer2++)
	{
		for (delim2 = delim; *delim2 != '\0'; delim2++)
		{
			if (*buffer2 == *delim2)
			{
				*buffer2 = '\0';
				buffer = buffer2 + 1;

				if (buffer2 == ret)
				{
					ret++;
					break;
				}
			return (ret);
			}
		}
	}

	return (ret);
}

