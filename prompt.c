#include "holberton.h"
void prompt(void)
{
	char *prompt = "New shell $ ";

	write(1, prompt, 12);
}
