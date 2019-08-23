#include "holberton.h"
void spaces(char *buffer)
{
	int i = 0, j = 0;

	if (buffer[i] == 32)
	{
		while(buffer[i] == 32)
		{
			i++;
		}
		while(buffer[i] != '\0')
		{
			buffer[j] = buffer[i];
			i++;
			j++;
		}
		while(buffer[j] != '\0')
		{
			buffer[j] = '\0';
		}
	}
	else
		return;
}
