#include "main.h"
/**
 * divide - Divides a number by 10 until the division equals 0,
 * then print it to the screen
 * @n: the given number
 * @l: the given length
 *
 * Return: number of digits printed
*/
int divide(unsigned int n, unsigned int l)
{
	if ((n / 10) != 0)
		l =	divide((n / 10), l);

	_putchar('0' + (n % 10));
	l++;
	return (l);
}
