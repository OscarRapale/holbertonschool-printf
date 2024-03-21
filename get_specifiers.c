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
static int handle_format_specifier(char specifier, va_list args
									, int *count, format_t *formats)
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
 * print_percentage - print '%' character
 * @count: character counter
 */
static void print_percentage(int *count)
{
	putchar('%');
	(*count)++;
}

/**
 * print_character - print a single character
 * @ch: the character to print
 * @count: character counter
 */
static void print_character(char ch, int *count)
{
	putchar(ch);
	(*count)++;
}

/**
 * handle_invalid_format - handle invalid format specifier
 * @format_char: the invalid format character
 * @count: character counter
 */
static void handle_invalid_format(char format_char, int *count)
{
	putchar('%');
	putchar(format_char);
	(*count) += 2;
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
			if (*format != '\0')
			{
				if (*format == '%')
				{
					print_percentage(&count);
				}
				else if (*(format + 1) == '\0')
				{
				}
				else
				{
					if (!handle_format_specifier(*format, args, &count, formats))
					{
						handle_invalid_format(*format, &count);
					}
				}
			}
		}
		else
		print_character(*format, &count);
		format++;
	}
	va_end(args);
	return (count);
}

