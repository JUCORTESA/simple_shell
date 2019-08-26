#include "holberton.h"
/**
 * sigintHandler - avoid ctrl + c
 * @sig_num: value that received
 * Return: nothing
 */
void sigintHandler(int sig_num __attribute__((unused)))
{
	if (signal(SIGINT, SIG_IGN) == SIG_ERR)
		write(1, "fail", 5);
}
