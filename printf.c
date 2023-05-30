#include "main.h"

/**
 * _printf - prints anything
 * @format: the format string
 *
 * Return: number of bytes printed
 */
int _printf(const char *format, ...)
{
	int sum = 0;
	va_list ap;
	char *p, *start;
	params_t params = PARAMS_INIT;

	va_start(ap, format);

	if (!format || (format[0] == '%' && !format[1]))
	return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
	return (-1);
	for (p = (char *)format; *p; p++)
	{
	init_params(&params, ap);
	if (*p != '%')
{
	sum += _putchar(*p);
	continue;
}
	start = p;
	p++;
	while (get_flag(p, &params)) /* while char at p is flag char */

{
	p++; /*the next char */
}
	p = get_width(p, &params, ap);
	p = get_precision(p, &params, ap);
	if (get_modifier(p, &params))
		p++;
	if (!get_specifier(p))
	sum += print_from_to(start, p,
	params.l_modifier || params.h_modifier ? p - 1 : 0);
	else
	sum += get_print_func(p, ap, &params);
}
	_putchar(BUF_FLUSH);
	va_end(ap);
	return (sum);
}
/**
 * get_flag - gets the flag character and updates the parameters
 * @p: the current position in the format string
 * @params: the parameters struct to update
 *
 * Return: pointer to the next position after the flag character
 */
char *get_flag(char *p, params_t *params)
{
	if (*p == '-')
		params->flag_minus = 1;
	else if (*p == '+')
		params->flag_plus = 1;
	else if (*p == ' ')
		params->flag_space = 1;
	else if (*p == '0')
		params->flag_zero = 1;
	else if (*p == '#')
		params->flag_hash = 1;
	else
		return (p); /* Not a flag character, return pointer as is */

	return (p + 1); /* Move to the next character */
}

/**
 * get_width - gets the field width and updates the parameters
 * @p: the current position in the format string
 * @params: the parameters struct to update
 * @ap: the va_list argument
 *
 * Return: pointer to the next position after the field width
 */
char *get_width(char *p, params_t *params, va_list ap)
{
	if (*p == '*')
	{
		params->width = va_arg(ap, int);
		if (params->width < 0)
		{
			params->width *= -1;
			params->flag_minus = 1;
		}
		return (p + 1);
	}
	else if (*p >= '0' && *p <= '9')
	{
		params->width = atoi(p);
		while (*p >= '0' && *p <= '9')
			p++;
		return (p);
	}

	return (p); /* No width specified, return pointer as is */
}

/**
 * get_precision - gets the precision and updates the parameters
 * @p: the current position in the format string
 * @params: the parameters struct to update
 * @ap: the va_list argument
 *
 * Return: pointer to the next position after the precision
 */
char *get_precision(char *p, params_t *params, va_list ap)
{
	if (*p == '.')
	{
		p++;
		if (*p == '*')
		{
			params->precision = va_arg(ap, int);
			return (p + 1);
		}
		else if (*p >= '0' && *p <= '9')
		{
			params->precision = atoi(p);
			while (*p >= '0' && *p <= '9')
				p++;
			return (p);
		}
		else
		{
			params->precision = 0;
			return (p);
		}
	}

	return (p); /* No precision specified, return pointer as is */
}

/**
 * get_modifier - gets the length modifier and updates the parameters
 * @p: the current position in the format string
 * @params: the parameters struct to update
 *
 * Return: pointer to the next position after the length modifier
 */
char *get_modifier(char *p, params_t *params)
{
	if (*p == 'l')
		params->l_modifier = 1;
	else if (*p == 'h')
		params->h_modifier = 1;
	else
		return (p); /* Not a modifier, return pointer as is */

	return (p + 1); /* Move to the next character */
}

/**
 * get_specifier - checks if the character is a valid specifier
 * @c: the character to check
 *
 * Return: 1 if valid specifier
