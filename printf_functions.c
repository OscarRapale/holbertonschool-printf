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

/**
 * print_binary- prints the binary representation
 * of a integer, handles %b
 *
 * @args: list og arguments
 * @count: character counter
 *
 */
void print_binary(va_list args, int *count)
{
	unsigned int n = va_arg(args, unsigned int);
	char buffer[33];
	int i;

	if (n == 0)
	{
		putchar('0');
		(*count)++;
		return;
	}
	for (i = 31; i >= 0; i--)
	{
		buffer[i] = (n & 1) ? '1' : '0';
		n >>= 1;
	}
	for (i = 0; buffer[i] == '0'; i++)
		;
	for (; i < 32; i++)
	{
		putchar(buffer[i]);
		(*count)++;
	}
}
