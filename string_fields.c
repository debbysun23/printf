#include "main.h"

/**
 * print_string - prints the precision from the format string
 * @s: the format string
 * @params: the parameters struct
 * Return: new pointer
 */
int print_string(char *s, params_t *params)
{
	int count = 0;

	if (s == NULL)
		s = "(null)";

	while (*s != '\0')
	{
		_putchar(*s);
		s++;
		count++;
	}

	return (count);
}
