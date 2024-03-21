#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>

/**
 * struct format_t - Struct for format specifiers and their corresponding
 * function pointers.
 * @specifier: The format specifier.
 * @handler: The function to handle the format specifier.
 */

typedef struct format_t
{
char *specifier;
void (*handler)(va_list args, int *count);
} format_t;

void print_char(va_list args, int *count);
void print_string(va_list args, int *count);
void print_int(va_list args, int *count);
void print_binary(va_list args, int *count);
int _printf(const char *format, ...);

format_t *get_formats(void);
#endif
