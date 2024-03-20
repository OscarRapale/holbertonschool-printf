#include <stdio.h>
#include <stdarg.h>
#include "main.h"

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
	int i;

	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			for (i = 0; formats[i].specifier; i++)
			{
				if (*format == *(formats[i].specifier))
				{
					formats[i].handler(args, &count);
					break;
				}
			}
			if (*format == '%')
			{
				putchar('%');
				count++;
			}
		}
		else
		{
			putchar(*format);
			count++;
		}
		format++;
	}
	va_end(args);
	return (count);
}

