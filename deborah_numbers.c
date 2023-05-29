#include "main.h"

/**
 * _isdigit - Checks if a character is a digit (0-9)
 * @c: The character to be checked
 *
 * Return: 1 if the character is a digit, 0 otherwise
 */
int _isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

/**
 * _strlen - Computes the length of a string
 * @s: The input string
 *
 * Return: The length of the string
 */
int _strlen(char *s)
{
	int i = 0;

	while (*s++)
		i++;
	return (i);
}

/**
 * print_number - Prints an integer to stdout
 * @str: The string representation of the integer
 * @params: The parameters struct (not used in this function)
 *
 * Return: The number of characters printed
 */
int print_number(char *str, params_t *params)
{
	unsigned int i = _strlen(str);
	int neg = (!params->unsign && *str == '-');

	if (!params->precision && *str == '0' && !str[1])
