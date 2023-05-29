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
 * print_int - Prints an integer to stdout
 * @ap: The va_list containing the integer argument
 * @params: The parameters struct (not used in this function)
 *
 * Return: The number of characters printed
 */
int print_int(va_list ap, params_t *params)
{
	int num = va_arg(ap, int);
	int count = 0;

	if (num < 0)
	{
		_putchar('-');
		num = -num;
		count++;
	}
		count += print_number(convert(num, 10, 0, params) params);

	return count;
}
