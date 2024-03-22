#include <stdio.h>
#include <stdarg.h>
#include "main.h"

/**
 * get_formats - Function that initializes and returns the formats array.
 *
 *
 * Return: A pointer to the first element of the formats array.
 */
format_t *get_formats(void)
{
	static format_t formats[] = {
		{"c", print_char},
		{"s", print_string},
		{"d", print_int},
		{"i", print_int},
		{"b", print_binary},
		{"u", print_unsigned},
		{"o", print_octal},
		{"x", print_hex},
		{"X", print_HEX},
		{NULL, NULL}
	};

	return (formats);
}

