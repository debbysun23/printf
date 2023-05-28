#include "main.h"

/* _put.c module */

/**
 * _puts - Prints a string to stdout
 * @str: The string to be printed
 *
 * Return: The number of characters printed
 */
int _puts(char *str)
{
	char *a = str;

	while (*str)
	_putchar(*str++);
	return (str - a);
}

/**
 * _putchar - Writes a character to stdout
 * @c: The character to be written
 *
 * Return: On success, the character written. On error, -1 is returned.
 */
int _putchar(int c)
{
	static int i;
	static char buf[OUTPUT_BUF_SIZE];

	if (c == BUF_FLUSH || i >= OUTPUT_BUF_SIZE)
{
	write(1, buf, i);
	i = 0;
}
	if (c != BUF_FLUSH)
	buf[i++] = c;
	return (1);
}
