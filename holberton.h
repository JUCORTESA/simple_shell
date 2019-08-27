#ifndef SHELL_H
#define SHELL_H


#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <sys/stat.h>
#include <stdint.h>
#include <stdarg.h>
#include <fcntl.h>

/**
 * struct type - struct of type of data
 * @type: type od data
 * @functiontype: pointer to de function
 */
typedef struct type
{
	char *type;
	int (*functiontype)(char *buffer, char **buff);
} data;

void prompt(void);
void sigintHandler(int sig_num);
char *_strtok(char *str, const char *delim);
int _strlen(char *s);
char **getargs(char *buffer);
int count(char *buff, char *l);
void freeAll(char **buff);
int coincidence(char **buff, char *buffer);
int ext(char * buffer, char **buff);
ssize_t getline1(char **lineptr, size_t *n, FILE *stream);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
char *_strcpy(char *dest, char *src);
void spaces(char *buffer);
int env(char * buffer, char **buff);
char *compare_path(char * buffer, char *path);
char *str_concat(char *s1, char *s2);
char *get_env(char *);
char *cpstring(char *path);
ssize_t getline1(char **lineptr, size_t *n, FILE *stream);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
char *_strcpy(char *dest, char *src);
void *_calloc(unsigned int nmemb, unsigned int size);
int cd_fun(char *buff, char **buffer);
char *get_pwd(void);
void changepwd(char *pwd);
char *oldpwd(void);


#endif
