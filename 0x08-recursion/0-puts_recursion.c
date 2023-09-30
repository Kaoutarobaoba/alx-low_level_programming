#include "main.h"
/**
 * _puts_recursion - function like puts();
 * @s: input
 * Return: Always 0 (Success)
 */
void _puts_recursion(char *s)
{
<<<<<<< HEAD
	if (*s)
	{
		_putchar(*s);
		_puts_recursion(s + 1);
	}

	else
		_putchar('\n');
=======
		if (*s)
                {
			_putchar(*s);
			_puts_recursion(s + 1);
		}

		else
		        _putchar('\n');
>>>>>>> db2c661b466713d83334386f5061f292eb7339cf
}
