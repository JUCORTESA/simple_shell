#ifndef HOL
#define HOL


#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>

char *_getline(size_t *p);
void prompt(void);
void sigintHandler(int sig_num);
char **_strtok(char *buffer);
#endif
