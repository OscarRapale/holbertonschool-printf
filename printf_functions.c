#include <stdio.h>
#include <stdarg.h>
#include "main.h"

/**
 * print_char - prints a single character, handles %c
 * @args: list of arguments
 * @count: character counter
 *
 */
void print_char(va_list args, int *count)
{
	int ch = va_arg(args, int);

	putchar(ch);
	(*count)++;
}

/**
 * print_string - prints a string, handles %s
 * @args: list of arguments
 * @count: character counter
 *
 */
void print_string(va_list args, int *count)
{
	char *str = va_arg(args, char *);

	if (str == NULL)
		str = "(null)";
	while (*str)
	{
		putchar(*str);
		str++;
		(*count)++;
	}
}

/**
 * print_int - prints an integer, handles %d and %i
 * @args: list of arguments
 * @count: character counter
 *
 */
void print_int(va_list args, int *count)
{
	int value = va_arg(args, int);
	int i;

	char buffer[50];

	sprintf(buffer, "%d", value);

	for (i = 0; buffer[i]; i++, (*count)++)
	{
		putchar(buffer[i]);
	}
}

