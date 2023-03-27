#include "main.h"
#include <stdarg.h>
#include <stdlib.h>

/**
 * print_uToBinary - prints int converted to binary
 * @arg: argument
 *
 * Return: 0
 */
int print_uToBinary(va_list arg)
{
	unsigned int n = va_arg(arg, unsigned int);
	unsigned int printed;

	print_binary(n, &printed);
	print_binary(n, &printed);

	return (printed);
}
