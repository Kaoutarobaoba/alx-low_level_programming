#include "main.h"
/**
<<<<<<< HEAD
 * _print_rev_recursion - Print a string in reverse.
=======
 * _print_rev_recursion - Prints a string in reverse.
>>>>>>> db2c661b466713d83334386f5061f292eb7339cf
 * @s: The string to be printed.
 */
void _print_rev_recursion(char *s)
{
	if (*s)
	{
		_print_rev_recursion(s + 1);
		_putchar(*s);
	}
}
