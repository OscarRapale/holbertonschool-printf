#include <stdio.h>
#include <stdarg.h>
#include "main.h"

/**
 * handle_format_specifier - handle a single format specifier
 * @specifier: the format specifier character
 * @args: list of arguments
 * @count: character counter
 * @formats: array of format_t structures
 *
 * Return: 1 if the specifier was handled, 0 otherwise
 */
static int handle_format_specifier(char specifier, va_list args,
		int *count, format_t *formats)
{
	int i;

	for (i = 0; formats[i].specifier != NULL; i++)
	{
		if (specifier == *(formats[i].specifier))
		{
			formats[i].handler(args, count);
			return (1);
		}
	}
	return (0);
}

/**
 * print_and_increment_count - Helper function to print character
 * and increment count
 * @c: format given by the user
 * @count: counter of characters
 *
 * Return: void
 */

static void print_and_increment_count(char c, int *count)
{
	putchar(c);
	(*count)++;
}

/**
 * _printf - function to print different format specifiers
 * @format: the format given by the user
 *
 * Return: number of characters counted
 */
int _printf(const char *format, ...)
{
	format_t formats[] = {
		{"c", print_char},
		{"s", print_string},
		{"d", print_int},
		{"i", print_int},
		{NULL, NULL}
	};
	va_list args;
	int count = 0;

	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == '%')
			{
				print_and_increment_count('%', &count);
			}
			else if (*format == '\0')
			{
				return (-1);
			}
			else
			{
				if (!handle_format_specifier(*format, args, &count, formats))
				{
					print_and_increment_count('%', &count);
					print_and_increment_count(*format, &count);
				}
			}
		}
		else
		print_and_increment_count(*format, &count);

		format++;
	}
	va_end(args);
	return (count);
}

