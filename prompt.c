#include "holberton.h"
/**
 * prompt - print a prompt
 * Return - nothing
 */
void prompt(void)
{
	char *prompt = "New shell $ ";

	write(STDIN_FILENO, prompt, 12);
}
