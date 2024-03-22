#include <stdio.h>
#include <stdarg.h>
#include "main.h"

/**
 * print_unsigned - Prints an unsigned integer in decimal format
 * @args: list of arguments
 * @count: character counter
 *
 * Return: void
 */
void print_unsigned(va_list args, int *count)
{
	unsigned int value = va_arg(args, unsigned int);
	char buffer[50];
	int i;

	sprintf(buffer, "%u", value);
	for (i = 0; buffer[i]; i++, (*count)++)
	{
		putchar(buffer[i]);
	}
}

/**
 * print_octal - Prints an unsigned integer in octal format
 * @args: list of arguments
 * @count: character counter
 *
 * Return: void
 */
void print_octal(va_list args, int *count)
{
	unsigned int value = va_arg(args, unsigned int);
	char buffer[50];
	int i;

	sprintf(buffer, "%o", value);
	for (i = 0; buffer[i]; i++, (*count)++)
	{
		putchar(buffer[i]);
	}
}

/**
 * print_hex - Prints an unsigned integer in lowercase hexadecimal format
 * @args: list of arguments
 * @count: character chounter
 *
 * Return: void
 */
void print_hex(va_list args, int *count)
{
	unsigned int value = va_arg(args, unsigned int);
	char buffer[50];
	int i;

	sprintf(buffer, "%x", value);
	for (i = 0; buffer[i]; i++, (*count)++)
	{
		putchar(buffer[i]);
	}
}

/**
 * print_HEX - Prints an unsigned integer in uppercase hexadecimal format
 * @args: list of arguments
 * @count: character counter
 *
 * Return: void
 */
void print_HEX(va_list args, int *count)
{
	unsigned int value = va_arg(args, unsigned int);
	char buffer[50];
	int i;

	sprintf(buffer, "%X", value);
	for (i = 0; buffer[i]; i++, (*count)++)
	{
		putchar(buffer[i]);
	}
}

