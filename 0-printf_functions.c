#include "main.h"

/**
 * print_char - prints char
 * @types: arg list
 * @buffer: buffer array
 * @flags: calculates flags
 * @width: gives width of output
 * @precision: specifies precision
 * @size: specifies size of output
 * Return: printed char number
 */
int print_char(va_list types, char buffer[], int flags, int width, int precision, int size)
{
	char c = va_arg(types, int);

	return (handle_write_char(c, buffer, flags, width, precision, size));
}

/**
 * print_string - prints string
 * @types: arg list
 * @buffer: buff array
 * @flags: flag calc
 * @width: output width
 * @precision: specifies precision
 * @size: output size
 * Return: printed chars number
 */
int print_string(va_list types, char buffer[], int flags, int width, int precision, int size)
{
	int length = 0, i;
	char *str = va_arg(types, char *);

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	if (str == NULL)
	{
		str = "(null)";
		if (precision >= 6)
		{
			str = "      ";
		}
	}
	while (str[length] != '\0')
	{
		length++;
	}
	if (precision >= 0 && precision < length)
	{
		length = precision;
	}
	if (width > length)
	{
		if (flags & F_MINUS)
		{
			write(1, &str[0], length);
			for (i = width - length; i > 0; i--)
			{
				write(1, " ", 1);
			}
			return (width);
		}
		else
		{
			for (i = width - length; i > 0; i--)
			{
				write(1, " ", 1);
			}
			write(1, &str[0], length);
			return (width);
		}
	}
	return (write(1, str, length));
}

/**
 * print_percent - prints percent sign
 * @types: arg list
 * @buffer: buff array
 * @flags: calcs flags
 * @width: outputs width
 * @precision: specifies precision
 * @size: specifies size
 *
 * Return: chars printed amount
 */
int print_percent(va_list types, char buffer[], int flags, int width, int precision, int size)
{
	  UNUSED(buffer);
	  UNUSED(flags);
	  UNUSED(width);
	  UNUSED(precision);
	  UNUSED(size);
	  UNUSED(types);
	  
	  return (write(1, "%%", 1));
}

/**
 * print_int - print int
 * @types: arg list
 * @buffer: biffer array
 * @flags: calculates active flags
 * @width: gives width
 * @precision: specifies precision
 * @size: specifies size
 *
 * Return: printed chars amount
 */
int print_int(va_list types, char buffer[], int flags, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	int is_negative = 0;
	long int n = va_arg(types, long int);
	unsigned long int num;

	n = convert_size_number(n, size);

	if (n == 0)
	{
		buffer[i--] = '0';
	}

