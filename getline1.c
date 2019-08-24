#include "holberton.h"
/**
 * store_lineptr - assigns the line for get_line
 * @lineptr: buffer that store the string
 * @buffer: str that is been called to line
 * @size_l: size of line
 * @size_b: size of buffer
 */

void store_lineptr(char **lineptr, size_t *size_l, char *buffer, size_t size_b)
{
	size_t size = 1024;

	if (*lineptr == NULL)
	{
		if  (size_b > size)
			*size_l = size_b;

		else
			*size_l = size;
		*lineptr = buffer;
	}
	if (*size_l < size_b)
	{
		if (size_b > size)
			*size_l = size_b;
		else
			*size_l = size;
		*lineptr = buffer;
	}
	else
	{
		_strcpy(*lineptr, buffer);
		free(buffer);
	}
}
/**
 * getline1 - Read input from stream
 * @lineptr: buffer that stores the input
 * @n: size of lineptr
 * @stream: stream to read from
 * Return: The number of bytes
 */
ssize_t getline1(char **lineptr, size_t *n, FILE *stream)
{

	char *buffer, buff;
	ssize_t count = 0, ret;
	ssize_t size = 1024;
	int i;

	if (count == 0)
		fflush(stream);
	else
		return (-1);


	buffer = malloc(size);
	if (buffer == 0)
		return (-1);
	while (buff != '\n')
	{
		i = read(STDIN_FILENO, &buff, 1);
		if (i == -1 || (i == 0 && count == 0))
		{
			free(buffer);
			return (-1);
		}
		if (i == 0 && count != 0)
		{
			count++;
			break;
		}
		if (count >= size)
			buffer = _realloc(buffer, count, count + 1);
		buffer[count] = buff;
		count++;
	}
	buffer[count] = '\0';
	store_lineptr(lineptr, n, buffer, count);
	ret = count;
	if (i != 0)
		count = 0;
	return (ret);
}
