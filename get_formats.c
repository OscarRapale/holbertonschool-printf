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
		{NULL, NULL}
	};

	return (formats);
}

