#include "main.h"
/**
 * pt_char - Prints a character
 * @a: the given character
 * @len: the given length
 *
 * Return: number of characters printed
*/
int pt_char(va_list a, int len)
{
	_putchar(va_arg(a, int));
	return (++len);
}
