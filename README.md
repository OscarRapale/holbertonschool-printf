# Holbertonschool Printf Team Project

## Description
This team project handles the printf function as part of the first trimester learning C.
_printf replicates the C standard library printf() function.

What you should learn from this project:

* How to use git in a team setting
* Applying variadic functions
* Applying function pointers
* Managing multiple files

---

## Prototype
```int _printf(const char *format, ...);```

## Usage
* Prints a string to the standard output, according to a given format
* All files were created and compiled on Ubuntu 14.04.4 LTS using GCC 4.8.4 with the command ```gcc -Wall -Werror -Wextra -pedantic -std=gnu89 -Wno-format *.c```
* Returns the number of characters in the output string on success.
* Call it like this: ```_printf("format string", arguments...)``` where ```format string``` can contain conversion specifiers,
along with regular characters.

## Examples

* ```_printf("Hello, World\n")``` *prints "Hello, World", followed by a new line*
* ```_printf("%s", "Hello")``` *prints "Hello"*
* ```_printf("This is a number: %d", 17)``` *prints "This is a number: 17"*

---

### Authors
* **Oscar Rapale** - (https://github.com/OscarRapale)
* **Ricardo Sanchez** - (https://github.com/RickMelendez)
