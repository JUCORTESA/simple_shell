#include "holberton.h"
/**
 * sigintHandler - avoid ctrl + c
 * @sig_num: value that received
 * Return: nothing
 */
void sigintHandler(int sig_num)
{
	if (signal(SIGINT, SIG_IGN) == SIG_ERR)
		printf("Signal error: %i\n", sig_num);
}
