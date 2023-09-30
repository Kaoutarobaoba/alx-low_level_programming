#include "main.h"

/**
<<<<<<< HEAD
 * factorial - returns the factorial to a number
 * @n: number to return the factorial from
 *
 * Return:to factorial of n
=======
 * factorial - returns the factorial of a number
 * @n: number to return the factorial from
 *
 * Return: factorial of n
>>>>>>> db2c661b466713d83334386f5061f292eb7339cf
 */
int factorial(int n)
{
	if (n < 0)
		return (-1);
	if (n == 0)
		return (1);
	return (n * factorial(n - 1));
}
