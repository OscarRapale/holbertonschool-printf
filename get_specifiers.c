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
			if (*format == '\0')
			{
				break;
			}
			else if (*format == '%')
			{
				putchar('%');
				count++;
				format++;
				continue;
			}
			int valid_format = 0;

			for (i = 0; formats[i].specifier; i++)
			{
				if (*format == *(formats[i].specifier))
				{
					formats[i].handler(args, &count);
					valid_format = 1;
					break;
				}
			}
			if (!valid_format && *format != '\0')
			{
				putchar('%');
				putchar(*format);
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

