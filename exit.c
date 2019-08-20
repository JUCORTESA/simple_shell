#include "holberton.h"
void sigintHandler(int sig_num)
{
	if (signal(SIGINT, SIG_IGN) == SIG_ERR)
		printf("Signal error: %i\n", sig_num);
}
