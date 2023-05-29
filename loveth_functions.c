#include "main.h"

/* loveth_functions.c module */

/**
 * print_char - Prints a single character to stdout
 * @ap: The va_list containing the character argument
 * @params: The parameters struct (not used in this function)
 *
 * Return: The number of characters printed (always 1)
 */
int print_char(va_list ap, params_t *params)
{
	char pad_char = ' ';
	 unsigned int pad = 1, sum = 0, ch = va_arg(ap, int);

	if (params->minus_flag)
		sum += _putchar(ch);
	while (pad++ < params->width)
		sum += _putchar(pad_char);
	if (!params->minus_flag)
		sum += _putchar(ch);
	return (sum);
}

/**
 * print_int - Prints a signed decimal integer to stdout
 * @ap: The va_list containing the integer argument
 * @params: The parameters struct (not used in this function)
 *
 * Return: The number of characters printed
 */
int print_int(va_list ap, params_t *params)
{
	long l;

	if (params->l_modifier)
		l = va_arg(ap, long);
	else if (params->h_modifier)
		l = (short int)va_arg(ap, int);
	else
		l = (int)va_arg(ap, int);
