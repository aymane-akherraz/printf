#ifndef MAIN_H_
#define MAIN_H_

#include <stdio.h>
#include <stdarg.h>

/**
 * struct print - Struct print
 *
 * @fs: The format specifier
 * @f: The function associated
*/
typedef struct print
{
	char *fs;
	int (*f)(va_list a, int l);
} print_f;

int _putchar(char c);
int divide(unsigned int n, unsigned int l);
int _printf(const char *format, ...);
int pt_char(va_list a, int len);
int pt_str(va_list a, int len);
int pt_dec(va_list a, int len);
int pt_int(va_list a, int len);

#endif
